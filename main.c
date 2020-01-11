/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhadem <ikhadem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 23:27:42 by ikhadem           #+#    #+#             */
/*   Updated: 2020/01/09 03:30:19 by ikhadem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		update(t_game *game)
{
	t_vec2	start;

	reset_image();
	update_player_pos(game);
	cast_rays(game);
	draw_lifebar(game);
	if (game->kaka != 0)
	{
		if (game->kaco + game->kaka == 9)
		{
			game->kaka = 0;
			game->kaco = 0;
		}
		if (game->kaco == 1)
			Mix_PlayChannel(1, game->gun, 0);
		game->kaco += game->kaka;
	}
	start.x = (int)(g_win.resolution.x * 0.5);
	start.y = (int)(g_win.resolution.y * 0.65);
	draw_gun(start, game, 0, 0);
	mlx_put_image_to_window(g_win.ptr, g_win.win, g_win.img_ptr, 0, 0);
	draw_hud();
	return (0);
}

void	game_start(t_game *game)
{
	mlx_hook(g_win.win, 2, 0, key_press, game);
	mlx_hook(g_win.win, 3, 0, key_release, game);
	mlx_hook(g_win.win, 17, 0, kill_game, game);
	mlx_hook(g_win.win, 4, 0, mouse_press, game);
	mlx_hook(g_win.win, 5, 0, mouse_release, game);
	mlx_mouse_move(g_win.win, (int)(g_win.resolution.x / 2),\
		(int)(g_win.resolution.y / 2));
	mlx_loop_hook(g_win.ptr, update, game);
	mlx_do_sync(g_win.ptr);
	mlx_loop(g_win.ptr);
}

int		main(int ac, char *av[])
{
	t_game game;

	SDL_Init(SDL_INIT_AUDIO);
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 4096);
	if (!check_extention(av[1]))
	{
		ft_puterror("wrong file format:\n\tusage: ./cub3D <name>.cub\n");
		exit(EXIT_FAILURE);
	}
	if (ac == 3 && ft_strncmp("--save", av[2], 6) != 0)
		exit_msg("second argument is wrong verify '--save' !!");
	game = init_game(av[1]);
	if (ac == 3 && ft_strncmp("--save", av[2], 6) == 0)
	{
		update(&game);
		save_bmp_image();
	}
	if (ac == 2)
	{
		game_start(&game);
		// update(&game);
		// int i = -1;
		// while (i++ < 500)
		// 	printf("%d ==> %lf\n", i, game.zbuff[i]);
	}
	else
		exit_msg("too many arguments");
	return (0);
}
