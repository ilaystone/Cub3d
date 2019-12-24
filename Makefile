# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ikhadem <ikhadem@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/13 19:57:44 by ikhadem           #+#    #+#              #
#    Updated: 2019/12/24 04:51:29 by ikhadem          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

CC = gcc

#CFLAGS = -Wall -Wextra -Werror

SRC :=	main.c \
		sources/cub3d.c \
		sources/vec2.c \
		sources/line.c \
		sources/rect.c \
		sources/color.c \
		sources/game.c \
		sources/caster.c


all:
	@$(CC) $(CFLAGS) $(SRC) -g -lmlx -framework OpenGl -framework AppKit
	@echo "Done"
