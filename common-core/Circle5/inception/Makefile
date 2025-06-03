DC = docker compose -f srcs/docker-compose.yml
SERVICE = $(filter-out $@,$(MAKECMDGOALS))
DATA = ${HOME}/data
DB_VOLUME = $(DATA)/mariadb
WP_VOLUME = $(DATA)/wordpress

all: up

data:
	mkdir -p $(DB_VOLUME) $(WP_VOLUME)

build: data
	$(DC) build

up: build
	$(DC) up -d

exec:
	$(DC) exec $(SERVICE) bash

logs:
	$(DC) logs $(SERVICE)

cls:
	docker ps -a

vls:
	docker volume ls

ils:
	docker image ls

nls:
	docker network ls

down:
	$(DC) down

iclean:
	$(DC) down --rmi all

vclean:
	$(DC) down --rmi all -v
	sudo rm -rf $(DATA)
	sudo docker system prune -af
