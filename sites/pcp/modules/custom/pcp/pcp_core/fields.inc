<?php

/**
 * Constructs a fieldset. Check the content model.
 * 
 * @return type Fieldset: Content ; Body, Image, For More Information
 */
function _mynci_fieldset_content() {
    return array(
        'field_body' => array(
            'field_name' => 'field_body',
            'type' => 'text_with_summary',
            'cardinality' => 1,
            'default_widget' => 'text_textarea_with_summary',
            'required' => TRUE,
            'label' => t('Body'),
            'description' => t('This detailed description will appear only on the content page.'),
            'default_formatter' => 'text_summary_or_trimmed',
            'settings' => array(
                'rows' => '20',
                'text_processing' => TRUE,
                'display_summary' => FALSE,
            ),
            'instance_settings' => array(
                'text_processing' => TRUE,
                'display_summary' => FALSE,
            ),
            'display' => array(
                'default' => array(
                    'label' => 'hidden',
                ),
            ),
        ),
        'field_image_collection' => array(
            'field_name' => 'field_image_collection',
            'cardinality' => 1,
            'type' => 'field_collection',
            'description' => '',
            'widget' => array('type' => 'field_collection_embed'),
            'required' => FALSE,
            'label' => t('Image'),
            'display' => array(
                'default' => array(
                    'label' => 'hidden',
                    'type' => 'field_collection_fields',
                ),
            ),
        ),
        /**
         *  DEPRECATED FIELD - Replaced by field_for_more_info
         *
          'field_for_more_information' => array(
          'field_name' => 'field_for_more_information',
          'type' => 'entityreference',
          'cardinality' => FIELD_CARDINALITY_UNLIMITED,
          'default_widget' => 'entityreference_autocomplete_tags',
          'required' => FALSE,
          'label' => t('For More Information'),
          'settings' => array(
          'target_type' => 'node',
          'handler' => 'base',
          ),
          'display' => array(
          'default' => array(
          'label' => 'hidden',
          ),
          ),
          'widget' => array(
          'type' => 'entityreference_autocomplete_tags',
          ),
          ),
         *
         */
        'field_for_more_info' => array(
            'field_name' => 'field_for_more_info',
            'type' => 'field_collection',
            'entity_type' => 'node',
            'cardinality' => FIELD_CARDINALITY_UNLIMITED,
            'widget' => array('type' => 'field_collection_embed'),
            'required' => FALSE,
            'label' => t('For More Information'),
            'display' => array(
                'default' => array(
                    'label' => 'hidden',
                    'type' => 'field_collection_fields',
                ),
            ),
        ),
    );
}

function _mynci_field_collection_more_info() {
    return array(
        'field_for_more_info' . '_links' => array(
            'field_name' => 'field_for_more_info' . '_links',
            'type' => 'link_field',
            'cardinality' => 1,
            'default_widget' => 'link_field',
            'required' => TRUE,
            'label' => t('Link'),
            'settings' => array(
                'validate_url' => 1,
                'url' => 0,
                'title' => 'optional',
                'title_value' => '',
                'title_maxlength' => '128',
                'enable_tokens' => 1,
                'attributes' => array(
                    'target' => 'default',
                ),
                'linkit' => array(
                    'enable' => TRUE,
                    'insert_plugin' => 'raw_url',
                ),
            ),
            'display' => array(
                'default' => array(
                    'label' => 'hidden',
                ),
            ),
        ),
        'field_for_more_info' . '_desc' => array(
            'field_name' => 'field_for_more_info' . '_desc',
            'type' => 'text',
            'cardinality' => 1,
            'default_widget' => 'text_textfield',
            'required' => FALSE,
            'label' => t('Link Description'),
            'display' => array(
                'default' => array(
                    'label' => 'hidden',
                ),
            ),
        ),
    );
}

