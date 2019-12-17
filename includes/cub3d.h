/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhadem <ikhadem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 21:48:39 by ikhadem           #+#    #+#             */
/*   Updated: 2019/12/17 17:02:45 by ikhadem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <math.h>
# include <mlx.h>
# include "color.h"
# include "point.h"
# include "player.h"
# include "key.h"
# include "map.h"
# include "line.h"
# include "rect.h"


typedef struct	s_canvas
{
	void	*ptr;
	void	*win;
	void	*img_ptr;
	int		bpp;
	int		size_line;
	int		endian;
	char	*img_data;
}				t_canvas;

t_canvas		g_win;

void			canvas_init(int w, int h, char *title);

#endif
