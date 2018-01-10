<?php
/**
 * @file
 * pcp_features.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function pcp_features_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'pcp_home';
  $page->task = 'page';
  $page->admin_title = 'PCP Home';
  $page->admin_description = 'The PCP homepage, used to display the carousel and sections blocks.';
  $page->path = 'home';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_pcp_home__panel_context_df6e7c93-f7cd-4ee9-989f-b13c167b9231';
  $handler->task = 'page';
  $handler->subtask = 'pcp_home';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'PCP Home Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'pcp_homepage';
  $display->layout_settings = array(
    'items' => array(
      'canvas' => array(
        'type' => 'row',
        'contains' => 'column',
        'children' => array(
          0 => 'main',
        ),
        'parent' => NULL,
        'class' => '',
        'column_class' => 'columns',
        'row_class' => 'row',
        'region_class' => '',
        'no_scale' => TRUE,
        'fixed_width' => '',
        'column_separation' => '0.5em',
        'region_separation' => '0.5em',
        'row_separation' => '0.5em',
        'hide_empty' => 0,
      ),
      'main' => array(
        'type' => 'column',
        'width' => 100,
        'width_type' => '%',
        'children' => array(
          0 => 1,
          1 => 'main-row',
        ),
        'parent' => 'canvas',
      ),
      'main-row' => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'center',
        ),
        'parent' => 'main',
      ),
      'center' => array(
        'type' => 'region',
        'title' => 'Center',
        'width' => 100,
        'width_type' => '%',
        'parent' => 'main-row',
      ),
      1 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'feature_cards',
        ),
        'parent' => 'main',
        'class' => 'row',
        'hide_empty' => 0,
      ),
      'feature_cards' => array(
        'type' => 'region',
        'title' => 'Feature Cards',
        'width' => 100,
        'width_type' => '%',
        'parent' => '1',
        'class' => 'row',
        'hide_empty' => 0,
      ),
    ),
  );
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'feature_cards' => NULL,
      'middle' => NULL,
      'carousel' => NULL,
      'featured' => NULL,
      'sections' => NULL,
    ),
    'feature_cards' => array(
      'style' => 'naked',
    ),
    'center' => array(
      'style' => 'naked',
    ),
    'middle' => array(
      'style' => 'naked',
    ),
    'style' => 'naked',
    'sections' => array(
      'style' => '-1',
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'f2fcd415-83e2-4e56-a8af-96704b4dbc3a';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-171f911e-a410-44cf-8ed9-d67b49e1315d';
    $pane->panel = 'carousel';
    $pane->type = 'block';
    $pane->subtype = 'views-pcp_carousel-block';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '171f911e-a410-44cf-8ed9-d67b49e1315d';
    $display->content['new-171f911e-a410-44cf-8ed9-d67b49e1315d'] = $pane;
    $display->panels['carousel'][0] = 'new-171f911e-a410-44cf-8ed9-d67b49e1315d';
    $pane = new stdClass();
    $pane->pid = 'new-9089153a-0c41-4171-b8c1-99593e002562';
    $pane->panel = 'featured';
    $pane->type = 'block';
    $pane->subtype = 'views-featured_cards-block';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'medium-8 columns',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '9089153a-0c41-4171-b8c1-99593e002562';
    $display->content['new-9089153a-0c41-4171-b8c1-99593e002562'] = $pane;
    $display->panels['featured'][0] = 'new-9089153a-0c41-4171-b8c1-99593e002562';
    $pane = new stdClass();
    $pane->pid = 'new-159386e8-0b74-417d-af28-5fa286e25b23';
    $pane->panel = 'featured';
    $pane->type = 'block';
    $pane->subtype = 'pcp_social_media-twitter_timeline_widget';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
      'style' => 'default',
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'medium-4 columns',
    );
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '159386e8-0b74-417d-af28-5fa286e25b23';
    $display->content['new-159386e8-0b74-417d-af28-5fa286e25b23'] = $pane;
    $display->panels['featured'][1] = 'new-159386e8-0b74-417d-af28-5fa286e25b23';
    $pane = new stdClass();
    $pane->pid = 'new-6e8e956b-6b6f-4df8-8b9f-542085607e13';
    $pane->panel = 'sections';
    $pane->type = 'block';
    $pane->subtype = 'views-pcp_sections-block';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '6e8e956b-6b6f-4df8-8b9f-542085607e13';
    $display->content['new-6e8e956b-6b6f-4df8-8b9f-542085607e13'] = $pane;
    $display->panels['sections'][0] = 'new-6e8e956b-6b6f-4df8-8b9f-542085607e13';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['pcp_home'] = $page;

  return $pages;

}
