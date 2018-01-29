<?php
/**
 * @file
 * dennis_fb_instant_articles.features.features_overrides.inc
 */

/**
 * Implements hook_features_override_default_overrides().
 */
function dennis_fb_instant_articles_features_override_default_overrides() {
  // This code is only used for UI in features. Exported alters hooks do the magic.
  $overrides = array();

  // Exported overrides for: views_view
  $overrides["views_view.fb_instant_articles_views.display|default|display_options|filters|published_at"] = array(
    'id' => 'published_at',
    'table' => 'publication_date',
    'field' => 'published_at',
    'operator' => '>=',
    'value' => array(
      'value' => '-1 Hour',
      'type' => 'offset',
    ),
  );
  $overrides["views_view.fb_instant_articles_views.display|default|display_options|sorts|created"]["DELETED"] = TRUE;
  $overrides["views_view.fb_instant_articles_views.display|default|display_options|sorts|published_at"] = array(
    'id' => 'published_at',
    'table' => 'publication_date',
    'field' => 'published_at',
    'order' => 'DESC',
  );

 return $overrides;
}
