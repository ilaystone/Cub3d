# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ikhadem <ikhadem@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/13 19:57:44 by ikhadem           #+#    #+#              #
#    Updated: 2020/01/05 15:42:52 by ikhadem          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#TODO: Redo this Makefile

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
		sources/camera.c \
		sources/events.c \
		sources/mouvement.c

LIBS = -I SDL/SDL2.framework/Headers/ -I SDL/SDL2_mixer.framework/Headers/ -I minilibx/ -I GNL/ -I includes/

all:
	@make -C minilibx/
	@$(CC) $(CFLAGS) $(SRC) $(LIBS) minilibx/libmlx.a -lz -framework OpenGl -framework AppKit -rpath @loader_path/SDL\
		-framework SDL2 -F SDL/ -framework SDL2_mixer -F SDL/ -o cub3D 
	@echo "Done"
