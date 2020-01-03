/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhadem <ikhadem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 21:48:39 by ikhadem           #+#    #+#             */
/*   Updated: 2020/01/01 18:16:39 by ikhadem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <math.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <errno.h>
# include <string.h>
# include "../minilibx/mlx.h"
# include "../GNL/get_next_line.h"
# include "utils.h"
# include "color.h"
# include "vec2.h"
# include "line.h"
# include "rect.h"
# include "key.h"
# include "game.h"
# include "bmp.h"

# define TRUE 1
# define FALSE 0

# define NORTH 0
# define SOUTH 1
# define EAST 2
# define WEST 3

typedef struct	s_canvas
{
	t_vec2		resolution;
	void		*ptr;
	void		*win;
	void		*img_ptr;
	int			bpp;
	int			size_line;
	int			endian;
	char		*img_data;
}				t_canvas;

t_canvas		g_win;

void			canvas_init(t_vec2 pos, char *title);
void			reset_image();

#endif
