/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhadem <ikhadem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 05:38:30 by ikhadem           #+#    #+#             */
/*   Updated: 2020/01/06 22:05:21 by ikhadem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_vec2			new_vec2(double x, double y)
{
	t_vec2		p;

	p.x = x;
	p.y = y;
	return (p);
}

void			add_vec2(t_vec2 v, t_color c)
{
	int pos;

	pos = v.x * 4 + v.y * 4 * g_win.resolution.x;
	g_win.img_data[pos] = (char)c.b;
	g_win.img_data[pos + 1] = (char)c.g;
	g_win.img_data[pos + 2] = (char)c.r;
	g_win.img_data[pos + 3] = (char)c.a;
}

void			draw_vec2(t_vec2 p)
{
	add_vec2(p, new_color(255, 255, 255, 0));
	mlx_put_image_to_window(g_win.ptr, g_win.win, g_win.img_ptr, 0, 0);
}
