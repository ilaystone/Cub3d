/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhadem <ikhadem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 20:46:22 by ikhadem           #+#    #+#             */
/*   Updated: 2020/01/07 00:49:58 by ikhadem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		full_init(t_game *g)
{
	int		i;

	i = 0;
	g->map.grid = NULL;
	while (i < 20)
	{
		g->t[i].img = NULL;
		i++;
	}
	i = 0;
	while (i < 6)
	{
		g->w[i].img = NULL;
		i++;
	}
	g->run = NULL;
	g->gun = NULL;
}

void		release_music(t_game *g)
{
	Mix_FreeChunk(g->gun);
	Mix_FreeChunk(g->run);
	Mix_FreeMusic(g->bgm[1]);
	Mix_FreeMusic(g->bgm[0]);
	Mix_FreeMusic(g->bgm[2]);
	Mix_FreeMusic(g->bgm[3]);
}

void		full_free(t_game *g)
{
	int		i;

	i = 0;
	if (g->map.grid)
		free(g->map.grid);
	while (i < 20)
	{
		if (g->t[i].img != NULL)
			mlx_destroy_image(g_win.ptr, g->t[i].img);
		i++;
	}
	i = 0;
	while (i < 6)
	{
		if (g->w[i].img != NULL)
			mlx_destroy_image(g_win.ptr, g->w[i].img);
		i++;
	}
	release_music(g);
}

int			kill_game(t_game *g)
{
	full_free(g);
	SDL_CloseAudio();
	exit_msg("thank for trying this game");
	return (0);
}
