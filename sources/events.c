/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhadem <ikhadem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 15:41:04 by ikhadem           #+#    #+#             */
/*   Updated: 2020/01/06 06:07:32 by ikhadem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		key_press(int key, t_game *g)
{
	if (key == K_ESC)
		exit(0);
	if (key == K_LEFT)
		g->cam.turn = 1;
	else if (key == K_RIGHT)
		g->cam.turn = -1;
	else if (key == K_W)
	{
		g->cam.move = 1;
		if (g->chacha == 0)
			Mix_PlayChannel(2, g->run, -1);
		g->chacha = 1;
	}
	else if (key == K_S)
		g->cam.move = -1;
	else if (key == K_A)
		g->cam.move_h = -1;
	else if (key == K_D)
		g->cam.move_h = 1;
	else if (key == K_F12)
		save_bmp_image();
	if (key == K_SP)
		g->kaka = 1;
	return (0);
}

int		key_release(int key, t_game *g)
{
	if (key == K_LEFT)
		g->cam.turn = 0;
	else if (key == K_RIGHT)
		g->cam.turn = 0;
	else if (key == K_W)
	{
		g->cam.move = 0;
		Mix_HaltChannel(2);
		g->chacha = 0;
	}
	else if (key == K_S)
		g->cam.move = 0;
	else if (key == K_A)
		g->cam.move_h = 0;
	else if (key == K_D)
		g->cam.move_h = 0;
	return (0);
}

int		mouse_press(int button, int x, int y, t_game *g)
{
	if (button == 1)
		g->kaka = 1;
	return (0);
}

int		mouse_release(int button, int x, int y, t_game *g)
{
	if (button == 1)
	{
		g->cam.move = 0;
		Mix_HaltChannel(2);
		g->chacha = 0;
	}
	return (0);
}

int		mouse_move(int x, int y, t_game *g)
{
	double	ratio;
	int		start;
	int		end;

	ratio = ((g_win.resolution.x / 2) - x) / g_win.resolution.x;
	start = g_win.resolution.x / 2 - g_win.resolution.x * 0.1;
	end = g_win.resolution.x / 2 + g_win.resolution.x * 0.1;
	if (x < start)
		g->cam.turn = ratio;
	else if (x > end)
		g->cam.turn = ratio;
	else
		g->cam.turn = 0;
	return (0);
}
