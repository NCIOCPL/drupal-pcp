<?php
/**
 * @file
 * pcp_features.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function pcp_features_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'featured_cards';
  $view->description = 'Display a list of all nodes in queue \'Featured Cards\'';
  $view->tag = 'nodequeue';
  $view->base_table = 'node';
  $view->human_name = 'Featured Cards';
  $view->core = 0;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['title'] = 'Featured Cards';
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'medium-6 columns';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  /* Relationship: Nodequeue: Queue */
  $handler->display->display_options['relationships']['nodequeue_rel']['id'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['nodequeue_rel']['field'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['required'] = TRUE;
  $handler->display->display_options['relationships']['nodequeue_rel']['limit'] = TRUE;
  $handler->display->display_options['relationships']['nodequeue_rel']['names'] = array(
    'featured_cards' => 'featured_cards',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = '[field_internal_link]';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Link */
  $handler->display->display_options['fields']['field_internal_link']['id'] = 'field_internal_link';
  $handler->display->display_options['fields']['field_internal_link']['table'] = 'field_data_field_internal_link';
  $handler->display->display_options['fields']['field_internal_link']['field'] = 'field_internal_link';
  $handler->display->display_options['fields']['field_internal_link']['label'] = '';
  $handler->display->display_options['fields']['field_internal_link']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_internal_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_internal_link']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_internal_link']['type'] = 'link_plain';
  /* Field: Content: Card Image */
  $handler->display->display_options['fields']['field_card_image']['id'] = 'field_card_image';
  $handler->display->display_options['fields']['field_card_image']['table'] = 'field_data_field_card_image';
  $handler->display->display_options['fields']['field_card_image']['field'] = 'field_card_image';
  $handler->display->display_options['fields']['field_card_image']['label'] = '';
  $handler->display->display_options['fields']['field_card_image']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_card_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_card_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_card_image']['settings'] = array(
    'image_style' => 'large',
    'image_link' => '',
  );
  /* Field: Content: Description */
  $handler->display->display_options['fields']['field_description']['id'] = 'field_description';
  $handler->display->display_options['fields']['field_description']['table'] = 'field_data_field_description';
  $handler->display->display_options['fields']['field_description']['field'] = 'field_description';
  $handler->display->display_options['fields']['field_description']['label'] = '';
  $handler->display->display_options['fields']['field_description']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_description']['element_label_colon'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="featured-card equalheight"><a href="[field_internal_link]">
[field_card_image]
<div class="card-title">[title]</div>
<div class="card-description">[field_description]</div></a></div>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Sort criterion: Nodequeue: Position */
  $handler->display->display_options['sorts']['position']['id'] = 'position';
  $handler->display->display_options['sorts']['position']['table'] = 'nodequeue_nodes';
  $handler->display->display_options['sorts']['position']['field'] = 'position';
  $handler->display->display_options['sorts']['position']['relationship'] = 'nodequeue_rel';
  /* Filter criterion: Content: Published or admin */
  $handler->display->display_options['filters']['status_extra']['id'] = 'status_extra';
  $handler->display->display_options['filters']['status_extra']['table'] = 'node';
  $handler->display->display_options['filters']['status_extra']['field'] = 'status_extra';
  $handler->display->display_options['filters']['status_extra']['group'] = 0;
  $handler->display->display_options['filters']['status_extra']['expose']['operator'] = FALSE;

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['block_description'] = 'Featured Cards';
  $export['featured_cards'] = $view;

  $view = new view();
  $view->name = 'pcp_carousel';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'PCP Carousel';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'carousel-slide';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  /* Relationship: File Usage: File */
  $handler->display->display_options['relationships']['node_to_file']['id'] = 'node_to_file';
  $handler->display->display_options['relationships']['node_to_file']['table'] = 'file_usage';
  $handler->display->display_options['relationships']['node_to_file']['field'] = 'node_to_file';
  /* Relationship: Content: Carousel Image (field_carousel_image:fid) */
  $handler->display->display_options['relationships']['field_carousel_image_fid']['id'] = 'field_carousel_image_fid';
  $handler->display->display_options['relationships']['field_carousel_image_fid']['table'] = 'field_data_field_carousel_image';
  $handler->display->display_options['relationships']['field_carousel_image_fid']['field'] = 'field_carousel_image_fid';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'span';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['title']['element_wrapper_class'] = 'carousel-title';
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Carousel Description */
  $handler->display->display_options['fields']['field_carousel_description']['id'] = 'field_carousel_description';
  $handler->display->display_options['fields']['field_carousel_description']['table'] = 'field_data_field_carousel_description';
  $handler->display->display_options['fields']['field_carousel_description']['field'] = 'field_carousel_description';
  $handler->display->display_options['fields']['field_carousel_description']['label'] = '';
  $handler->display->display_options['fields']['field_carousel_description']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_carousel_description']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_carousel_description']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_carousel_description']['element_wrapper_class'] = 'carousel-description';
  $handler->display->display_options['fields']['field_carousel_description']['element_default_classes'] = FALSE;
  /* Field: File: Path */
  $handler->display->display_options['fields']['uri']['id'] = 'uri';
  $handler->display->display_options['fields']['uri']['table'] = 'file_managed';
  $handler->display->display_options['fields']['uri']['field'] = 'uri';
  $handler->display->display_options['fields']['uri']['relationship'] = 'field_carousel_image_fid';
  $handler->display->display_options['fields']['uri']['label'] = '';
  $handler->display->display_options['fields']['uri']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uri']['file_download_path'] = TRUE;
  /* Sort criterion: Content: Order (field_order) */
  $handler->display->display_options['sorts']['field_order_value']['id'] = 'field_order_value';
  $handler->display->display_options['sorts']['field_order_value']['table'] = 'field_data_field_order';
  $handler->display->display_options['sorts']['field_order_value']['field'] = 'field_order_value';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'pcp_section' => 'pcp_section',
  );
  /* Filter criterion: Content: Order (field_order) */
  $handler->display->display_options['filters']['field_order_value']['id'] = 'field_order_value';
  $handler->display->display_options['filters']['field_order_value']['table'] = 'field_data_field_order';
  $handler->display->display_options['filters']['field_order_value']['field'] = 'field_order_value';
  $handler->display->display_options['filters']['field_order_value']['operator'] = '>';
  $handler->display->display_options['filters']['field_order_value']['value']['value'] = '0';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['block_description'] = 'Carousel (Ordered)';
  $export['pcp_carousel'] = $view;

  $view = new view();
  $view->name = 'pcp_meeting_left_nav';
  $view->description = 'The navigation and sections of a PCP Metting page.';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'PCP Meeting Page Elements';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'PCP Meeting Left Nav';
  $handler->display->display_options['css_class'] = 'section-nav equalheight';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'nav-item';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  /* Relationship: Content: Sections (field_sections) */
  $handler->display->display_options['relationships']['field_sections_value']['id'] = 'field_sections_value';
  $handler->display->display_options['relationships']['field_sections_value']['table'] = 'field_data_field_sections';
  $handler->display->display_options['relationships']['field_sections_value']['field'] = 'field_sections_value';
  $handler->display->display_options['relationships']['field_sections_value']['required'] = TRUE;
  $handler->display->display_options['relationships']['field_sections_value']['delta'] = '-1';
  /* Field: Content: Sections (field_sections:delta) */
  $handler->display->display_options['fields']['delta']['id'] = 'delta';
  $handler->display->display_options['fields']['delta']['table'] = 'field_data_field_sections';
  $handler->display->display_options['fields']['delta']['field'] = 'delta';
  $handler->display->display_options['fields']['delta']['label'] = '';
  $handler->display->display_options['fields']['delta']['exclude'] = TRUE;
  $handler->display->display_options['fields']['delta']['element_label_colon'] = FALSE;
  /* Field: Active state */
  $handler->display->display_options['fields']['counter']['id'] = 'counter';
  $handler->display->display_options['fields']['counter']['table'] = 'views';
  $handler->display->display_options['fields']['counter']['field'] = 'counter';
  $handler->display->display_options['fields']['counter']['ui_name'] = 'Active state';
  $handler->display->display_options['fields']['counter']['label'] = '';
  $handler->display->display_options['fields']['counter']['exclude'] = TRUE;
  $handler->display->display_options['fields']['counter']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['counter']['alter']['text'] = ' ';
  $handler->display->display_options['fields']['counter']['element_type'] = '0';
  $handler->display->display_options['fields']['counter']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['counter']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['counter']['empty'] = 'active';
  $handler->display->display_options['fields']['counter']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['counter']['counter_start'] = '0';
  $handler->display->display_options['fields']['counter']['reverse'] = 0;
  /* Field: Field: Title */
  $handler->display->display_options['fields']['field_title']['id'] = 'field_title';
  $handler->display->display_options['fields']['field_title']['table'] = 'field_data_field_title';
  $handler->display->display_options['fields']['field_title']['field'] = 'field_title';
  $handler->display->display_options['fields']['field_title']['relationship'] = 'field_sections_value';
  $handler->display->display_options['fields']['field_title']['label'] = '';
  $handler->display->display_options['fields']['field_title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_title']['alter']['text'] = '<a class=\'[counter]\' data-section-id=\'[delta]\'>[field_title]</a>';
  $handler->display->display_options['fields']['field_title']['element_type'] = '0';
  $handler->display->display_options['fields']['field_title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_title']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_title']['type'] = 'text_plain';
  /* Sort criterion: Content: Sections (field_sections:delta) */
  $handler->display->display_options['sorts']['delta']['id'] = 'delta';
  $handler->display->display_options['sorts']['delta']['table'] = 'field_data_field_sections';
  $handler->display->display_options['sorts']['delta']['field'] = 'delta';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'meeting' => 'meeting',
  );

  /* Display: Nav */
  $handler = $view->new_display('block', 'Nav', 'nav');

  /* Display: Sections */
  $handler = $view->new_display('block', 'Sections', 'sections');
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'meeting-sections';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Sections (field_sections:delta) */
  $handler->display->display_options['fields']['delta']['id'] = 'delta';
  $handler->display->display_options['fields']['delta']['table'] = 'field_data_field_sections';
  $handler->display->display_options['fields']['delta']['field'] = 'delta';
  $handler->display->display_options['fields']['delta']['label'] = '';
  $handler->display->display_options['fields']['delta']['exclude'] = TRUE;
  $handler->display->display_options['fields']['delta']['element_label_colon'] = FALSE;
  /* Field: Active state */
  $handler->display->display_options['fields']['counter']['id'] = 'counter';
  $handler->display->display_options['fields']['counter']['table'] = 'views';
  $handler->display->display_options['fields']['counter']['field'] = 'counter';
  $handler->display->display_options['fields']['counter']['ui_name'] = 'Active state';
  $handler->display->display_options['fields']['counter']['label'] = '';
  $handler->display->display_options['fields']['counter']['exclude'] = TRUE;
  $handler->display->display_options['fields']['counter']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['counter']['alter']['text'] = ' ';
  $handler->display->display_options['fields']['counter']['element_type'] = '0';
  $handler->display->display_options['fields']['counter']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['counter']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['counter']['empty'] = 'active';
  $handler->display->display_options['fields']['counter']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['counter']['counter_start'] = '0';
  $handler->display->display_options['fields']['counter']['reverse'] = 0;
  /* Field: Collapsed state */
  $handler->display->display_options['fields']['counter_2']['id'] = 'counter_2';
  $handler->display->display_options['fields']['counter_2']['table'] = 'views';
  $handler->display->display_options['fields']['counter_2']['field'] = 'counter';
  $handler->display->display_options['fields']['counter_2']['ui_name'] = 'Collapsed state';
  $handler->display->display_options['fields']['counter_2']['label'] = '';
  $handler->display->display_options['fields']['counter_2']['exclude'] = TRUE;
  $handler->display->display_options['fields']['counter_2']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['counter_2']['alter']['text'] = 'collapsed';
  $handler->display->display_options['fields']['counter_2']['element_type'] = '0';
  $handler->display->display_options['fields']['counter_2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['counter_2']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['counter_2']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['counter_2']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['counter_2']['counter_start'] = '0';
  $handler->display->display_options['fields']['counter_2']['reverse'] = 0;
  /* Field: Field: Title */
  $handler->display->display_options['fields']['field_title']['id'] = 'field_title';
  $handler->display->display_options['fields']['field_title']['table'] = 'field_data_field_title';
  $handler->display->display_options['fields']['field_title']['field'] = 'field_title';
  $handler->display->display_options['fields']['field_title']['relationship'] = 'field_sections_value';
  $handler->display->display_options['fields']['field_title']['label'] = '';
  $handler->display->display_options['fields']['field_title']['alter']['text'] = '<a data-section-id=\'[field_sections]\'>[field_title]</a>';
  $handler->display->display_options['fields']['field_title']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_title']['element_class'] = 'section-title small-only [counter]';
  $handler->display->display_options['fields']['field_title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_title']['element_default_classes'] = FALSE;
  /* Field: Field collection item: Section Body */
  $handler->display->display_options['fields']['field_body']['id'] = 'field_body';
  $handler->display->display_options['fields']['field_body']['table'] = 'field_data_field_body';
  $handler->display->display_options['fields']['field_body']['field'] = 'field_body';
  $handler->display->display_options['fields']['field_body']['relationship'] = 'field_sections_value';
  $handler->display->display_options['fields']['field_body']['label'] = '';
  $handler->display->display_options['fields']['field_body']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_body']['alter']['text'] = '<div class=\'section-body [counter_2]\' data-section-id=\'[delta]\'>[field_body]</div>';
  $handler->display->display_options['fields']['field_body']['element_type'] = '0';
  $handler->display->display_options['fields']['field_body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_body']['element_default_classes'] = FALSE;
  $export['pcp_meeting_left_nav'] = $view;

  $view = new view();
  $view->name = 'pcp_members';
  $view->description = 'Display a list of all nodes in queue \'Members\'';
  $view->tag = 'nodequeue';
  $view->base_table = 'node';
  $view->human_name = 'PCP Members';
  $view->core = 0;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['title'] = 'PCP Members';
  $handler->display->display_options['css_class'] = 'small-12 collapsed member-bios';
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['row_class'] = 'medium-4 columns member';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['style_options']['class'] = 'row';
  $handler->display->display_options['style_options']['wrapper_class'] = '';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  /* Relationship: Nodequeue: Queue */
  $handler->display->display_options['relationships']['nodequeue_rel']['id'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['nodequeue_rel']['field'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['required'] = TRUE;
  $handler->display->display_options['relationships']['nodequeue_rel']['limit'] = TRUE;
  $handler->display->display_options['relationships']['nodequeue_rel']['names'] = array(
    'members' => 'members',
  );
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid']['element_default_classes'] = FALSE;
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_member_staff_image']['id'] = 'field_member_staff_image';
  $handler->display->display_options['fields']['field_member_staff_image']['table'] = 'field_data_field_member_staff_image';
  $handler->display->display_options['fields']['field_member_staff_image']['field'] = 'field_member_staff_image';
  $handler->display->display_options['fields']['field_member_staff_image']['label'] = '';
  $handler->display->display_options['fields']['field_member_staff_image']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_member_staff_image']['element_class'] = 'member-image';
  $handler->display->display_options['fields']['field_member_staff_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_member_staff_image']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_member_staff_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_member_staff_image']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Field: Content: Name */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['ui_name'] = 'Content: Name';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_type'] = 'div';
  $handler->display->display_options['fields']['title']['element_class'] = 'member-name';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Field: Title */
  $handler->display->display_options['fields']['field_title']['id'] = 'field_title';
  $handler->display->display_options['fields']['field_title']['table'] = 'field_data_field_title';
  $handler->display->display_options['fields']['field_title']['field'] = 'field_title';
  $handler->display->display_options['fields']['field_title']['label'] = '';
  $handler->display->display_options['fields']['field_title']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_title']['element_class'] = 'member-title';
  $handler->display->display_options['fields']['field_title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_title']['element_default_classes'] = FALSE;
  /* Field: Expanded state */
  $handler->display->display_options['fields']['counter']['id'] = 'counter';
  $handler->display->display_options['fields']['counter']['table'] = 'views';
  $handler->display->display_options['fields']['counter']['field'] = 'counter';
  $handler->display->display_options['fields']['counter']['ui_name'] = 'Expanded state';
  $handler->display->display_options['fields']['counter']['label'] = '';
  $handler->display->display_options['fields']['counter']['exclude'] = TRUE;
  $handler->display->display_options['fields']['counter']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['counter']['alter']['text'] = ' ';
  $handler->display->display_options['fields']['counter']['element_type'] = '0';
  $handler->display->display_options['fields']['counter']['element_label_type'] = '0';
  $handler->display->display_options['fields']['counter']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['counter']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['counter']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['counter']['empty'] = 'expanded';
  $handler->display->display_options['fields']['counter']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['counter']['counter_start'] = '0';
  $handler->display->display_options['fields']['counter']['reverse'] = 0;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<a class=\'view-bio [counter]\' data-member-bio=[nid]>View Bio</a>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing']['element_default_classes'] = FALSE;
  /* Sort criterion: Nodequeue: Position */
  $handler->display->display_options['sorts']['position']['id'] = 'position';
  $handler->display->display_options['sorts']['position']['table'] = 'nodequeue_nodes';
  $handler->display->display_options['sorts']['position']['field'] = 'position';
  $handler->display->display_options['sorts']['position']['relationship'] = 'nodequeue_rel';
  /* Filter criterion: Content: Published or admin */
  $handler->display->display_options['filters']['status_extra']['id'] = 'status_extra';
  $handler->display->display_options['filters']['status_extra']['table'] = 'node';
  $handler->display->display_options['filters']['status_extra']['field'] = 'status_extra';
  $handler->display->display_options['filters']['status_extra']['group'] = 0;
  $handler->display->display_options['filters']['status_extra']['expose']['operator'] = FALSE;

  /* Display: Nav */
  $handler = $view->new_display('block', 'Nav', 'nav');
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'medium-up member-nav';
  $handler->display->display_options['block_description'] = 'PCP Members Nav';

  /* Display: Bios */
  $handler = $view->new_display('block', 'Bios', 'bios');
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'small-12 collapsed member-bios';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['row_class'] = 'member';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['style_options']['wrapper_class'] = '';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_member_staff_image']['id'] = 'field_member_staff_image';
  $handler->display->display_options['fields']['field_member_staff_image']['table'] = 'field_data_field_member_staff_image';
  $handler->display->display_options['fields']['field_member_staff_image']['field'] = 'field_member_staff_image';
  $handler->display->display_options['fields']['field_member_staff_image']['label'] = '';
  $handler->display->display_options['fields']['field_member_staff_image']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_member_staff_image']['element_class'] = 'small-only member-image';
  $handler->display->display_options['fields']['field_member_staff_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_member_staff_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_member_staff_image']['settings'] = array(
    'image_style' => 'large',
    'image_link' => '',
  );
  /* Field: Content: Name */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['ui_name'] = 'Content: Name';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_type'] = 'div';
  $handler->display->display_options['fields']['title']['element_class'] = 'small-only member-name';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Field: Title */
  $handler->display->display_options['fields']['field_title']['id'] = 'field_title';
  $handler->display->display_options['fields']['field_title']['table'] = 'field_data_field_title';
  $handler->display->display_options['fields']['field_title']['field'] = 'field_title';
  $handler->display->display_options['fields']['field_title']['label'] = '';
  $handler->display->display_options['fields']['field_title']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_title']['element_class'] = 'small-only member-title';
  $handler->display->display_options['fields']['field_title']['element_label_colon'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<a class=\'view-bio\'>View Bio</a>';
  $handler->display->display_options['fields']['nothing']['element_class'] = 'small-only';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Field: Hidden state */
  $handler->display->display_options['fields']['counter']['id'] = 'counter';
  $handler->display->display_options['fields']['counter']['table'] = 'views';
  $handler->display->display_options['fields']['counter']['field'] = 'counter';
  $handler->display->display_options['fields']['counter']['ui_name'] = 'Hidden state';
  $handler->display->display_options['fields']['counter']['label'] = '';
  $handler->display->display_options['fields']['counter']['exclude'] = TRUE;
  $handler->display->display_options['fields']['counter']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['counter']['alter']['text'] = 'small-only';
  $handler->display->display_options['fields']['counter']['element_type'] = '0';
  $handler->display->display_options['fields']['counter']['element_label_type'] = '0';
  $handler->display->display_options['fields']['counter']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['counter']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['counter']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['counter']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['counter']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['counter']['counter_start'] = '0';
  $handler->display->display_options['fields']['counter']['reverse'] = 0;
  /* Field: Content: Bio */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['text'] = '<div data-member-bio="[nid]" class="body [counter] medium-up"><div class="row"><div class=\'small-12 column\'>[body]</div></div></div>';
  $handler->display->display_options['fields']['body']['element_type'] = '0';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['body']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '600',
  );
  $handler->display->display_options['block_description'] = 'PCP Members Bios';
  $export['pcp_members'] = $view;

  $view = new view();
  $view->name = 'pcp_sections';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'PCP Sections';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entity';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Sort criterion: Content: Order (field_order) */
  $handler->display->display_options['sorts']['field_order_value']['id'] = 'field_order_value';
  $handler->display->display_options['sorts']['field_order_value']['table'] = 'field_data_field_order';
  $handler->display->display_options['sorts']['field_order_value']['field'] = 'field_order_value';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'pcp_section' => 'pcp_section',
  );
  /* Filter criterion: Content: Order (field_order) */
  $handler->display->display_options['filters']['field_order_value']['id'] = 'field_order_value';
  $handler->display->display_options['filters']['field_order_value']['table'] = 'field_data_field_order';
  $handler->display->display_options['filters']['field_order_value']['field'] = 'field_order_value';
  $handler->display->display_options['filters']['field_order_value']['operator'] = '>';
  $handler->display->display_options['filters']['field_order_value']['value']['value'] = '0';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['block_description'] = 'Sections (Ordered)';

  /* Display: Main Menu */
  $handler = $view->new_display('block', 'Main Menu', 'main_menu');
  $handler->display->display_options['display_description'] = 'Main Menu';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $export['pcp_sections'] = $view;

  $view = new view();
  $view->name = 'pcp_series';
  $view->description = 'A view with blocks for both Current Series and Past Reports';
  $view->tag = 'default';
  $view->base_table = 'taxonomy_term_data';
  $view->human_name = 'PCP Series';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Past Reports';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'row series';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['element_type'] = 'h3';
  $handler->display->display_options['fields']['name']['element_class'] = 'series-year';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['element_default_classes'] = FALSE;
  /* Field: Taxonomy term: Term description */
  $handler->display->display_options['fields']['description']['id'] = 'description';
  $handler->display->display_options['fields']['description']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['description']['field'] = 'description';
  $handler->display->display_options['fields']['description']['label'] = '';
  $handler->display->display_options['fields']['description']['element_class'] = 'field-description';
  $handler->display->display_options['fields']['description']['element_label_colon'] = FALSE;
  /* Field: Field: Series Links */
  $handler->display->display_options['fields']['field_series_links']['id'] = 'field_series_links';
  $handler->display->display_options['fields']['field_series_links']['table'] = 'field_data_field_series_links';
  $handler->display->display_options['fields']['field_series_links']['field'] = 'field_series_links';
  $handler->display->display_options['fields']['field_series_links']['label'] = '';
  $handler->display->display_options['fields']['field_series_links']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_series_links']['settings'] = array(
    'edit' => '',
    'delete' => '',
    'add' => '',
    'description' => 0,
    'view_mode' => 'full',
  );
  $handler->display->display_options['fields']['field_series_links']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_series_links']['multi_type'] = 'ul';
  /* Sort criterion: Taxonomy term: Weight */
  $handler->display->display_options['sorts']['weight']['id'] = 'weight';
  $handler->display->display_options['sorts']['weight']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['sorts']['weight']['field'] = 'weight';
  /* Filter criterion: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'series' => 'series',
  );
  /* Filter criterion: Taxonomy term: Series Status (field_series_status) */
  $handler->display->display_options['filters']['field_series_status_value']['id'] = 'field_series_status_value';
  $handler->display->display_options['filters']['field_series_status_value']['table'] = 'field_data_field_series_status';
  $handler->display->display_options['filters']['field_series_status_value']['field'] = 'field_series_status_value';
  $handler->display->display_options['filters']['field_series_status_value']['value'] = array(
    1 => '1',
  );

  /* Display: Current Series Block */
  $handler = $view->new_display('block', 'Current Series Block', 'current_series');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Current Series';
  $handler->display->display_options['display_description'] = 'A block that displays only current series.';

  /* Display: Past Reports Block */
  $handler = $view->new_display('block', 'Past Reports Block', 'past_reports');
  $handler->display->display_options['display_description'] = 'A block that displays only past reports.';
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Footer: Global: Text area */
  $handler->display->display_options['footer']['area']['id'] = 'area';
  $handler->display->display_options['footer']['area']['table'] = 'views';
  $handler->display->display_options['footer']['area']['field'] = 'area';
  $handler->display->display_options['footer']['area']['label'] = 'DEAInfo link';
  $handler->display->display_options['footer']['area']['empty'] = TRUE;
  $handler->display->display_options['footer']['area']['content'] = '<div class=\'row\'><div class=\'small-12 column\'><a class=\'view-more\' href=\'http://deainfo.nci.nih.gov/advisory/pcp/archive/index.htm\'>View More<a></div></div>';
  $handler->display->display_options['footer']['area']['format'] = 'filtered_html';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['element_type'] = 'h3';
  $handler->display->display_options['fields']['name']['element_class'] = 'series-year';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['element_default_classes'] = FALSE;
  /* Field: Taxonomy term: Report URL */
  $handler->display->display_options['fields']['field_report_url']['id'] = 'field_report_url';
  $handler->display->display_options['fields']['field_report_url']['table'] = 'field_data_field_report_url';
  $handler->display->display_options['fields']['field_report_url']['field'] = 'field_report_url';
  $handler->display->display_options['fields']['field_report_url']['label'] = '';
  $handler->display->display_options['fields']['field_report_url']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_report_url']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_report_url']['element_type'] = '0';
  $handler->display->display_options['fields']['field_report_url']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_report_url']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_report_url']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_report_url']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_report_url']['settings'] = array(
    'trim_length' => '',
    'nofollow' => 0,
  );
  /* Field: Taxonomy term: Term description */
  $handler->display->display_options['fields']['description']['id'] = 'description';
  $handler->display->display_options['fields']['description']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['description']['field'] = 'description';
  $handler->display->display_options['fields']['description']['label'] = '';
  $handler->display->display_options['fields']['description']['element_class'] = 'field-description';
  $handler->display->display_options['fields']['description']['element_label_colon'] = FALSE;
  /* Field: Field: Series Links */
  $handler->display->display_options['fields']['field_series_links']['id'] = 'field_series_links';
  $handler->display->display_options['fields']['field_series_links']['table'] = 'field_data_field_series_links';
  $handler->display->display_options['fields']['field_series_links']['field'] = 'field_series_links';
  $handler->display->display_options['fields']['field_series_links']['label'] = '';
  $handler->display->display_options['fields']['field_series_links']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_series_links']['settings'] = array(
    'edit' => '',
    'delete' => '',
    'add' => '',
    'description' => 0,
    'view_mode' => 'full',
  );
  $handler->display->display_options['fields']['field_series_links']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_series_links']['multi_type'] = 'ul';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'series' => 'series',
  );
  /* Filter criterion: Taxonomy term: Series Status (field_series_status) */
  $handler->display->display_options['filters']['field_series_status_value']['id'] = 'field_series_status_value';
  $handler->display->display_options['filters']['field_series_status_value']['table'] = 'field_data_field_series_status';
  $handler->display->display_options['filters']['field_series_status_value']['field'] = 'field_series_status_value';
  $handler->display->display_options['filters']['field_series_status_value']['value'] = array(
    0 => '0',
  );
  $export['pcp_series'] = $view;

  $view = new view();
  $view->name = 'pcp_series_meetings';
  $view->description = 'Renders all meetings assigned to a certain series.';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'PCP Series Meetings';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'PCP Series Meetings';
  $handler->display->display_options['css_class'] = 'row display';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '4';
  $handler->display->display_options['pager']['options']['offset'] = '2';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'series-meeting';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Date */
  $handler->display->display_options['fields']['field_date']['id'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['table'] = 'field_data_field_date';
  $handler->display->display_options['fields']['field_date']['field'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['label'] = '';
  $handler->display->display_options['fields']['field_date']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_date']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['field_date']['alter']['link_class'] = 'field-date';
  $handler->display->display_options['fields']['field_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_date']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_date']['settings'] = array(
    'format_type' => 'medium',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  $handler->display->display_options['fields']['field_date']['field_api_classes'] = TRUE;
  /* Field: Content: Location */
  $handler->display->display_options['fields']['field_location']['id'] = 'field_location';
  $handler->display->display_options['fields']['field_location']['table'] = 'field_data_field_location';
  $handler->display->display_options['fields']['field_location']['field'] = 'field_location';
  $handler->display->display_options['fields']['field_location']['label'] = '';
  $handler->display->display_options['fields']['field_location']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_location']['element_label_colon'] = FALSE;
  /* Field: Content: Status */
  $handler->display->display_options['fields']['field_status']['id'] = 'field_status';
  $handler->display->display_options['fields']['field_status']['table'] = 'field_data_field_status';
  $handler->display->display_options['fields']['field_status']['field'] = 'field_status';
  $handler->display->display_options['fields']['field_status']['label'] = '';
  $handler->display->display_options['fields']['field_status']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_status']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_status']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_status']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Date / Location / Status */
  $handler->display->display_options['fields']['field_sections']['id'] = 'field_sections';
  $handler->display->display_options['fields']['field_sections']['table'] = 'field_data_field_sections';
  $handler->display->display_options['fields']['field_sections']['field'] = 'field_sections';
  $handler->display->display_options['fields']['field_sections']['ui_name'] = 'Date / Location / Status';
  $handler->display->display_options['fields']['field_sections']['label'] = '';
  $handler->display->display_options['fields']['field_sections']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_sections']['alter']['text'] = '<div class=\'field-date\'>[field_date]</div>
<div class=\'field-location\'>[field_location]</div>
<div class=\'field-status\'>[field_status]</div>';
  $handler->display->display_options['fields']['field_sections']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_sections']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['field_sections']['alter']['trim_whitespace'] = TRUE;
  $handler->display->display_options['fields']['field_sections']['alter']['link_class'] = 'date-location-wrapper';
  $handler->display->display_options['fields']['field_sections']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_sections']['empty'] = '<div class=\'date-location-wrapper\'>
<div class=\'field-date\'>[field_date]</div>
<div class=\'field-location\'>[field_location]</div>
<div class=\'field-status\'>[field_status]</div>
</div>';
  $handler->display->display_options['fields']['field_sections']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['field_sections']['settings'] = array(
    'edit' => '',
    'delete' => '',
    'add' => '',
    'description' => 0,
    'view_mode' => 'full',
  );
  $handler->display->display_options['fields']['field_sections']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_sections']['delta_offset'] = '0';
  /* Field: Field: Series Links */
  $handler->display->display_options['fields']['field_series_links']['id'] = 'field_series_links';
  $handler->display->display_options['fields']['field_series_links']['table'] = 'field_data_field_series_links';
  $handler->display->display_options['fields']['field_series_links']['field'] = 'field_series_links';
  $handler->display->display_options['fields']['field_series_links']['label'] = '';
  $handler->display->display_options['fields']['field_series_links']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_series_links']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_series_links']['type'] = 'field_collection_fields';
  $handler->display->display_options['fields']['field_series_links']['settings'] = array(
    'view_mode' => 'full',
  );
  $handler->display->display_options['fields']['field_series_links']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_series_links']['multi_type'] = 'ul';
  /* Sort criterion: Content: Date (field_date) */
  $handler->display->display_options['sorts']['field_date_value']['id'] = 'field_date_value';
  $handler->display->display_options['sorts']['field_date_value']['table'] = 'field_data_field_date';
  $handler->display->display_options['sorts']['field_date_value']['field'] = 'field_date_value';
  /* Sort criterion: Content: Date (field_date:value2) */
  $handler->display->display_options['sorts']['field_date_value2']['id'] = 'field_date_value2';
  $handler->display->display_options['sorts']['field_date_value2']['table'] = 'field_data_field_date';
  $handler->display->display_options['sorts']['field_date_value2']['field'] = 'field_date_value2';
  /* Contextual filter: Content: Has taxonomy term ID */
  $handler->display->display_options['arguments']['tid']['id'] = 'tid';
  $handler->display->display_options['arguments']['tid']['table'] = 'taxonomy_index';
  $handler->display->display_options['arguments']['tid']['field'] = 'tid';
  $handler->display->display_options['arguments']['tid']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['tid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['tid']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['tid']['validate_options']['vocabularies'] = array(
    'series' => 'series',
  );
  $handler->display->display_options['arguments']['tid']['validate']['fail'] = 'empty';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'meeting' => 'meeting',
  );

  /* Display: Series Meetings */
  $handler = $view->new_display('block', 'Series Meetings', 'series_meetings');
  $export['pcp_series_meetings'] = $view;

  $view = new view();
  $view->name = 'pcp_staff';
  $view->description = 'Display a list of all nodes in queue \'Staff\'';
  $view->tag = 'nodequeue';
  $view->base_table = 'node';
  $view->human_name = 'PCP Staff';
  $view->core = 0;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['title'] = 'Queue \'Staff\'';
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['row_class'] = 'medium-3 columns member';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['style_options']['class'] = 'row';
  $handler->display->display_options['style_options']['wrapper_class'] = '';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  /* Relationship: Nodequeue: Queue */
  $handler->display->display_options['relationships']['nodequeue_rel']['id'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['nodequeue_rel']['field'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['required'] = TRUE;
  $handler->display->display_options['relationships']['nodequeue_rel']['limit'] = TRUE;
  $handler->display->display_options['relationships']['nodequeue_rel']['names'] = array(
    'staff' => 'staff',
  );
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_member_staff_image']['id'] = 'field_member_staff_image';
  $handler->display->display_options['fields']['field_member_staff_image']['table'] = 'field_data_field_member_staff_image';
  $handler->display->display_options['fields']['field_member_staff_image']['field'] = 'field_member_staff_image';
  $handler->display->display_options['fields']['field_member_staff_image']['label'] = '';
  $handler->display->display_options['fields']['field_member_staff_image']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_member_staff_image']['element_class'] = 'member-image';
  $handler->display->display_options['fields']['field_member_staff_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_member_staff_image']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_member_staff_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_member_staff_image']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Field: Content: Name */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['ui_name'] = 'Content: Name';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_type'] = 'div';
  $handler->display->display_options['fields']['title']['element_class'] = 'member-name';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Field: Title */
  $handler->display->display_options['fields']['field_title']['id'] = 'field_title';
  $handler->display->display_options['fields']['field_title']['table'] = 'field_data_field_title';
  $handler->display->display_options['fields']['field_title']['field'] = 'field_title';
  $handler->display->display_options['fields']['field_title']['label'] = '';
  $handler->display->display_options['fields']['field_title']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_title']['element_class'] = 'member-title';
  $handler->display->display_options['fields']['field_title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_title']['element_default_classes'] = FALSE;
  /* Field: Content: Phone Number */
  $handler->display->display_options['fields']['field_phone_number']['id'] = 'field_phone_number';
  $handler->display->display_options['fields']['field_phone_number']['table'] = 'field_data_field_phone_number';
  $handler->display->display_options['fields']['field_phone_number']['field'] = 'field_phone_number';
  $handler->display->display_options['fields']['field_phone_number']['label'] = '';
  $handler->display->display_options['fields']['field_phone_number']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_phone_number']['element_class'] = 'member-number';
  $handler->display->display_options['fields']['field_phone_number']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_phone_number']['element_default_classes'] = FALSE;
  /* Field: Content: Email */
  $handler->display->display_options['fields']['field_email']['id'] = 'field_email';
  $handler->display->display_options['fields']['field_email']['table'] = 'field_data_field_email';
  $handler->display->display_options['fields']['field_email']['field'] = 'field_email';
  $handler->display->display_options['fields']['field_email']['label'] = '';
  $handler->display->display_options['fields']['field_email']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_email']['element_class'] = 'member-email';
  $handler->display->display_options['fields']['field_email']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_email']['element_default_classes'] = FALSE;
  /* Sort criterion: Nodequeue: Position */
  $handler->display->display_options['sorts']['position']['id'] = 'position';
  $handler->display->display_options['sorts']['position']['table'] = 'nodequeue_nodes';
  $handler->display->display_options['sorts']['position']['field'] = 'position';
  $handler->display->display_options['sorts']['position']['relationship'] = 'nodequeue_rel';
  /* Filter criterion: Content: Published or admin */
  $handler->display->display_options['filters']['status_extra']['id'] = 'status_extra';
  $handler->display->display_options['filters']['status_extra']['table'] = 'node';
  $handler->display->display_options['filters']['status_extra']['field'] = 'status_extra';
  $handler->display->display_options['filters']['status_extra']['group'] = 0;
  $handler->display->display_options['filters']['status_extra']['expose']['operator'] = FALSE;

  /* Display: PCP Staff */
  $handler = $view->new_display('block', 'PCP Staff', 'block');
  $handler->display->display_options['block_description'] = 'Queue \'Staff\'';
  $export['pcp_staff'] = $view;

  return $export;
}
