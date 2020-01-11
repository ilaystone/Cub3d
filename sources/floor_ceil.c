/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_ceil.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhadem <ikhadem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 10:13:36 by ikhadem           #+#    #+#             */
/*   Updated: 2020/01/08 07:59:41 by ikhadem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		texturing(t_game *g, int y, int n)
{
	int			pos;
	int			pos2;

	g->dfc.texx = (int)(g->dfc.fx * g->t[n].w) % g->t[n].w;
	g->dfc.texy = (int)(g->dfc.fy * g->t[n].h) % g->t[n].h;
	pos = g->dfc.texx * 4 + g->dfc.texy * 4 * g->t[n].h;
	pos2 = g->cam.id * 4 + g_win.resolution.x * 4 * y;
	g_win.img_data[pos2] = get_shadow(g->dfc.currentdist,\
		g->t[n].img_ptr[pos]);
	g_win.img_data[pos2 + 1] = get_shadow(g->dfc.currentdist,\
		g->t[n].img_ptr[pos + 1]);
	g_win.img_data[pos2 + 2] = get_shadow(g->dfc.currentdist,\
		g->t[n].img_ptr[pos + 2]);
}

static void		coloring(t_game *g, int y, int n)
{
	int			pos2;

	g->dfc.texx = (int)(g->dfc.fx * 64) % 64;
	g->dfc.texy = (int)(g->dfc.fy * 64) % 64;
	pos2 = g->cam.id * 4 + g_win.resolution.x * 4 * y;
	g_win.img_data[pos2] = g->color[n].b;
	g_win.img_data[pos2 + 1] = g->color[n].g;
	g_win.img_data[pos2 + 2] = g->color[n].r;
}

static void		draw_vertical_stripes_floor(t_game *g)
{
	int			y;

	y = g->cam.drawend + 1;
	while (y < g_win.resolution.y)
	{
		g->dfc.currentdist = g_win.resolution.y /\
			(2.0 * (y - g->l_up) - g_win.resolution.y);
		g->dfc.weight = (g->dfc.currentdist - g->dfc.distplayer) /\
			(g->dfc.distwall - g->dfc.distplayer);
		g->dfc.fx = g->dfc.weight * g->dfc.fxwall + (1.0 - g->dfc.weight) *\
			g->cam.posx;
		g->dfc.fy = g->dfc.weight * g->dfc.fywall + (1.0 - g->dfc.weight) *\
			g->cam.posy;
		if (g->is_fc_rgb == 0)
			texturing(g, y, 29);
		else if (g->is_fc_rgb == 1)
			coloring(g, y, 0);
		y++;
	}
}

static void		draw_vertical_stripes_ceil(t_game *g)
{
	int			y;

	y = 0;
	while (y < g->cam.drawstart - 1)
	{
		g->dfc.currentdist = g_win.resolution.y /\
			(2.0 * (y - g->l_up) - g_win.resolution.y);
		g->dfc.currentdist *= -1;
		g->dfc.weight = (g->dfc.currentdist - g->dfc.distplayer) /\
			(g->dfc.distwall - g->dfc.distplayer);
		g->dfc.fx = g->dfc.weight * g->dfc.fxwall + (1.0 - g->dfc.weight) *\
			g->cam.posx;
		g->dfc.fy = g->dfc.weight * g->dfc.fywall + (1.0 - g->dfc.weight) *\
			g->cam.posy;
		if (g->is_fc_rgb == 0)
			texturing(g, y, 28);
		else if (g->is_fc_rgb == 1)
			coloring(g, y, 1);
		y++;
	}
}

void			cast_floor(t_game *g)
{
	if (g->cam.side == 0 && g->cam.raydirx > 0)
	{
		g->dfc.fxwall = g->cam.mapx;
		g->dfc.fywall = g->cam.mapy + g->t[0].wall_x;
	}
	if (g->cam.side == 0 && g->cam.raydirx < 0)
	{
		g->dfc.fxwall = g->cam.mapx + 1.0;
		g->dfc.fywall = g->cam.mapy + g->t[1].wall_x;
	}
	if (g->cam.side == 1 && g->cam.raydiry > 0)
	{
		g->dfc.fxwall = g->cam.mapx + g->t[2].wall_x;
		g->dfc.fywall = g->cam.mapy;
	}
	if (g->cam.side == 1 && g->cam.raydiry < 0)
	{
		g->dfc.fxwall = g->cam.mapx + g->t[3].wall_x;
		g->dfc.fywall = g->cam.mapy + 1.0;
	}
	g->dfc.distwall = g->cam.perpewalldist;
	g->dfc.distplayer = 0.0;
	if (g->cam.drawend < 0)
		g->cam.drawend = g_win.resolution.y;
	if (g->cam.drawstart < 0)
		g->cam.drawstart = 0;
	draw_vertical_stripes_floor(g);
	draw_vertical_stripes_ceil(g);
}
