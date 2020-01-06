/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhadem <ikhadem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 14:53:23 by ikhadem           #+#    #+#             */
/*   Updated: 2020/01/04 00:30:38 by ikhadem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_line		new_line(t_vec2 p1, t_vec2 p2, t_color c)
{
	t_line	l;

	l.p1 = p1;
	l.p2 = p2;
	l.c = c;
	return (l);
}

void		add_line(t_line l)
{
	t_plot	plot;

	plot.dx = abs((int)l.p2.x - (int)l.p1.x);
	plot.sx = l.p1.x < l.p2.x ? 1 : -1;
	plot.dy = -abs((int)l.p2.y - (int)l.p1.y);
	plot.sy = l.p1.y < l.p2.y ? 1 : -1;
	plot.err = plot.dx + plot.dy;
	while (1)
	{
		add_vec2(new_vec2(l.p1.x, l.p1.y), l.c);
		if (l.p1.x == l.p2.x && l.p1.y == l.p2.y)
			break ;
		plot.e2 = 2 * plot.err;
		if (plot.e2 >= plot.dy)
		{
			plot.err += plot.dy;
			l.p1.x += plot.sx;
		}
		if (plot.e2 <= plot.dx)
		{
			plot.err += plot.dx;
			l.p1.y += plot.sy;
		}
	}
}

void		draw_line(t_line l)
{
	add_line(l);
	mlx_put_image_to_window(g_win.ptr, g_win.win, g_win.img_ptr, 0, 0);
}
