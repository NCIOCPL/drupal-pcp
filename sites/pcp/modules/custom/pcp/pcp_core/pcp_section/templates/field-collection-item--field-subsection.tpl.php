<?php
/**
 * @file
 * Default theme implementation for entities.
 *
 * Available variables:
 * - $content: An array of comment items. Use render($content) to print them all, or
 *   print a subset such as render($content['field_example']). Use
 *   hide($content['field_example']) to temporarily suppress the printing of a
 *   given element.
 * - $title: The (sanitized) entity label.
 * - $url: Direct url of the current entity if specified.
 * - $page: Flag for the full page state.
 * - $classes: String of classes that can be used to style contextually through
 *   CSS. It can be manipulated through the variable $classes_array from
 *   preprocess functions. By default the following classes are available, where
 *   the parts enclosed by {} are replaced by the appropriate values:
 *   - entity-{ENTITY_TYPE}
 *   - {ENTITY_TYPE}-{BUNDLE}
 *
 * Other variables:
 * - $classes_array: Array of html class attribute values. It is flattened
 *   into a string within the variable $classes.
 *
 * @see template_preprocess()
 * @see template_preprocess_entity()
 * @see template_process()
 * 
 * subsection-specific fields:
 *   field_title
 *   field_contextual_intro_text
 *   field_body
 * 
 */
?>
<div class="<?php print $classes; ?> clearfix subsection small-12"<?php print $attributes; ?>>
	<div class='row intro'>
		<div class="small-12 column">
			<h3>
				<?php print render($content['field_title']); ?>
			</h3>

			<div class="content"<?php print $content_attributes; ?>>
				<?php
				print render($content['field_contextual_intro_text']);
				print "<a data-body-id='$id' class='view-more'>See More</a>";
				?>
			</div>
		</div>
	</div>
	<div class="body hidden" data-body-id='<?php print $id; ?>'>
		<div class="row">
			<div class="small-12 column">
				<?php
				print render($content['field_body']);
				
				$item_id = $elements['#entity']->item_id;
				$last_item = end($elements['#entity']->hostEntity()->field_subsection['und']);

				if ($item_id === $last_item['value']) {
					$staff = views_embed_view('pcp_staff', 'block');
					print $staff;
				}
				?>
			</div>
		</div>
	</div>
</div>
