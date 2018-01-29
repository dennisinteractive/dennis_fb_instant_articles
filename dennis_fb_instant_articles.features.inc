<?php
/**
 * @file
 * dennis_fb_instant_articles.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function dennis_fb_instant_articles_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function dennis_fb_instant_articles_views_api() {
  return array("api" => "3.0");
}

/**
 * Implements hook_views_default_views_alter().
 */
function dennis_fb_instant_articles_views_default_views_alter(&$data) {
  if (isset($data['fb_instant_articles_views'])) {
    $data['fb_instant_articles_views']->display['default']->display_options['filters']['published_at'] = array(
      'id' => 'published_at',
      'table' => 'publication_date',
      'field' => 'published_at',
      'operator' => '>=',
      'value' => array(
        'value' => '-1 Hour',
        'type' => 'offset',
      ),
    ); /* WAS: '' */
    $data['fb_instant_articles_views']->display['default']->display_options['sorts']['published_at'] = array(
      'id' => 'published_at',
      'table' => 'publication_date',
      'field' => 'published_at',
      'order' => 'DESC',
    ); /* WAS: '' */
    unset($data['fb_instant_articles_views']->display['default']->display_options['sorts']['created']);
  }
}
