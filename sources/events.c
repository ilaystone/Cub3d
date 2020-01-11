/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhadem <ikhadem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 15:41:04 by ikhadem           #+#    #+#             */
/*   Updated: 2020/01/08 04:05:39 by ikhadem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		key_press(int key, t_game *g)
{
	if (key == K_ESC)
		kill_game(g);
	split_press(key, g);
	if (key == K_F12)
		save_bmp_image();
	if (key == K_SP)
		g->kaka = 1;
	play_music(key, g);
	hard_core(key);
	return (0);
}

int		key_release(int key, t_game *g)
{
	if (key == K_LEFT)
		g->cam.turn = 0;
	if (key == K_RIGHT)
		g->cam.turn = 0;
	if (key == K_W)
	{
		g->cam.move = 0;
		Mix_HaltChannel(2);
		g->chacha = 0;
	}
	if (key == K_S)
		g->cam.move = 0;
	if (key == K_A)
		g->cam.move_h = 0;
	if (key == K_D)
		g->cam.move_h = 0;
	return (0);
}

int		mouse_press(int button, int x, int y, t_game *g)
{
	(void)y;
	if (button == 1)
		g->kaka = 1;
	if (button == 2)
	{
		if (x > g_win.resolution.x / 2)
			g->cam.turn = -0.5;
		else
			g->cam.turn = 0.5;
	}
	return (0);
}

int		mouse_release(int button, int x, int y, t_game *g)
{
	(void)x;
	(void)y;
	if (button == 1)
	{
		Mix_HaltChannel(2);
		g->chacha = 0;
	}
	if (button == 2)
	{
		g->cam.turn = 0;
	}
	return (0);
}
