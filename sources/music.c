/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   music.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhadem <ikhadem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 20:45:53 by ikhadem           #+#    #+#             */
/*   Updated: 2020/01/07 01:32:04 by ikhadem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		init_music(t_game *g)
{
	g->bgm[0] = Mix_LoadMUS("./SFX/Castle Vania.mp3");
	g->bgm[1] = Mix_LoadMUS("./SFX/Gulie Stage.mp3");
	g->bgm[2] = Mix_LoadMUS("./SFX/Kirby dream.mp3");
	g->bgm[3] = Mix_LoadMUS("./SFX/Shooting Stars.mp3");
	g->gun = Mix_LoadWAV("./SFX/Gun.wav");
	g->run = Mix_LoadWAV("./SFX/Run.wav");
}

void		reset_music(Mix_Music *bgm)
{
	Mix_HaltMusic();
	Mix_PlayMusic(bgm, -1);
}

void		play_music(int key, t_game *g)
{
	if (key == K_DIGIT_1)
		reset_music(g->bgm[0]);
	if (key == K_DIGIT_2)
		reset_music(g->bgm[1]);
	if (key == K_DIGIT_3)
		reset_music(g->bgm[2]);
	if (key == K_DIGIT_4)
		reset_music(g->bgm[3]);
}
