/* Implement custom javascript here */
function triggerResize(includeResize) {
    if(includeResize == null || includeResize) {
        jQuery(window).trigger('resize');
    }
    
    jQuery(window).trigger('scroll');
}

var cookies = document.cookie;
if (cookies.indexOf('has_js') >= 0) {
    // ensure has_js is set to secure
    document.cookie = 'has_js=1;secure;';
}

(function ($) {

    // sets the height of the given imageset element and fires a resize
    function resizeImageset(imageset) {
        var $imageset = $(imageset);
        var $fadeout = $imageset.find('.imageset-fadeout');

        var pager = $imageset.data('pager');
        var pagerHint;

        var $image = $imageset.find('.imageset').first();
        var imageHeight = $image.outerHeight();

        if (!pager) {
            // get the current height
            var setHeight = $imageset.outerHeight();

            // record initial and current fraction shown 
            var initialFraction = setHeight / imageHeight;
            $imageset.data('initial', initialFraction);
            $imageset.data('padding', initialFraction);

            pagerHint = 1 / initialFraction;
            var pagerRemainder = pagerHint % 1;

            pagerHint = pagerRemainder < (0.34) ? Math.floor(pagerHint) : Math.ceil(pagerHint);

            $imageset.data('pager', 1);
            $imageset.data('pager-hint', pagerHint);
        }
        else {
            var pxHeight = null;
            pagerHint = $imageset.data('pager-hint');


            // calculate the new height based on the pager
            if (pager === 1) {
                // set to the initial fraction
                pxHeight = $imageset.data('initial') * imageHeight;
            }
            else if (pager === pagerHint) {
                // set to max height directly and hide the fader
                pxHeight = imageHeight + 50;
            }
            else {
                // set to a fraction of the imageheight
                pxHeight = ((pager / pagerHint) * imageHeight);
            }
            
            // calculate the window scroll target
            var windowOffset = $imageset.offset().top + pxHeight - $(window).height() + 30;

            $imageset.animate({
                paddingBottom: pxHeight + "px"
            }, {
                duration: 500,
                queue: false,
                complete: function () {
                    if (pager === pagerHint) {
                        $fadeout.hide();
                    }
                    else {
                        $fadeout.show();
                    }
                    
                    triggerResize();
                },
                step: function (now, tween) {
                    $(window).trigger('resize.px.parallax');
                }
            });

            $("html, body").animate({
                scrollTop: windowOffset
            }, {
                duration: 1000,
                queue: false
            });
        }
    }

    function scrollSection(element, position) {
        var $section = $(element);

        if ($section.attr('id')) {
            toggleMenu($section.attr('id'));
        }
    }

    function toggleMenu(menuId) {
        var anchor = $('.top-bar-section a[href="/#' + menuId + '"]');
        anchor.parent().addClass('active');
        anchor.addClass('active');

        var $inactiveItems = $('.top-bar-section a:not([href="/#' + menuId + '"])');
        $inactiveItems.parent().removeClass('active');
        $inactiveItems.removeClass('active');
    }

    var topoffset = 50; //variable for menu height

    // Activate Scrollspy
    function enableScrollspy() {

        $('.view-pcp-sections article').each(function () {
            var position = $(this).offset();
            
            var namespace = 'section-' + this.id;
            
            // wipe out all scroll events attached to this namespace
            $(window).unbind('scroll.' + namespace);

            $(this).scrollspy({
                min: position.top,
                max: position.top + $(this).height(),
                buffer: 300,
                namespace: namespace,
                onEnter: scrollSection//,
                //onTick: scrollSection,
            });        });

        // unbind all scroll events for home namespace
        $(window).unbind('scroll.section-home');

        // enable scrollspy for home
        $('body.front header, .section.carousel, .section.featured').each(function () {
            var position = $(this).offset();

            $(this).scrollspy({
                min: position.top,
                max: position.top + $(this).height(),
                namespace: 'section-home',
                onEnter: function (element, position) {
                    toggleMenu('front');
                }
            });
        });

        // enable scrollspy for meetings pages
        $('.meeting-main.current-series').each(function () {
            var anchor = $('.top-bar-section a[href="/#current-series"]');
            anchor.parent().addClass('active');
            anchor.addClass('active');
        });
        $('.meeting-main.past-reports').each(function () {
            var anchor = $('.top-bar-section a[href="/#past-reports"]');
            anchor.parent().addClass('active');
            anchor.addClass('active');
        });

        //Use smooth scrolling when clicking on navigation
        $('.top-bar-section a[href*=#]:not([href=#]), .carousel-link').click(function () {
            if (location.pathname.replace(/^\//, '') ===
                    this.pathname.replace(/^\//, '') &&
                    location.hostname === this.hostname) {
                var target = $(this.hash);
                target = target.length ? target : $('[name=' + this.hash.slice(1) + ']');
                if (target.length) {
                    $('html,body').animate({
                        scrollTop: target.offset().top - topoffset + 2
                    }, 0);
                    return false;
                } //target.length
            } //click function
        }); //smooth scrolling  
    }


    function clickMeetingLeftNavItem(){
        var hash = window.location.hash.slice(1); // get the hash, and strip out the "#"
        if (hash) {
            //var $meeting_left_nav_item = $('a.meeting-left-nav-item'+ '[data-section-id="' + hash + '"]');
            var $meeting_left_nav_item = $('a.meeting-left-nav-item'+ '[data-section-aliased-title="' + hash + '"]');
            if( $meeting_left_nav_item.length )  {
                $meeting_left_nav_item.trigger('click');
                //window.console&&console.log('Hash triggered.');
                // $('a' + hash ).trigger('click');
                // jQuery('a.meeting-left-nav-item'+ '#' + window.location.hash.slice(1)).trigger('click');
                // jQuery('a.meeting-left-nav-item'+ '[data-section-id="' + window.location.hash.slice(1) + '"]').trigger('click');
            }
        }
    }

    $(document).ready(function () {
        // invoke anythingslider
        $('#slider').anythingSlider({
            // Appearance
            theme: "default", // Theme name
            mode: "fade", // Set mode to "horizontal", "vertical" or "fade" (only first letter needed); replaces vertical option
            expand: true, // If true, the entire slider will expand to fit the parent element
            resizeContents: true, // If true, solitary images/objects in the panel will expand to fit the viewport
            aspectRatio: null, // Valid values: null, true, a float e.g. 1.5 (or as 3/2) or a ratio in a string e.g. '3:2'
            showMultiple: false, // Set this value to a number and it will show that many slides at once
            easing: "linear", // Anything other than "linear" or "swing" requires the easing plugin or jQuery UI

            buildArrows: true, // If true, builds the forwards and backwards buttons
            buildNavigation: true, // If true, builds a list of anchor links to link to each panel
            buildStartStop: true, // If true, builds the start/stop button and adds slideshow functionality

            appendForwardTo: null, // Append forward arrow to a HTML element (jQuery Object, selector or HTMLNode), if not null
            appendBackTo: null, // Append back arrow to a HTML element (jQuery Object, selector or HTMLNode), if not null
            appendControlsTo: null, // Append controls (navigation + start-stop) to a HTML element (jQuery Object, selector or HTMLNode), if not null
            appendNavigationTo: null, // Append navigation buttons to a HTML element (jQuery Object, selector or HTMLNode), if not null
            appendStartStopTo: null, // Append start-stop button to a HTML element (jQuery Object, selector or HTMLNode), if not null

            toggleArrows: false, // If true, side navigation arrows will slide out on hovering & hide @ other times
            toggleControls: false, // if true, slide in controls (navigation + play/stop button) on hover and slide change, hide @ other times

            startText: "Start", // Start button text
            stopText: "Stop", // Stop button text
            forwardText: "&raquo;", // Link text used to move the slider forward (hidden by CSS, replaced with arrow image)
            backText: "&laquo;", // Link text used to move the slider back (hidden by CSS, replace with arrow image)
            tooltipClass: "tooltip", // Class added to navigation & start/stop button (text copied to title if it is hidden by a negative text indent)

            // Function
            enableArrows: true, // if false, arrows will be visible, but not clickable.
            enableNavigation: true, // if false, navigation links will still be visible, but not clickable.
            enableStartStop: true, // if false, the play/stop button will still be visible, but not clickable. Previously "enablePlay"
            enableKeyboard: true, // if false, keyboard arrow keys will not work for this slider.

            // Navigation
            startPanel: 1, // This sets the initial panel
            changeBy: 1, // Amount to go forward or back when changing panels.
            hashTags: false, // Should links change the hashtag in the URL?
            infiniteSlides: true, // if false, the slider will not wrap & not clone any panels
            navigationFormatter: null, // Details at the top of the file on this use (advanced use)
            navigationSize: false, // Set this to the maximum number of visible navigation tabs; false to disable

            // Slideshow options
            autoPlay: true, // If true, the slideshow will start running; replaces "startStopped" option
            autoPlayLocked: false, // If true, user changing slides will not stop the slideshow
            autoPlayDelayed: false, // If true, starting a slideshow will delay advancing slides; if false, the slider will immediately advance to the next slide when slideshow starts
            pauseOnHover: true, // If true & the slideshow is active, the slideshow will pause on hover
            stopAtEnd: false, // If true & the slideshow is active, the slideshow will stop on the last page. This also stops the rewind effect when infiniteSlides is false.
            playRtl: false, // If true, the slideshow will move right-to-left

            // Times
            delay: 5000, // How long between slideshow transitions in AutoPlay mode (in milliseconds)
            resumeDelay: 5000, // Resume slideshow after user interaction, only if autoplayLocked is true (in milliseconds).
            animationTime: 1000, // How long the slideshow transition takes (in milliseconds)
            delayBeforeAnimate: 0, // How long to pause slide animation before going to the desired slide (used if you want your "out" FX to show).

            // Callbacks
            onBeforeInitialize: function (e, slider) {
            }, // Callback before the plugin initializes
            onInitialized: function (e, slider) {
            }, // Callback when the plugin finished initializing
            onShowStart: function (e, slider) {
            }, // Callback on slideshow start
            onShowStop: function (e, slider) {
            }, // Callback after slideshow stops
            onShowPause: function (e, slider) {
            }, // Callback when slideshow pauses
            onShowUnpause: function (e, slider) {
            }, // Callback when slideshow unpauses - may not trigger properly if user clicks on any controls
            onSlideInit: function (e, slider) {
            }, // Callback when slide initiates, before control animation
            onSlideBegin: function (e, slider) {
            }, // Callback before slide animates
            onSlideComplete: function (slider) {
            }, // Callback when slide completes; this is the only callback without an event "e" variable

            // Interactivity
            clickForwardArrow: "click", // Event used to activate forward arrow functionality (e.g. add jQuery mobile's "swiperight")
            clickBackArrow: "click", // Event used to activate back arrow functionality (e.g. add jQuery mobile's "swipeleft")
            clickControls: "click focusin", // Events used to activate navigation control functionality
            clickSlideshow: "click", // Event used to activate slideshow play/stop button
            allowRapidChange: false, // If true, allow rapid changing of the active pane, instead of ignoring activity during animation

            // Video
            resumeOnVideoEnd: true, // If true & the slideshow is active & a supported video is playing, it will pause the autoplay until the video is complete
            resumeOnVisible: true, // If true the video will resume playing (if previously paused, except for YouTube iframe - known issue); if false, the video remains paused.
            isVideoPlaying: function (base) {
                return false;
            } // return true if video is playing or false if not - used by video extension

            // deprecated - use the video extension `wmode` option now
            // addWmodeToObject : "opaque",  // If your slider has an embedded object, the script will automatically add a wmode parameter with this setting
        });

        // activate the parallax
        $('[data-parallax="scroll"]').parallax();

        // create click handlers for the member bios
        $('.member-nav a[data-member-bio]').each(function (index) {
            // get the related nid
            var $this = $(this);
            var nid = $this.attr('data-member-bio');

            $this.click(function () {

                // expand this anchor
                $this.addClass('expanded');

                // collapse all other anchors
                $('.member-nav a:not([data-member-bio=' + nid + '])').removeClass('expanded');

                // uncollapse this bio
                $('.member-bios div.body[data-member-bio=' + nid + ']')
                        .removeClass('small-only');

                // collapse all other bios
                $('.member-bios div.body:not([data-member-bio=' + nid + '])')
                        .addClass('small-only');

                triggerResize();
            });
        });

        // create click handlers for the member bio mobile view
        $('.member-bios a.view-bio').each(function (index) {
            // get the related nid
            var $this = $(this);

            $this.click(function () {
                // find the bio
                var $member = $($this.closest('.member'));
                var $bio = $member.children('.body');

                // toggle this anchor
                if ($this.hasClass('expanded')) {
                    $this.removeClass('expanded');
                    $bio.addClass('medium-up');
                }
                else {
                    $this.addClass('expanded');
                    $bio.removeClass('medium-up');
                }

                triggerResize();
            });
        });

        // create click handlers for view-more areas
        $('.subsection a.view-more').each(function (index) {
            // get the related nid
            var $this = $(this);
            var nid = $this.attr('data-body-id');

            $this.click(function () {
                // find the related body elements
                $('.subsection div.body[data-body-id=' + nid + ']').each(function (index) {
                    var $body_this = $(this);

                    // if the bio is hidden, show it and add expanded to the 
                    // anchor
                    if ($body_this.hasClass('hidden')) {
                        $body_this.removeClass('hidden');

                        // expand the related anchor
                        $this.addClass('expanded');
                    }
                    else {
                        // hide the body
                        $body_this.addClass('hidden');

                        // collapse the related anchor
                        $this.removeClass('expanded');
                    }
                });

                triggerResize();
            });

        });

        // create click handlers for member-nav areas
        $('.section-nav .nav-item a[data-section-id]').each(function (index) {
            // get the related nid
            var $sectionNav = $(this);
            var id = $sectionNav.attr('data-section-id');

            // get the related section-title
            var $sectionTitle = $('.meeting-sections .section-body[data-section-id=' + id + ']').siblings('.section-title');

            var activeItems = [
                $sectionNav[0], $sectionTitle[0]
            ];

            $(activeItems).click(function () {

                var $this = $(this);

                var $scrollTarget = null;

                if ($this.hasClass('section-title') && $this.hasClass('active')) {
                    // collapsing active section on mobile

                    // collapse all sections but set the first to medium-up
                    $('.meeting-sections .section-body[data-section-id]').each(function (index) {
                        var $section = $(this);
                        var sectionId = $section.attr('data-section-id');

                        if (sectionId === '0') {
                            // show this section and set title to active
                            $section.removeClass('collapsed');
                            $section.addClass('medium-up');
                        }
                        else {
                            // collapse this section and remove active from title
                            $section.addClass('collapsed');
                        }

                        // make the title inactive regardless
                        $section.siblings('.section-title').removeClass('active');
                    });

                    // set the first section nav to active
                    $('.section-nav .nav-item a[data-section-id]').each(function (index) {
                        var $nav = $(this);
                        var navId = $nav.attr('data-section-id');

                        if (navId === '0') {
                            // show this section
                            $nav.addClass('active');
                        }
                        else {
                            // collapse this section
                            $nav.removeClass('active');
                        }
                    });
                }
                else
                {
                    // expand clicked - find all relevant elements to expand/collapse
                    $('.meeting-sections .section-body[data-section-id]').each(function (index) {
                        var $section = $(this);
                        var sectionId = $section.attr('data-section-id');

                        if (id === sectionId) {
                            // show this section and set title to active
                            $section.removeClass('collapsed');

                            $section.siblings('.section-title').addClass('active');

                            // keep this section for later window scrolling
                            $scrollTarget = $section.siblings('.section-title');
                        }
                        else {
                            // collapse this section and remove active from title
                            $section.addClass('collapsed');

                            $section.siblings('.section-title').removeClass('active');
                        }

                        // in either case, remove medium-up class as a section will
                        // be visible at the mobile breakpoint
                        $section.removeClass('medium-up');
                    });

                    // set the correct nav to active
                    $('.section-nav .nav-item a[data-section-id]').each(function (index) {
                        var $nav = $(this);
                        var navId = $nav.attr('data-section-id');

                        if (id === navId) {
                            // show this section
                            $nav.addClass('active');
                        }
                        else {
                            // collapse this section
                            $nav.removeClass('active');
                        }
                    });
                }

                triggerResize();

                // scroll window to top of scroll target
                if ($scrollTarget !== null) {
                    $("html, body").animate({
                        scrollTop: $scrollTarget.offset().top - 100
                    }, {
                        duration: 500
                    });
                }
            });

        });

        triggerResize();

        $('.field-name-field-svg-imageset').each(function (index) {
            resizeImageset(this);

            var imageSet = this;
            var $imageSet = $(this);
            var $moreButton = $imageSet.find('.button.more').first();
            var $lessButton = $imageSet.find('.button.less').first();
            var pager = $imageSet.data('pager');
            var pagerHint = $imageSet.data('pager-hint');

            $moreButton.click(function () {
                pager++;
                if (pager >= pagerHint) {
                    pager = pagerHint;
                    $moreButton.addClass('disabled');
                }

                $lessButton.removeClass('disabled');
                $imageSet.data('pager', pager);

                resizeImageset(imageSet);
                triggerResize();
            });

            $lessButton.click(function () {
                pager--;
                if (pager <= 1) {
                    pager = 1;
                    $lessButton.addClass('disabled');
                }

                $moreButton.removeClass('disabled');
                $imageSet.data('pager', pager);

                resizeImageset(imageSet);
                triggerResize();
            });
        });

        // call click handler for meeting left nav
        var $meeting_left_nav_items =  $('a.meeting-left-nav-item');

        if($meeting_left_nav_items.length) {
            $meeting_left_nav_items.each(function(index){
                var rawTitle = $(this).data('section-raw-title'),
                  reWrittenTitle = rawTitle.trim().toLowerCase().replaceAll(' ','-'),
                  newHref = '#' + reWrittenTitle;
                window.console&&console.log('reWrittenTitle',reWrittenTitle);
                $(this).attr("data-section-aliased-title",reWrittenTitle).attr("href",newHref);
            });
        }


        clickMeetingLeftNavItem();

        window.addEventListener("hashchange", clickMeetingLeftNavItem, false);
    });

    window.onload = triggerResize;

    // equalheights
    function equalHeights() {
        $('[data-match-height]').each(function () {
            // initialize isStacked to false; this is the default behavior
            var isStacked = false;
            // get the '.equalheight' items to equalize them
            var items = $(this).find('.equalheight');
            if (items.length === 0) {
                return;
            }
            // get the top-offset of the first item, to check for stacking
            var firstTopOffset = items.first().offset().top;

            items.height('inherit');

            /* iterate through the items to:
             * 1) check if they're stacked, and
             * 2) get the heights of the elements
             *
             * for the heights, we could also use the following map
             * (outside of the each loop) but it DOESN'T WORK IN IE8:
             * items.map(function() { return $(this).height() });
             */
            var heights = [];
            items.each(function () {
                var el = $(this);
                if (el.offset().top !== firstTopOffset) {
                    isStacked = true;
                    return;
                }
                heights.push(el.height());
            });
            // if they are stacked, we don't need to worry about making them the same height
            if (isStacked) {
                return;
            }
            // get the maximum height (from the previously-calculated heights)
            var maxHeight = Math.max.apply(null, heights);

            // get the width of the whole row
            var rowWidth = $(this).width();

            // find equalheight and matchheight items - matchheight items
            // do not influence the final calculated height.
            var allitems = $(this).find('.equalheight, .matchheight');

            // define a function to set the height of an element
            function setHeight(item, height, maxWidth) {
                if ((rowWidth - item.width()) > maxWidth) {
                    item.height(height);
                }
            }
            // call that function for every 'item' in the 'items' array
            setHeight.call(null, allitems, maxHeight, 40);
        });
    }

    /* run the above function */
    $(window).on('load resize', function () {        
        equalHeights();
        
        triggerResize(false);

        enableScrollspy();
    });

}(jQuery));