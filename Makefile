# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ikhadem <ikhadem@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/13 19:57:44 by ikhadem           #+#    #+#              #
#    Updated: 2020/01/09 03:35:09 by ikhadem          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

CC = gcc

# CFLAGS = -Wall -Wextra -Werror

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
		sources/mouvement.c \
		sources/exit.c \
		sources/hud.c \
		sources/music.c \
		sources/shadows.c

OBJ := $(SRC:.c=.o)

HEADERS = -I SDL/SDL2.framework/Headers/ -I SDL/SDL2_mixer.framework/Headers/ \
			-I minilibx/ -I GNL/ -I includes/

LIBS = minilibx/libmlx.a -lz -framework OpenGl -framework AppKit -rpath\
			@loader_path/SDL -framework SDL2 -F SDL/ -framework SDL2_mixer\
			-F SDL/

all: $(NAME)

$(NAME): $(OBJ)
	@make -C minilibx/
	@$(CC) $(CFLAGS) $(HEADERS) $(LIBS) $(OBJ) -o cub3D
	@echo "Done"

%.o : %.c
	$(CC) $(CFLAGS) -c $(HEADERS) $< -o $@

clean:
	@make clean -C minilibx/
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

bonus: all
