FROM debian:bullseye

RUN apt-get update -y \
    && apt-get upgrade -y \
    && apt-get install -y \
    wget \
    php7.4-fpm \
    php7.4-mysqli \
    && apt-get clean

RUN mkdir -p /var/www/html \
    && wget https://wordpress.org/wordpress-6.8.1.tar.gz \
    && tar -xzf wordpress-6.8.1.tar.gz \
    && rm wordpress-6.8.1.tar.gz \
    && mv wordpress /var/www/html

RUN mkdir -p /run/php && chown -R www-data:www-data /run/php
COPY /conf/www.conf /etc/php/7.4/fpm/pool.d/www.conf
COPY /tools/init_wp.sh .
RUN chmod +x ./init_wp.sh

CMD ["./init_wp.sh"]