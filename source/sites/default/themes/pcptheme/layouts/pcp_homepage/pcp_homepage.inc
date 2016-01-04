<?php

/**
 * Implements hook_panels_layouts()
 */
function pcptheme_pcp_homepage_panels_layouts() {
  $items['pcp_homepage'] = array(
    'title' => t('PCP Homepage'),
    'category' => t('PCP'),
    'icon' => 'pcp_homepage.png',
    'theme' => 'pcp_homepage',
    //'admin css' => '../foundation_panels_admin.css',
    'regions' => array(
      'carousel' => t('Carousel'),
      'featured' => t('Featured'),
      'sections' => t('Sections'),
    ),
  );
  return $items;
}