function _mynci_field_collection_image() {
    $local_fields = array();
    $local_fields[] = array(
        'field_name' => 'field_image',
        'type' => 'image',
        'cardinality' => 1,
        'default_widget' => 'image_image',
        'required' => FALSE,
        'label' => t('Image'),
        'description' => t('Upload an image for this content. This image will appear above the body field on the page.'),
        'settings' => array(
            'uri_scheme' => variable_get('file_default_scheme', 'public'),
            'default_image' => 0,
            'alt_field' => TRUE,
            'title_field' => FALSE,
        ),
        'instance_settings' => array(
            'file_extensions' => 'png gif jpg jpeg',
            'file_directory' => 'field/image',
            'max_filesize' => '2 MB',
        ),
        'display' => array(
            'default' => array(
                'label' => 'hidden',
            ),
        ),
    );
    $local_fields[] = array(
        'field_name' => 'field_image_caption',
        'type' => 'text_long',
        'cardinality' => 1,
        'default_widget' => 'text_textarea',
        'required' => FALSE,
        'label' => t('Caption'),
        'description' => t('The caption to display under an image.'),
        'default_formatter' => 'text_default',
        'settings' => array(
            //'max_length' => 250,
            'rows' => '3', // @todo Rows won't set??
            'text_processing' => 0,
        ),
        'widget' => array(// @todo Some kind of countdown?
            'type' => 'text_textarea',
            'settings' => array(
                'rows' => '3',
            )
        ),
        'display' => array(
            'default' => array(
                'label' => 'hidden',
            ),
        ),
    );


    return $local_fields;
}

/**
 * Constructs a fieldset. Check the content model.
 * 
 * @return type Fieldset: Metadata ; Description, Topics, Tags, NCI Organization,
 *      Contact, Date Posted, Date Updated, Date Reviewed
 */
