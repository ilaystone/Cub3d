/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhadem <ikhadem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 14:53:23 by ikhadem           #+#    #+#             */
/*   Updated: 2019/12/16 03:17:14 by ikhadem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_line		new_line(t_point p1, t_point p2, t_color c)
{
	t_line	l;

	l.p1 = p1;
	l.p2 = p2;
	l.c = c;
	return (l);
}

void		add_line(t_line l, t_point d, t_point s)
{
	int			err;
	int			e;

	d.x = abs(l.p2.x - l.p1.x);
	s.x = l.p1.x < l.p2.x ? 1 : -1;
	d.y = -abs(l.p2.y - l.p1.y);
	s.y = l.p1.y < l.p2.y ? 1 : -1;
	err = d.x + d.y;
	while (1)
	{
		add_point(l.p1, l.c);
		if (l.p1.x == l.p2.x && l.p1.y == l.p2.y)
			break ;
		e = 2 * err;
		if (e >= d.y)
		{
			err += d.y;
			l.p1.x += s.x;
		}
		if (e <= d.x)
		{
			err += d.x;
			l.p1.y += s.y;
		}
	}
}

void		draw_line(t_line l)
{
	add_line(l, new_point(0, 0), new_point(0, 0));
	mlx_put_image_to_window(g_win.ptr, g_win.win, g_win.img_ptr, 0, 0);
}