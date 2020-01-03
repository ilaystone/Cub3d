/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhadem <ikhadem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 23:27:42 by ikhadem           #+#    #+#             */
/*   Updated: 2020/01/03 02:13:07 by ikhadem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "includes/cub3d.h"

int	exit_game(t_game *g)
{
	(void)g;
	exit(0);
}

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
	int		j;

	rt = g->cam.turn * (2 * M_PI / 180);
	mv = g->cam.move * 0.1;
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
		j = (int)(g->cam.posx + g->cam.dirx * mv) + (int)(g->cam.posy + g->cam.diry * mv) * g->map.width;
		if (g->map.grid[j] == '0')
		{
			g->cam.posx += g->cam.dirx * mv;
			g->cam.posy += g->cam.diry * mv;
		}
		else
		{
			j = (int)(g->cam.posx + g->cam.dirx * mv) + (int)(g->cam.posy) * g->map.width;
			if (g->map.grid[j] == '0')
				g->cam.posx += g->cam.dirx * mv;
			j = (int)(g->cam.posx) + (int)(g->cam.posy + g->cam.diry * mv) * g->map.width;
			if (g->map.grid[j] == '0')
				g->cam.posy += g->cam.diry * mv;
		}
	}
}

int update(t_game *game)
{
	reset_image();
	update_player_pos(game);
	cast_rays(game);
	//draw_minimap(game);
	mlx_put_image_to_window(g_win.ptr, g_win.win, g_win.img_ptr, 0, 0);
	return (0);
}

int main(int ac, char *av[])
{
	// t_map map;
	// t_cam cam;
	t_game game;

	// map.width = 29;
	// map.height = 14;
	// map.grid = strdup("1111111111111111111111111111110000000001100000000000000001101100000111000000200000100011001000000000000000000001000110110000011100000000000010001100000000011000001110111100011111011111111101110000001000111110111111111011101010010001110000001101010111000000100011000200000000000110000001000110000000000000001101010010001110000001101010111110111100011111011111110101111101111000111111111111111111111111111111");
	// cam.posx = 26;
	// cam.posy = 11;
	// cam.dirx = 0;
	// cam.diry = 0;
	// cam.planex = 0;
	// cam.planey = 0.66;
	// game.map = map;
	// game.cam = cam;
	// game.spcount = 0;
	// get_all_sprites(&game);
	// canvas_init(new_vec2(1600, 900), "CUB3D");
	// game.t[0] = get_texture("./pics/colorstone.png");
	// game.t[1] = get_texture("./pics/bluestone.png");
	// game.t[2] = get_texture("./pics/greystone.png");
	// game.t[3] = get_texture("./pics/redbrick.png");
	// game.t[4] = get_texture("./pics/mossy.png");
	// game.t[5] = get_texture("./pics/wood.png");
	// game.t[6] = get_texture("./pics/kirby2.png");
	// update(&game);
	// save_bmp_image(&game);
	if (!check_extention(av[1]))
	{
		ft_puterror("wrong file format:\n\tusage: ./cub3D <name>.cub\n");
		exit (EXIT_FAILURE);
	}
	game = init_game(av[1]);
	mlx_hook(g_win.win, 2, 0, key_press, &game);
	mlx_hook(g_win.win, 3, 0, key_release, &game);
	mlx_hook(g_win.win, 17, 0, exit_game, &game);
	mlx_loop_hook(g_win.ptr, update, &game);
	mlx_loop(g_win.ptr);
	return (0);
}