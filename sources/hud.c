/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhadem <ikhadem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 21:44:01 by ikhadem           #+#    #+#             */
/*   Updated: 2020/01/09 00:31:44 by ikhadem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		draw_lifebar(void)
{
	t_vec2	pos;
	int		y;

	pos.x = g_win.resolution.x / 2 - (g_win.resolution.x * 0.1);
	pos.y = g_win.resolution.x / 2 + (g_win.resolution.x * 0.1);
	y = 22;
	add_line(new_line(new_vec2(pos.x, 20), new_vec2(pos.y, 20),\
		new_color(0, 0, 0, 0)));
	add_line(new_line(new_vec2(pos.x, 21), new_vec2(pos.y, 21),\
		new_color(0, 0, 0, 0)));
	while (y < 48)
	{
		add_line(new_line(new_vec2(pos.x, y), new_vec2(pos.y, y),\
			new_color(255, 0, 0, 0)));
		y++;
	}
	add_line(new_line(new_vec2(pos.x, 48), new_vec2(pos.y, 48),\
		new_color(0, 0, 0, 0)));
	add_line(new_line(new_vec2(pos.x, 49), new_vec2(pos.y, 49),\
		new_color(0, 0, 0, 0)));
}

void		draw_hud(void)
{
	mlx_string_put(g_win.ptr, g_win.win, 10, 20, 0xffffff, "moving player : \
		W A S D");
	mlx_string_put(g_win.ptr, g_win.win, 10, 30, 0xffffff, "mouving camera : \
		left right");
	mlx_string_put(g_win.ptr, g_win.win, 10, 40, 0xffffff, "change music : \
		1 2 3 4");
	mlx_string_put(g_win.ptr, g_win.win, 10, 50, 0xffffff, "screen shot : \
		f12");
	mlx_string_put(g_win.ptr, g_win.win, 10, 60, 0xffffff, "disable shadows : \
		f1");
	mlx_string_put(g_win.ptr, g_win.win, 10, 70, 0xffffff, "shoot : \
		space / left mouse click");
	mlx_string_put(g_win.ptr, g_win.win, g_win.resolution.x / 2 - 4,\
		40, 0xffffff, "100%");
}

void		init_gun(t_game *g)
{
	g->w[0] = get_texture("./Archive/1.png");
	g->w[1] = get_texture("./Archive/2.png");
	g->w[2] = get_texture("./Archive/3.png");
	g->w[3] = get_texture("./Archive/4.png");
	g->w[4] = get_texture("./Archive/5.png");
	g->w[5] = get_texture("./Archive/6.png");
}
