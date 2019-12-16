/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhadem <ikhadem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 05:38:30 by ikhadem           #+#    #+#             */
/*   Updated: 2019/12/16 04:45:37 by ikhadem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_point			new_point(int x, int y)
{
	t_point		p;
	p.x = x;
	p.y = y;
	return (p);
}

void			add_point(t_point p, t_color c)
{
	int pos;

	pos = p.x * 4 + p.y * 4 * 29 * 32;
	g_win.img_data[pos] = (char)c.b;
	g_win.img_data[pos + 1] = (char)c.g;
	g_win.img_data[pos + 2] = (char)c.r;
}

void			draw_point(t_point p)
{
	add_point(p, new_color(255, 255, 255));
	mlx_put_image_to_window(g_win.ptr, g_win.win, g_win.img_ptr, 0, 0);
}