function _mynci_fieldset_metadata() {
    return array(
        'field_description' => array(
            'field_name' => 'field_description',
            'type' => 'text_long',
            'cardinality' => 1,
            'default_widget' => 'text_textarea',
            'required' => TRUE,
            'label' => t('Short Description'),
            'description' => t('This description will appear in the search results and display on pages throughout the site. The character limit is 250.'),
            'default_formatter' => 'text_default',
            'settings' => array(
                //'max_length' => 250,
                'rows' => '3', // @todo Rows won't set??
                'text_processing' => 0,
            ),
            'widget' => array(// @todo Some kind of countdown?
                'type' => 'text_textarea',
                'settings' => array(
                    'rows' => '3',
                )
            ),
            'display' => array(
                'default' => array(
                    'label' => 'hidden',
                ),
            ),
        ),
        'field_topics' => array(
            'field_name' => 'field_topics',
            'type' => 'taxonomy_term_reference',
            'cardinality' => FIELD_CARDINALITY_UNLIMITED,
            'default_widget' => 'options_buttons',
            'required' => TRUE,
            'label' => t('Topics'),
            'settings' => array(
                'allowed_values' => array(
                    array(
                        'vocabulary' => 'mynci_topics',
                        'parent' => 0,
                    ),
                ),
            ),
        ),
        'field_tags' => array(
            'field_name' => 'field_tags',
            'type' => 'taxonomy_term_reference',
            'cardinality' => FIELD_CARDINALITY_UNLIMITED,
            'default_widget' => 'taxonomy_autocomplete',
            'required' => FALSE,
            'label' => t('Tags'),
            'settings' => array(
                'allowed_values' => array(
                    array(
                        'vocabulary' => 'mynci_tags',
                        'parent' => 0,
                    ),
                ),
            ),
            'widget' => array(
                'type' => 'taxonomy_autocomplete',
                'settings' => array(
                    'content_taxonomy_autocomplete_new_terms' => 'allow',
                ),
            )
        ),
        'field_nci_organization' => array(
            'field_name' => 'field_nci_organization',
            'type' => 'taxonomy_term_reference',
            'cardinality' => FIELD_CARDINALITY_UNLIMITED,
            'default_widget' => 'taxonomy_autocomplete', // ToDo: Organization Widget
            'required' => FALSE,
            'label' => t('Content Owner (Organization)'),
            'description' => t("Content tagged with an organization will appear on that organization's page in the directory. A link to the organization will also display on the content page."),
            'settings' => array(
                'allowed_values' => array(
                    array(
                        'vocabulary' => 'mynci_organizations',
                        'parent' => 0,
                    ),
                ),
            ),
            'widget' => array(
                'type' => 'taxonomy_autocomplete',
                'module' => 'taxonomy',
                'settings' => array(
                    'content_taxonomy_autocomplete_new_terms' => 'deny'
                ),
            ),
            'display' => array(
                'default' => array(
                    'label' => 'inline',
                ),
            ),
        ),
        'field_contact' => array(
            'field_name' => 'field_contact',
            'type' => 'entityreference',
            'cardinality' => 2,
            'default_widget' => 'entityreference_autocomplete', // ToDo: People Widget
            'required' => TRUE,
            'label' => t('Contact for this Content'),
            'description' => t("The person responsible for the content and primary point of contact for the Governance team. One contact is required but two contacts are recommended."),
            'settings' => array(
                'target_type' => 'user',
                'handler' => 'base',
            ),
            'display' => array(
                'default' => array(
                    'label' => 'inline',
                ),
            ),
        // @todo: Custom field validation
        ),
        'field_date_posted' => array(
            'field_name' => 'field_date_posted',
            'type' => 'date',
            'cardinality' => 1,
            'default_widget' => 'date_popup',
            'required' => TRUE,
            'label' => t('Date Posted'),
            'description' => t("The date that the content is or will be published."),
            'default_formatter' => 'date_default',
            'settings' => array(
                'granularity' => date_granularity_array_from_precision('day'),
                'default_value' => 'now',
            ),
            'widget' => array(
                'type' => 'date_popup',
                'settings' => array(
                    'year_range' => '-0:+0',
                    'input_format' => 'custom',
                    'input_format_custom' => 'F d, Y',
                )
            ),
            'display' => array(
                'default' => array(
                    'label' => 'inline',
                ),
            ),
        ),
        'field_date_updated' => array(
            'field_name' => 'field_date_updated',
            'type' => 'date',
            'cardinality' => 1,
            'default_widget' => 'date_popup',
            'required' => FALSE,
            'label' => t('Date Updated'),
            'description' => t("The date that the content was last updated."),
            'default_formatter' => 'date_default',
            'settings' => array(
                'granularity' => date_granularity_array_from_precision('day'),
                'default_value' => 'now',
            ),
            'widget' => array(
                'type' => 'date_popup',
                'settings' => array(
                    'year_range' => '-10:+0',
                    'input_format' => 'custom',
                    'input_format_custom' => 'F d, Y',
                )
            ),
            'display' => array(
                'default' => array(
                    'label' => 'inline',
                ),
            ),
        ),
        'field_date_reviewed' => array(
            'field_name' => 'field_date_reviewed',
            'type' => 'date',
            'cardinality' => 1,
            'default_widget' => 'date_popup',
            'required' => FALSE,
            'label' => t("Date Reviewed"),
            'description' => t("Update this date after each content review."),
            'default_formatter' => 'date_default',
            'settings' => array(
                'granularity' => date_granularity_array_from_precision('day'),
                'default_value' => 'now',
            ),
            'widget' => array(
                'type' => 'date_popup',
                'settings' => array(
                    'year_range' => '-10:+0',
                    'input_format' => 'custom',
                    'input_format_custom' => 'F d, Y',
                )
            ),
            'display' => array(
                'default' => array(
                    'label' => 'inline',
                ),
            ),
        ),
    );
}

/**
 * Constructs a fieldset. Check the content model.
 * 
 * @global type $user The user currently accessing the field should be the default.
 * @return type Fieldset: Author ; Author
 */
function _mynci_fieldset_author() {
    global $user; // Get the current user so they are set to be the default author
    return array(
        'field_author' => array(
            'field_name' => 'field_author',
            'type' => 'entityreference',
            'cardinality' => FIELD_CARDINALITY_UNLIMITED,
            'default_widget' => 'entityreference_autocomplete_tags',
            'required' => TRUE,
            'label' => t('Author to Be Displayed in Byline'),
            'description' => t("If someone other than the content owner should be listed in the byline, enter that name here."),
            'settings' => array(
                'target_type' => 'user',
                'handler' => 'base',
            ),
            'display' => array(
                'default' => array(
                    'label' => 'hidden',
                ),
            ),
            'widget' => array(
                'type' => 'entityreference_autocomplete_tags',
            ),
        )
    );
}

