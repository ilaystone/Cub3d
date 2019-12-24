/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhadem <ikhadem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 23:27:42 by ikhadem           #+#    #+#             */
/*   Updated: 2019/12/24 20:34:05 by ikhadem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "includes/cub3d.h"

int key_press(int key, t_game *g)
{
	if (key == K_ESC)
		exit(0);
	if (key == K_LEFT)
		g->cam.turn = 1;
	else if (key == K_RIGHT)
		g->cam.turn = -1;
	else if (key == K_UP)
		g->cam.move = 1;
	else if (key == K_DOWN)
		g->cam.move = -1;
	return (0);
}

int key_release(int key, t_game *g)
{
	if (key == K_LEFT)
		g->cam.turn = 0;
	else if (key == K_RIGHT)
		g->cam.turn = 0;
	else if (key == K_UP)
		g->cam.move = 0;
	else if (key == K_DOWN)
		g->cam.move = 0;
	return (0);
}

void update_player_pos(t_game *g)
{
	double	rt;
	double	mv;
	double	olddirx;
	double	oldplanex;
	int 	j;

	rt = g->cam.turn * (2.0 * M_PI / 180);
	mv = g->cam.move * 0.05;
	if (g->cam.turn != 0)
	{
		olddirx = g->cam.dirx;
		g->cam.dirx = g->cam.dirx * cos(rt) - g->cam.diry * sin(rt);
		g->cam.diry = olddirx * sin(rt) + g->cam.diry * cos(rt);
		oldplanex = g->cam.planex;
		g->cam.planex = g->cam.planex * cos(rt) - g->cam.planey * sin(rt);
		g->cam.planey = oldplanex * sin(rt) + g->cam.planey * cos(rt);
	}
	if (g->cam.move != 0)
	{
		j = g->cam.posx + g->cam.dirx * mv + (g->cam.posy + g->cam.diry * mv) * g->map.width;
		if (g->map.grid[j] != '1')
		{
			g->cam.posx += g->cam.dirx * mv;
			g->cam.posy += g->cam.diry * mv;
		}
	}
}

int update(t_game *game)
{
	reset_image();
	update_player_pos(game);
	cast_rays(game);
	mlx_put_image_to_window(g_win.ptr, g_win.win, g_win.img_ptr, 0, 0);
	return (0);
}

int main()
{
	t_map map;
	t_cam cam;
	t_game game;

	map.width = 29;
	map.height = 14;
	map.grid = strdup("111111111111111111111111111111000000000110000000000000000110110000011100000020000010001100100000000000000000000100011011000001110000000000001000110000000001100000111011110001111101111111110111000000100011111011111111101110101001000111000000110101011100000010001100020000000000011000000100011000000000000000110101001000111000000110101011111011110N011111011111110101111101111000111111111111111111111111111111");
	cam.posx = 2;
	cam.posy = 2;
	cam.dirx = -1;
	cam.diry = 0;
	cam.planex = 0;
	cam.planey = 0.66;
	game.map = map;
	game.cam = cam;
	canvas_init(new_vec2(1600, 900), "CUB3D");
	mlx_put_image_to_window(g_win.ptr, g_win.win, g_win.img_ptr, 0, 0);
	mlx_hook(g_win.win, 2, 0, key_press, &game);
	mlx_hook(g_win.win, 3, 0, key_release, &game);
	mlx_loop_hook(g_win.ptr, update, &game);
	mlx_loop(g_win.ptr);
	return (0);
}