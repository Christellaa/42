#!/bin/bash

cd /var/www/html
wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
chmod +x wp-cli.phar

DB_USER=$(cat /run/secrets/db_user)
DB_PASS=$(cat /run/secrets/db_pass)
WP_ADMIN_USER=$(cat /run/secrets/wp_admin_user)
WP_ADMIN_MAIL=$(cat /run/secrets/wp_admin_mail)
WP_ADMIN_PASS=$(cat /run/secrets/wp_admin_pass)
WP_GUEST_USER=$(cat /run/secrets/wp_guest_user)
WP_GUEST_MAIL=$(cat /run/secrets/wp_guest_mail)
WP_GUEST_PASS=$(cat /run/secrets/wp_guest_pass)

# generate wp-config.php
./wp-cli.phar core download --allow-root

./wp-cli.phar config create \
    --dbname=$DB \
    --dbuser=$DB_USER \
    --dbpass=$DB_PASS \
    --dbhost=$DB_HOST \
    --allow-root

# install wordpress + add admin user
./wp-cli.phar core install \
    --url=$WP_URL \
    --title=$WP_TITLE \
    --admin_user=$WP_ADMIN_USER \
    --admin_password=$WP_ADMIN_PASS \
    --admin_email=$WP_ADMIN_MAIL \
    --allow-root

# add a guest user
./wp-cli.phar user create \
    $WP_GUEST_USER \
    $WP_GUEST_MAIL \
    --role=subscriber \
    --user_pass=$WP_GUEST_PASS \
    --allow-root

/usr/sbin/php-fpm7.4 -F