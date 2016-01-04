<?php
/**
 * @file
 * Default theme implementation to display a node.
 *
 * Available variables:
 * - $title: the (sanitized) title of the node.
 * - $content: An array of node items. Use render($content) to print them all, or
 *   print a subset such as render($content['field_example']). Use
 *   hide($content['field_example']) to temporarily suppress the printing of a
 *   given element.
 * - $user_picture: The node author's picture from user-picture.tpl.php.
 * - $date: Formatted creation date. Preprocess functions can reformat it by
 *   calling format_date() with the desired parameters on the $created variable.
 * - $name: Themed username of node author output from theme_username().
 * - $node_url: Direct url of the current node.
 * - $terms: the themed list of taxonomy term links output from theme_links().
 * - $display_submitted: whether submission information should be displayed.
 * - $classes: String of classes that can be used to style contextually through
 *   CSS. It can be manipulated through the variable $classes_array from
 *   preprocess functions. The default values can be one or more of the following:
 *   - node: The current template type, i.e., "theming hook".
 *   - node-[type]: The current node type. For example, if the node is a
 *     "Blog entry" it would result in "node-blog". Note that the machine
 *     name will often be in a short form of the human readable label.
 *   - node-teaser: Nodes in teaser form.
 *   - node-preview: Nodes in preview mode.
 *   The following are controlled through the node publishing options.
 *   - node-promoted: Nodes promoted to the front page.
 *   - node-sticky: Nodes ordered above other non-sticky nodes in teaser listings.
 *   - node-unpublished: Unpublished nodes visible only to administrators.
 * - $title_prefix (array): An array containing additional output populated by
 *   modules, intended to be displayed in front of the main title tag that
 *   appears in the template.
 * - $title_suffix (array): An array containing additional output populated by
 *   modules, intended to be displayed after the main title tag that appears in
 *   the template.
 *
 * Other variables:
 * - $node: Full node object. Contains data that may not be safe.
 * - $type: Node type, i.e. story, page, blog, etc.
 * - $comment_count: Number of comments attached to the node.
 * - $uid: User ID of the node author.
 * - $created: Time the node was published formatted in Unix timestamp.
 * - $classes_array: Array of html class attribute values. It is flattened
 *   into a string within the variable $classes.
 * - $zebra: Outputs either "even" or "odd". Useful for zebra striping in
 *   teaser listings.
 * - $id: Position of the node. Increments each time it's output.
 *
 * Node status variables:
 * - $view_mode: View mode, e.g. 'full', 'teaser'...
 * - $teaser: Flag for the teaser state (shortcut for $view_mode == 'teaser').
 * - $page: Flag for the full page state.
 * - $promote: Flag for front page promotion state.
 * - $sticky: Flags for sticky post setting.
 * - $status: Flag for published status.
 * - $comment: State of comment settings for the node.
 * - $readmore: Flags true if the teaser content of the node cannot hold the
 *   main body content.
 * - $is_front: Flags true when presented in the front page.
 * - $logged_in: Flags true when the current user is a logged-in member.
 * - $is_admin: Flags true when the current user is an administrator.
 *
 * Field variables: for each field instance attached to the node a corresponding
 * variable is defined, e.g. $node->body becomes $body. When needing to access
 * a field's raw values, developers/themers are strongly encouraged to use these
 * variables. Otherwise they will have to explicitly specify the desired field
 * language, e.g. $node->body['en'], thus overriding any language negotiation
 * rule that was previously applied.
 *
 * @see template_preprocess()
 * @see template_preprocess_node()
 * @see template_process()
 */
?>
<?php
$sectionType = '';
if (isset($content['field_section_type']['#items'][0]['value'])) {
	$sectionType = drupal_clean_css_identifier($content['field_section_type']['#items'][0]['value']);
}
?>
<div class="parallax-container" 
	 data-image-src="<?php print file_create_url($field_parallax_image[0]['uri']) ?>" 
	 data-bleed="10" data-position="top" data-parallax="scroll"></div>
<article id="<?php
if (function_exists('pathauto_cleanstring')) {
	print pathauto_cleanstring($title);
}
?>">
	<div class="section <?php print $sectionType ?>">
		<div class="<?php print $classes; ?>"<?php print $attributes; ?>>
			<div class='row'>
				<div class="small-12 column">
					<h2><?php print $title; ?></h2>

					<?php
					// We hide the comments and links now so that we can render them later.
					hide($content['field_section_type']);
					hide($content['field_subsection']);
					hide($content['comments']);
					hide($content['links']);
					hide($content['field_tags']);
					hide($content['field_parallax_image']);
					hide($content['field_carousel_description']);
					hide($content['field_carousel_image']);
					hide($content['field_svg_imageset']);
					print render($content);

					if (isset($content['field_section_type']['#items'][0]['value'])) {
						switch ($content['field_section_type']['#items'][0]['value']) {
							case 'members':
								$members_nav = views_embed_view('pcp_members', 'nav');
								print $members_nav;
								break;
						}
					}
					?>
				</div>
			</div>
		</div>
		<?php
		if (isset($content['field_section_type']['#items'][0]['value'])) {
			switch ($content['field_section_type']['#items'][0]['value']) {
				case 'current_series':
					$current_view = views_embed_view('pcp_series', 'current_series');
					print $current_view;
					break;
				case 'past_reports':
					$past_reports = views_embed_view('pcp_series', 'past_reports');
					print $past_reports;
					break;
			}
		}
		?>
	</div>
	<?php
	if (isset($content['field_section_type']['#items'][0]['value'])) {
		switch ($content['field_section_type']['#items'][0]['value']) {
			case 'members':
				$members_bios = views_embed_view('pcp_members', 'bios');
				print $members_bios;
				// render the past members
				print "<div class='subsection small-centered'>";
				print "<div class='body past-members'>";
				print "<h3>Past Members</h3>";
				print render($content['field_svg_imageset']);
				print "</div></div>";
				break;
			case 'subsections':
				print render($content['field_subsection']);
				break;
		}
	}
	?>
</article>