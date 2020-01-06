/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhadem <ikhadem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 23:27:42 by ikhadem           #+#    #+#             */
/*   Updated: 2020/01/06 05:56:15 by ikhadem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "cub3d.h"

int	exit_game(t_game *g)
{
	(void)g;
	exit(0);
}

void	draw_gun(t_game *game)
{
	t_vec2	start;

	start.x = (int)(g_win.resolution.x / 2 - game->gun.w / 2);
	start.y = (int)(g_win.resolution.y - game->gun.h);

}

int update(t_game *game)
{
	reset_image();
	update_player_pos(game);
	cast_rays(game);
	//  draw_minimap(game);
	// draw_gun(game);
	mlx_put_image_to_window(g_win.ptr, g_win.win, g_win.img_ptr, 0, 0);
	t_vec2	start;
	// //mlx_put_image_to_window(g_win.ptr, g_win.win, game->gun.img, start.x, start.y);
	if (game->kaka != 0)
	{
		if (game->kaco + game->kaka == 9)
		{
			game->kaka = 0;
			game->kaco = 0;
		}
		if(game->kaco == 1)
				Mix_PlayChannel(1, game->Gun, 0);
		game->kaco += game->kaka;
	}
	start.x = (int)(g_win.resolution.x / 2);
	start.y = (int)(g_win.resolution.y - game->w[(int)(game->kaco / 1.5)].h);
	mlx_put_image_to_window(g_win.ptr, g_win.win, game->w[(int)(game->kaco / 1.5)].img, start.x, start.y);
	return (0);
}

int main(int ac, char *av[])
{
	t_tex	gun;
	t_game game;
	SDL_Init(SDL_INIT_AUDIO);
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
	Mix_Music	*back_ground_music = Mix_LoadMUS("./SFX/Castle Vania.mp3"); 
	Mix_Chunk	*runing_effect = Mix_LoadWAV("./SFX/Run.wav");
	Mix_Chunk	*Gun_effct = Mix_LoadWAV("./SFX/Gun.wav");
	Mix_PlayMusic(back_ground_music, -1);

	if (!check_extention(av[1]))
	{
		ft_puterror("wrong file format:\n\tusage: ./cub3D <name>.cub\n");
		exit (EXIT_FAILURE);
	}
	game = init_game(av[1]);
	game.chacha = 0;
	game.kaka = 0;
	game.kaco = 0;
	game.run = runing_effect;
	game.Gun = Gun_effct;
	gun = get_texture("./pics/knife.png");
	game.w[0] = get_texture("./Archive/1.png");
	game.w[1] = get_texture("./Archive/2.png");
	game.w[2] = get_texture("./Archive/3.png");
	game.w[3] = get_texture("./Archive/4.png");
	game.w[4] = get_texture("./Archive/5.png");
	game.w[5] = get_texture("./Archive/6.png");
	game.gun = gun;
	if (ac == 3 && ft_strncmp("--save", av[2], 6) != 0)
		exit_msg("second argument is wrong verify '--save' !!");
	else if (ac == 3 && ft_strncmp("--save", av[2], 6) == 0)
	{
		update(&game);
		save_bmp_image();
	}
	if (ac == 2)
	{
		mlx_hook(g_win.win, 2, 0, key_press, &game);
		mlx_hook(g_win.win, 3, 0, key_release, &game);
		mlx_hook(g_win.win, 17, 0, exit_game, &game);
		mlx_hook(g_win.win, 4, 0, mouse_press, &game);
		mlx_hook(g_win.win, 5, 0, mouse_release, &game);
		mlx_hook(g_win.win, 5, 0, mouse_release, &game);
		mlx_hook(g_win.win, 6, 0, mouse_move, &game);
		mlx_mouse_move(g_win.win, (int)(g_win.resolution.x / 2), (int)(g_win.resolution.y / 2));
		mlx_mouse_hide();
		mlx_loop_hook(g_win.ptr, update, &game);
		mlx_do_sync(g_win.ptr);
		mlx_loop(g_win.ptr);
	}
	else
		exit_msg("too many arguments");

	Mix_FreeChunk(runing_effect);
	Mix_FreeMusic(back_ground_music);
	SDL_CloseAudio();
	return (0);
}