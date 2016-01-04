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
<?php
$desktopHeight = $field_desktop_img[0]['height'];
$desktopWidth = $field_desktop_img[0]['width'];
$desktopRatio = ($desktopHeight / $desktopWidth) * 100;

$mobileHeight = $field_small_img[0]['height'];
$mobileWidth = $field_small_img[0]['width'];
$mobileRatio = ($mobileHeight / $mobileWidth) * 100;
?>

<svg class='imageset-fadeout' width='100%' height="5%" viewBox="0 0 100 5" preserveAspectRatio="xMidYMin slice">
<defs>
<linearGradient id="fadeout" x1="0%" y1="0%" x2="0%" y2="50%">
<stop offset="0%" style="stop-color:rgb(247,247,247);stop-opacity:0" />
<stop offset="100%" style="stop-color:rgb(247,247,247);stop-opacity:1" />
</linearGradient>
</defs>
<rect x='0' y='0' width='100' height='6' fill="url(#fadeout)"/>
</svg>
<div class="row imageset-buttons">
	<div class="small-6 columns">
		<div class="button  more">View More</div>
	</div>
	<div class="small-6 columns">
		<div class="button less disabled">View Less</div>
	</div>
</div>
<div class="imageset">
	 <div class="medium-up">
		 <img longdesc="<?php print $field_longdesc[0]['safe_value']; ?>"
			  alt='<?php print $field_alt_text[0]['safe_value'] ?>'
			  src="<?php print file_create_url($field_desktop_img[0]['uri']); ?>" 
			  width="100%" height="auto">
	</div>
	<div class="small-only">
		<img longdesc="<?php print $field_longdesc[0]['safe_value']; ?>"
			  alt='<?php print $field_alt_text[0]['safe_value'] ?>'
			  src="<?php print file_create_url($field_small_img[0]['uri']); ?>" 
			  width="100%" height="auto">
	</div>
</div>