/**
 * Constructs a fieldset. Check the content model.
 * 
 * @return type Fieldset: File ; File
 */
function _mynci_fieldset_file() {
    return array(
        'field_file' => array(
            'field_name' => 'field_file',
            'type' => 'file',
            'cardinality' => 1,
            'default_widget' => 'file_generic',
            'required' => TRUE,
            'label' => t('Upload File'),
            'settings' => array(
                'file_extensions' => 'htm html pdf ppt pptx xls xlsx doc docx mobi epub',
                'alt_field' => FALSE,
                'title_field' => FALSE,
                'file_directory' => 'field/file',
                'uri_scheme' => variable_get('file_default_scheme', 'public'),
                'default_image' => 0,
            ),
            'display' => array(
                'default' => array(
                    'label' => 'hidden',
                ),
            ),
        )
    );
}

/**
 * Constructs a fieldset. Check the content model.
 * 
 * @return type Fieldset: FormPolicy ; Form or Policy Number, Governing Body
 */
function _mynci_fieldset_formpolicy() {
    return array(
        'field_form_or_policy_number' => array(
            'field_name' => 'field_form_or_policy_number',
            'type' => 'text',
            'cardinality' => 1,
            'default_widget' => 'text_textfield',
            'required' => FALSE,
            'label' => t('Form Number'),
            'widget' => array(
                'settings' => array(
                    'size' => '10',
                )
            ),
            'display' => array(
                'default' => array(
                    'label' => 'hidden',
                ),
            ),
        ),
        'field_ompc_approved' => array(
            'field_name' => 'field_ompc_approved',
            'type' => 'list_boolean',
            'cardinality' => 1,
            'default_widget' => 'options_onoff',
            'required' => FALSE,
            'label' => t('OMPC Approved?'),
            'widget' => array(
                'type' => 'options_onoff',
                'settings' => array(
                    'display_label' => TRUE,
                ),
            ),
            'settings' => array(
                'allowed_values' => array(
                    0 => 'No',
                    1 => 'Yes'
                )
            )
        ),
        'field_governing_body' => array(
            'field_name' => 'field_governing_body',
            'type' => 'list_integer',
            'cardinality' => 1,
            'default_widget' => 'options_select', // @todo Organization Widget
            'required' => FALSE,
            'label' => t('Governing Body'),
            'description' => t("Select the organization that is responsible for this form or policy."),
            'settings' => array(
                'allowed_values' => array(
                    0 => 'NCI',
                    1 => 'NIH',
                    2 => 'HHS',
                    3 => 'OPM',
                ),
            ),
            'display' => array(
                'default' => array(
                    'label' => 'hidden',
                ),
            ),
        )
    );
}

/**
 * Constructs a fieldset. Check the content model.
 * 
 * @return type Fieldset: Link ; Link
 */
function _mynci_fieldset_link() {
    return array(
        'field_link' => array(
            'field_name' => 'field_link',
            'type' => 'link_field',
            'cardinality' => 1,
            'default_widget' => 'link_field',
            'label' => t('Link URL'),
            'description' => t('Use a specific link name (vs. something generic like "Read More").'),
            'display' => array(
                'default' => array(
                    'label' => 'hidden',
                ),
            ),
        )
    );
}

function _mynci_fieldset_emailoptions() {
    return array(
    );
}

/**
 * Social Media Fieldset. 
 * Provides the following fields:
 *  field_twitter
 *  field_facebook
 *  field_researchgate
 *  field_yammer
 *  field_linkedin
 */
