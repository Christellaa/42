#!/bin/bash

DB_USER=$(cat /run/secrets/db_user)
DB_PASS=$(cat /run/secrets/db_pass)
DB_ROOT_PASS=$(cat /run/secrets/db_root_pass)

echo "CREATE DATABASE IF NOT EXISTS $DB ;" > /etc/mysql/init_database.sql
echo "CREATE USER IF NOT EXISTS '$DB_USER'@'%' IDENTIFIED BY '$DB_PASS' ;" >> /etc/mysql/init_database.sql
echo "GRANT ALL PRIVILEGES ON $DB.* TO '$DB_USER'@'%' ;" >> /etc/mysql/init_database.sql
echo "ALTER USER 'root'@'localhost' IDENTIFIED BY '$DB_ROOT_PASS' ;" >> /etc/mysql/init_database.sql
echo "FLUSH PRIVILEGES;" >> /etc/mysql/init_database.sql

exec mysqld