/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhadem <ikhadem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 21:48:39 by ikhadem           #+#    #+#             */
/*   Updated: 2019/12/15 21:56:03 by ikhadem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <math.h>
# include "../minilibx/mlx.h"
# include "point.h"
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

void			canvas_init(t_canvas *win, int w, int h, char *title);

#endif
