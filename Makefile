# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ikhadem <ikhadem@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/13 19:57:44 by ikhadem           #+#    #+#              #
#    Updated: 2019/12/16 18:01:22 by ikhadem          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC :=	main.c \
		sources/cub3d.c \
		sources/point.c \
		sources/line.c \
		sources/rect.c \
		sources/color.c \
		sources/player.c

all:
	@make -C libft/
	@$(CC) $(CFLAGS) $(SRC) libft/libft.a -lmlx -framework OpenGl -framework AppKit
	@echo "Done"
