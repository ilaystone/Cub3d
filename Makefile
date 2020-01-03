# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ikhadem <ikhadem@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/13 19:57:44 by ikhadem           #+#    #+#              #
#    Updated: 2020/01/03 01:22:53 by ikhadem          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

CC = gcc

#CFLAGS = -Wall -Wextra -Werror

SRC :=	main.c \
		GNL/get_next_line.c \
		GNL/get_next_line_utils.c \
		sources/cub3d.c \
		sources/vec2.c \
		sources/line.c \
		sources/rect.c \
		sources/color.c \
		sources/walls.c \
		sources/caster.c \
		sources/floor_ceil.c \
		sources/sprites.c \
		sources/sprites_utils.c \
		sources/bmp.c \
		sources/utils.c \
		sources/utils_2.c \
		sources/parser.c \
		sources/parser_utils.c \
		sources/checker.c \
		sources/map.c \
		sources/camera.c

all:
	@make -C minilibx/
	@$(CC) $(CFLAGS) $(SRC) minilibx/libmlx.a -lz -framework OpenGl	\
			-framework AppKit -o cub3D
	@echo "Done"
