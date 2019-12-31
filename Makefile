# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ikhadem <ikhadem@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/13 19:57:44 by ikhadem           #+#    #+#              #
#    Updated: 2019/12/30 21:51:14 by ikhadem          ###   ########.fr        #
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
		sources/walls.c \
		sources/caster.c \
		sources/floor_ceil.c \
		sources/sprites.c \
		sources/sprites_utils.c


all:
	@make -C minilibx/
	@$(CC) $(CFLAGS) $(SRC) minilibx/libmlx.a -lz -framework OpenGl	\
			-framework AppKit
	@echo "Done"
