FROM debian:bullseye

RUN apt-get update -y \
    && apt-get upgrade -y \
    && apt-get install mariadb-server -y \
    && apt-get clean

COPY /conf/50-server.cnf /etc/mysql/mariadb.conf.d/50-server.cnf

RUN mkdir -p /run/mysqld && chown -R mysql:mysql /run/mysqld

COPY /tools/start_mariadb.sh /usr/local/bin/start_mariadb.sh
RUN chmod +x /usr/local/bin/start_mariadb.sh

CMD ["/usr/local/bin/start_mariadb.sh"]

# mariadb -u root -p
# show databases;
# select user, host from mysql.user;
# use dbName; show tables;