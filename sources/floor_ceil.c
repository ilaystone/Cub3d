/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_ceil.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhadem <ikhadem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 10:13:36 by ikhadem           #+#    #+#             */
/*   Updated: 2019/12/29 17:55:35 by ikhadem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	ceiling(t_game *g, int pos, int pos2)
{
	g_win.img_data[pos2] = g->t[4].img_ptr[pos];
	g_win.img_data[pos2 + 1] = g->t[4].img_ptr[pos + 1];
	g_win.img_data[pos2 + 2] = g->t[4].img_ptr[pos + 2];
}

static void	ground(t_game *g, int pos, int pos2)
{
	g_win.img_data[pos2] = g->t[5].img_ptr[pos];
	g_win.img_data[pos2 + 1] = g->t[5].img_ptr[pos + 1];
	g_win.img_data[pos2 + 2] = g->t[5].img_ptr[pos + 2];
}

static void	draw_vertical_stripes(t_game *g)
{
	int		pos;
	int		pos2;
	int		y;

	y = g->cam.drawend + 1;
	while (y < g_win.resolution.y)
	{
		g->dfc.currentdist = g_win.resolution.y /\
			(2.0 * y - g_win.resolution.y);
		g->dfc.weight = (g->dfc.currentdist - g->dfc.distplayer) /\
			(g->dfc.distwall - g->dfc.distplayer);
		g->dfc.fx = g->dfc.weight * g->dfc.fxwall + (1.0 - g->dfc.weight) *\
			g->cam.posx;
		g->dfc.fy = g->dfc.weight * g->dfc.fywall + (1.0 - g->dfc.weight) *\
			g->cam.posy;
		g->dfc.texx = (int)(g->dfc.fx * g->t[4].w) % g->t[4].w;
		g->dfc.texy = (int)(g->dfc.fy * g->t[4].h) % g->t[4].h;
		pos = g->dfc.texx * 4 + g->dfc.texy * 4 * g->t[4].h;
		pos2 = g->cam.id * 4 + g_win.resolution.x * 4 * y;
		ceiling(g, pos, pos2);
		pos2 = g->cam.id * 4 + g_win.resolution.x * 4 *\
			(g_win.resolution.y - y);
		ground(g, pos, pos2);
		y++;
	}
}

void		cast_floor(t_game *g)
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
	draw_vertical_stripes(g);
}
