<?php
/**
 * @file
 * Template for the PCP homepage layout.
 *
 * This panel is provided to allow full-width areas on the home page for
 * parallax and carousel areas, along with a feature card area wrapped in
 * a row class.
 *
 * Variables:
 * - $id: An optional CSS id to use for the layout.
 * - $content: An array of content, each item in the array is keyed to one
 *   panel of the layout. This layout supports the following sections:
 *   - $content['carousel']: Full-width carousel area.
 *   - $content['featured']: Feature card and Twitter area, row-bounded.
 *   - $content['sections']: Full-width area for sections.
 */
?>
<?php !empty($css_id) ? print '<div id="' . $css_id . '">' : ''; ?>
<div class="small-12 carousel section"><?php print $content['carousel']; ?></div>

<div class="section featured">
	<div class="row collapse" data-match-height>
		<?php print $content['featured']; ?>
	</div>
</div>

<div class="small-12"><?php print $content['sections']; ?></div>

<?php !empty($css_id) ? print '</div>' : ''; ?>
