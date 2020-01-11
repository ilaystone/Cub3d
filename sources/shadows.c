/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadows.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhadem <ikhadem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 18:11:02 by ikhadem           #+#    #+#             */
/*   Updated: 2020/01/09 03:33:54 by ikhadem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	get_shadow(double distance, char c)
{
	double	d;

	if (g_win.shadow == 1)
	{
		d = distance / 0.75;
		if (d > 1.)
			return ((c & 0xff) / d);
	}
	return (c);
}

void	hard_core(int key)
{
	if (key == K_F1)
		g_win.shadow = (g_win.shadow == 1) ? 0 : 1;
}

void	split_press(int key, t_game *g)
{
	if (key == K_LEFT)
		g->cam.turn = 1;
	if (key == K_RIGHT)
		g->cam.turn = -1;
	if (key == K_W)
	{
		g->cam.move = 1;
		if (g->chacha == 0)
			Mix_PlayChannel(2, g->run, -1);
		g->chacha = 1;
	}
	if (key == K_S)
		g->cam.move = -1;
	if (key == K_A)
		g->cam.move_h = -1;
	if (key == K_D)
		g->cam.move_h = 1;
	if (key == K_UP)
		g->l_up += ((g->l_up > 200) ? 0 : 5);
    if (key == K_DOWN)
		g->l_up += ((g->l_up < -200) ? 0 : -5);
}

void	set_gun(t_draw *v, t_game *g)
{
	g_win.img_data[v->pos2] = g->w[(int)(g->kaco / 1.5)].img_ptr[v->pos];
	g_win.img_data[v->pos2 + 1] = g->w[(int)(g->kaco / 1.5)].img_ptr[v->pos + 1];
	g_win.img_data[v->pos2 + 2] = g->w[(int)(g->kaco / 1.5)].img_ptr[v->pos + 2];
}

void	draw_gun(t_vec2 pos, t_game *g, int x, int y)
{
	t_draw	v;

	while (pos.x < g_win.resolution.x * 0.7)
	{
		v.y = pos.y;
		y = 0;
		while (v.y < g_win.resolution.y)
		{
			v.pos2 = pos.x * 4 + v.y * 4 * g_win.resolution.x;
			v.texx = (int)(x * (float)g->w[(int)(g->kaco / 1.5)].w /\
				(g_win.resolution.x * 0.2));
			v.texy = (int)(y * (float)g->w[(int)(g->kaco / 1.5)].h /\
				(g_win.resolution.y * 0.35));
			v.pos = 4 * v.texx + 4 * g->w[(int)(g->kaco / 1.5)].w * v.texy;
			if (g->w[(int)(g->kaco / 1.5)].img_ptr[v.pos + 3] == 0)
			{
				set_gun(&v, g);
			}
			v.y++;
			y++;
		}
		x++;
		pos.x++;
	}
}
