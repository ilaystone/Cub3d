/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhadem <ikhadem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 15:40:21 by ikhadem           #+#    #+#             */
/*   Updated: 2020/01/07 03:24:41 by ikhadem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		move_camera(t_game *g, double rt)
{
	double	olddirx;
	double	oldplanex;

	if (g->cam.turn != 0)
	{
		olddirx = g->cam.dirx;
		g->cam.dirx = g->cam.dirx * cos(rt) - g->cam.diry * sin(rt);
		g->cam.diry = olddirx * sin(rt) + g->cam.diry * cos(rt);
		oldplanex = g->cam.planex;
		g->cam.planex = g->cam.planex * cos(rt) - g->cam.planey * sin(rt);
		g->cam.planey = oldplanex * sin(rt) + g->cam.planey * cos(rt);
	}
}

/*
** dir either 1 : according to Dir
**			  2 : according to Plane
*/

static void	move_player(t_game *g, int dir, double mv)
{
	double	side_x;
	double	side_y;
	int		j;

	side_x = (dir == 1) ? g->cam.dirx : g->cam.planex;
	side_y = (dir == 1) ? g->cam.diry : g->cam.planey;
	j = (int)(g->cam.posx + side_x * mv) + (int)(g->cam.posy + side_y * mv) *\
		g->map.width;
	if (g->map.grid[j] == '0')
	{
		g->cam.posx += side_x * mv;
		g->cam.posy += side_y * mv;
	}
	else
	{
		j = (int)(g->cam.posx + side_x * mv) + (int)(g->cam.posy) *\
			g->map.width;
		if (g->map.grid[j] == '0')
			g->cam.posx += side_x * mv;
		j = (int)(g->cam.posx) + (int)(g->cam.posy + side_y * mv) *\
			g->map.width;
		if (g->map.grid[j] == '0')
			g->cam.posy += side_y * mv;
	}
}

void		update_player_pos(t_game *g)
{
	double	rt;

	rt = g->cam.turn * (3 * M_PI / 180);
	move_camera(g, rt);
	if (g->cam.move != 0)
		move_player(g, 1, g->cam.move * 0.1);
	if (g->cam.move_h != 0)
		move_player(g, 2, g->cam.move_h * 0.1);
}