function _mynci_fieldset_socialmedia() {
    return array(
        'field_twitter' => array(
            'field_name' => 'field_twitter',
            'type' => 'text',
            'cardinality' => 1,
            'default_widget' => 'text_textfield',
            'required' => FALSE,
            'label' => t('Twitter'),
            'widget' => array(
            )
        ),
        'field_facebook' => array(
            'field_name' => 'field_facebook',
            'type' => 'text',
            'cardinality' => 1,
            'default_widget' => 'text_textfield',
            'required' => FALSE,
            'label' => t('Facebook'),
            'widget' => array(
            )
        ),
        'field_researchgate' => array(
            'field_name' => 'field_researchgate',
            'type' => 'text',
            'cardinality' => 1,
            'default_widget' => 'text_textfield',
            'required' => FALSE,
            'label' => t('ResearchGate'),
            'widget' => array(
            )
        ),
        'field_linkedin' => array(
            'field_name' => 'field_linkedin',
            'type' => 'text',
            'cardinality' => 1,
            'default_widget' => 'text_textfield',
            'required' => FALSE,
            'label' => t('LinkedIn'),
            'widget' => array(
            )
        ),
        'field_yammer' => array(
            'field_name' => 'field_yammer',
            'type' => 'text',
            'cardinality' => 1,
            'default_widget' => 'text_textfield',
            'required' => FALSE,
            'label' => t('Yammer'),
            'widget' => array(
            )
        ),
    );
}

function _mynci_fieldset_eventdatetime() {
    return array(
        'field_event_date' => array(
            'field_name' => 'field_event_date',
            'type' => 'datestamp',
            'cardinality' => 1,
            'default_widget' => 'date_popup',
            'required' => TRUE,
            'label' => t('Event Date'),
            'description' => t("The event's start and end times."),
            'default_formatter' => 'date_default',
            'settings' => array(
                'granularity' => date_granularity_array_from_precision('minute'),
                'default_value' => 'now',
                'todate' => 'required'
            ),
            'widget' => array(
                'type' => 'date_popup',
                'settings' => array(
                    'year_range' => '-0:+1',
                    'input_format' => 'custom',
                    'input_format_custom' => 'F j, Y g:i A',
                )
            ),
            'display' => array(
                'default' => array(
                    'label' => 'inline',
                    'type' => 'date_default',
                    'settings' => array(
                        'fromto' => 'both',
                    ),
                ),
            ),
        ),
        'field_event_all_day' => array(
            'field_name' => 'field_event_all_day',
            'type' => 'list_boolean',
            'cardinality' => 1,
            'default_widget' => 'options_onoff',
            'required' => FALSE,
            'label' => t('All Day Event?'),
            'widget' => array(
                'type' => 'options_onoff',
                'settings' => array(
                    'display_label' => TRUE,
                ),
            ),
            'settings' => array(
                'allowed_values' => array(
                    0 => 'No',
                    1 => 'Yes'
                )
            )
        )
    );
}

function _mynci_fieldset_campus_location() {
    return array(
        'field_campus' => array(
            'field_name' => 'field_campus',
            'type' => 'taxonomy_term_reference',
            'cardinality' => 1,
            'default_widget' => 'taxonomy_autocomplete',
            'required' => FALSE,
            'label' => t('Campus'),
            'description' => t("Select a location, if applicable."),
            'settings' => array(
                'allowed_values' => array(
                    array(
                        'vocabulary' => 'mynci_campus',
                        'parent' => 0,
                    ),
                ),
            ),
            'display' => array(
                'default' => array(
                    'label' => 'hidden',
                ),
            ),
        ),
            /* 'field_campus' => array(
              'field_name' => 'field_campus',
              'type' => 'list_integer',
              'cardinality' => 1,
              'default_widget' => 'options_select',
              'required' => FALSE,
              'label' => t('Campus'),
              'description' => t('Select a location, if applicable.'),
              'settings' => array(
              'allowed_values' => array(
              0 => 'NIH Campus - Lipsett (Bethesda)',
              1 => 'NIH Campus - Masur (Bethesda)',
              2 => 'NIH Campus - Natcher (Bethesda)',
              3 => 'NIH Campus - Other (Bethesda)',
              4 => 'Shady Grove campus',
              5 => 'NCI-Frederick',
              6 => 'ATRF (Frederick)'
              ),
              ),
              ), */
    );
}