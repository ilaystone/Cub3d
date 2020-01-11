/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   caster.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhadem <ikhadem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 03:50:34 by ikhadem           #+#    #+#             */
/*   Updated: 2020/01/08 05:24:00 by ikhadem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		dda(t_game *g)
{
	int		j;

	while (g->cam.hit == 0)
	{
		if (g->cam.sidedistx < g->cam.sidedisty)
		{
			g->cam.sidedistx += g->cam.deltadistx;
			g->cam.mapx += g->cam.stepx;
			g->cam.side = 0;
		}
		else
		{
			g->cam.sidedisty += g->cam.deltadisty;
			g->cam.mapy += g->cam.stepy;
			g->cam.side = 1;
		}
		j = g->map.width * g->cam.mapy + g->cam.mapx;
		if (g->map.grid[j] == '1')
			g->cam.hit = 1;
		else if (g->map.grid[j] == '1')
			g->cam.hit = 1;
	}
}

void		calc(t_game *g)
{
	if (g->cam.raydirx < 0)
	{
		g->cam.stepx = -1;
		g->cam.sidedistx = (g->cam.posx - g->cam.mapx) * g->cam.deltadistx;
	}
	else
	{
		g->cam.stepx = 1;
		g->cam.sidedistx = (g->cam.mapx + 1 - g->cam.posx) * g->cam.deltadistx;
	}
	if (g->cam.raydiry < 0)
	{
		g->cam.stepy = -1;
		g->cam.sidedisty = (g->cam.posy - g->cam.mapy) * g->cam.deltadisty;
	}
	else
	{
		g->cam.stepy = 1;
		g->cam.sidedisty = (g->cam.mapy + 1 - g->cam.posy) * g->cam.deltadisty;
	}
}

void		line_size(t_game *g)
{
	if (g->cam.side == 0)
		g->cam.perpewalldist = (double)((g->cam.mapx - g->cam.posx +\
			(1 - g->cam.stepx) / 2) / g->cam.raydirx);
	else
		g->cam.perpewalldist = (double)((g->cam.mapy - g->cam.posy +\
			(1 - g->cam.stepy) / 2) / g->cam.raydiry);
	if (g->cam.perpewalldist <= 0.05)
		g->cam.perpewalldist = 0.05;
	g->cam.lineheight = (int)(g_win.resolution.y / g->cam.perpewalldist);
	g->cam.drawstart = -g->cam.lineheight / 2 + g_win.resolution.y / 2 + g->l_up;
	if (g->cam.drawstart <= 0)
		g->cam.drawstart = 0;
	g->cam.drawend = g->cam.lineheight / 2 + g_win.resolution.y / 2 + g->l_up;
	if (g->cam.drawend >= g_win.resolution.y)
		g->cam.drawend = g_win.resolution.y - 1;
}

void		create_world(t_game *g)
{
	draw_walls(g);
	cast_floor(g);
}

void		cast_rays(t_game *g)
{
	int x;

	x = 0;
	while (x < g_win.resolution.x)
	{
		g->cam.camerax = 2 * x / (double)g_win.resolution.x - 1;
		g->cam.raydirx = g->cam.dirx + g->cam.planex * g->cam.camerax;
		g->cam.raydiry = g->cam.diry + g->cam.planey * g->cam.camerax;
		g->cam.mapx = (int)g->cam.posx;
		g->cam.mapy = (int)g->cam.posy;
		g->cam.deltadistx = fabs(1 / g->cam.raydirx);
		g->cam.deltadisty = fabs(1 / g->cam.raydiry);
		g->cam.hit = 0;
		g->cam.id = x;
		g->zbuff[x] = g->cam.perpewalldist;
		calc(g);
		dda(g);
		line_size(g);
		create_world(g);
		x++;
	}
	draw_sprites(g);
}
