/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhadem <ikhadem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 21:48:39 by ikhadem           #+#    #+#             */
/*   Updated: 2019/12/15 05:41:01 by ikhadem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <math.h>
# include "../minilibx/mlx.h"
# include "point.h"

typedef struct	s_display
{
	void	*ptr;
	void	*win;
	void	*img_ptr;
	int		bpp;
	int		size_line;
	int		endian;
	char	*img_data;
}				t_display;

t_display		g_win;

void			display_init(t_display *win, int w, int h, char *title);

#endif
