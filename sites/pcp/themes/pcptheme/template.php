<?php

/**
 * Implements template_preprocess_html().
 */
function pcptheme_preprocess_html(&$variables) {
	
}

/**
 * Implements template_preprocess_page.
 */
function pcptheme_preprocess_page(&$variables) {
	
}

/**
 * Implements template_preprocess_node.
 */
function pcptheme_preprocess_node(&$variables) {
	switch ($variables['type']) {
		case 'pcp_section':
			_pcptheme_preprocess_node__pcp_section($variables);
			break;
		case 'meeting':
			_pcptheme_preprocess_node__meeting($variables);
			break;
	}
}

/**
 * Implements template_preprocess_entity.
 */
function pcptheme_preprocess_entity(&$variables) {
	
}

/**
 * Implements template_preprocess_node.
 */
function _pcptheme_preprocess_node__pcp_section(&$variables) {

	if (isset($variables['field_section_type'][0]['value'])) {
		switch ($variables['field_section_type'][0]['value']) {
			case 'subsections':

				// get last subsection id and preserve for templates
				$last_subsection_item = end($variables['field_subsection']);
				if (!empty($last_subsection_item['value'])) {
					$variables['last_subsection'] = $last_subsection_item['value'];
				}
				break;
		}
	}

	//$staff = views_embed_view('pcp_staff', 'block');
	//print $staff;
}

function _pcptheme_preprocess_node__meeting(&$variables) {
	$series_items = $variables['field_series'];
	$series_status = $series_items[0]['taxonomy_term']->field_series_status['und'][0]['value'] ?
		'current-series' : 'past-reports';
	
	$variables['series_status'] = $series_status;
}

/**
 * Implements template_url_outbound_alter.
 */
function pcptheme_url_outbound_alter(&$path, &$options, $original_path) {
	if (preg_match('%node/\d+$%', $path)) {
		
		$node = menu_get_object("node", 1, $path);

		if (isset($node->type) && $node->type == "pcp_section") {
			module_load_include('inc', 'pathauto');
			$options['fragment'] = pathauto_cleanstring($node->title);
			$options['alias'] = true;
			$path = '<front>';
		}
	}
}

/**
 * Implements theme_breadrumb().
 *
 * Print breadcrumbs as a list, with separators.
 */
function pcptheme_breadcrumb($variables) {
	$breadcrumb = $variables['breadcrumb'];

	if (!empty($breadcrumb)) {
		// Provide a navigational heading to give context for breadcrumb links to
		// screen-reader users. Make the heading invisible with .element-invisible.
		$breadcrumbs = '<h2 class="element-invisible">' . t('You are here') . '</h2>';

		$breadcrumbs .= '<ul class="breadcrumbs">';

		foreach ($breadcrumb as $key => $value) {
			$breadcrumbs .= '<li>' . $value . '</li>';
		}

		$breadcrumbs .= '</ul>';

		return $breadcrumbs;
	}
}
