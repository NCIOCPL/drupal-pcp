<?php
/**
 * @file
 * pcp_features.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function pcp_features_user_default_roles() {
  $roles = array();

  // Exported role: administrator.
  $roles['administrator'] = array(
    'name' => 'administrator',
    'weight' => 2,
  );

  // Exported role: advanced content editor.
  $roles['advanced content editor'] = array(
    'name' => 'advanced content editor',
    'weight' => 5,
  );

  // Exported role: content approver.
  $roles['content approver'] = array(
    'name' => 'content approver',
    'weight' => 3,
  );

  // Exported role: content creator.
  $roles['content creator'] = array(
    'name' => 'content creator',
    'weight' => 2,
  );

  // Exported role: site manager.
  $roles['site manager'] = array(
    'name' => 'site manager',
    'weight' => 6,
  );

  // Exported role: site moderator.
  $roles['site moderator'] = array(
    'name' => 'site moderator',
    'weight' => 4,
  );

  return $roles;
}
