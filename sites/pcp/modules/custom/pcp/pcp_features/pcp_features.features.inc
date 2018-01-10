<?php
/**
 * @file
 * pcp_features.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function pcp_features_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "config_perms" && $api == "config_perms") {
    return array("version" => "1");
  }
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function pcp_features_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_fe_nodequeue_export_fields().
 */
function pcp_features_fe_nodequeue_export_fields() {
  $nodequeues = array();

  // Exported nodequeues: featured_cards
  $nodequeues['featured_cards'] = array(
    'name' => 'featured_cards',
    'title' => 'Featured Cards',
    'subqueue_title' => '',
    'size' => 2,
    'link' => '',
    'link_remove' => '',
    'owner' => 'nodequeue',
    'show_in_ui' => 1,
    'show_in_tab' => 1,
    'show_in_links' => 0,
    'reference' => 0,
    'reverse' => 0,
    'insert_at_front' => 1,
    'i18n' => 0,
    'subqueues' => 1,
    'types' => array(
      0 => 'feature_card',
    ),
    'roles' => array(),
    'count' => 0,
  );

  // Exported nodequeues: members
  $nodequeues['members'] = array(
    'name' => 'members',
    'title' => 'Members',
    'subqueue_title' => '',
    'size' => 3,
    'link' => '',
    'link_remove' => '',
    'owner' => 'nodequeue',
    'show_in_ui' => 1,
    'show_in_tab' => 1,
    'show_in_links' => 0,
    'reference' => 0,
    'reverse' => 0,
    'insert_at_front' => 0,
    'i18n' => 0,
    'subqueues' => 1,
    'types' => array(
      0 => 'member_staff',
    ),
    'roles' => array(),
    'count' => 0,
  );

  // Exported nodequeues: staff
  $nodequeues['staff'] = array(
    'name' => 'staff',
    'title' => 'Staff',
    'subqueue_title' => '',
    'size' => 4,
    'link' => '',
    'link_remove' => '',
    'owner' => 'nodequeue',
    'show_in_ui' => 1,
    'show_in_tab' => 1,
    'show_in_links' => 0,
    'reference' => 0,
    'reverse' => 0,
    'insert_at_front' => 0,
    'i18n' => 0,
    'subqueues' => 1,
    'types' => array(
      0 => 'member_staff',
    ),
    'roles' => array(),
    'count' => 0,
  );

  return $nodequeues;
}

/**
 * Implements hook_node_info().
 */
function pcp_features_node_info() {
  $items = array(
    'feature_card' => array(
      'name' => t('Feature Card'),
      'base' => 'node_content',
      'description' => t('A card to be displayed in the featured are on the home page below the carousel.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'meeting' => array(
      'name' => t('Meeting'),
      'base' => 'node_content',
      'description' => t('A specific meeting belonging to a chosen series.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'member_staff' => array(
      'name' => t('Member / Staff'),
      'base' => 'node_content',
      'description' => t('A PCP member or staff.'),
      'has_title' => '1',
      'title_label' => t('Name'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
