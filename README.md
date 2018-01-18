# Dennis Facebook Instant Articles

This module provides fb_instant_articles with its required dependencies.

fb_instant_articles is using composer.json and the recommended way to manage
these dependencies is composer_manager. But composer_manager loads files from
other modules as well and more importantly, we don't have full composer support
on our Drupal 7 environments.

As a result, this module is providing fb_instant_articles with all the files that
it needs. `composer install --prefer-dist` or `composer update --prefer-dist` brings
in all the required files, autoloaded in .module so fb_instant_articles can use them.
Vendor files are committed which is not the most common practise but it is the only
practical way to deal with this scenario until we have full composer support.

## Installation

Add the module into site/modules and enable it as usual.
