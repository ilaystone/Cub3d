/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhadem <ikhadem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/01 16:28:58 by ikhadem           #+#    #+#             */
/*   Updated: 2020/01/08 05:13:16 by ikhadem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int				check_extention(char *file)
{
	int			len;

	len = ft_strlen(file) - 1;
	if (!file)
		return (0);
	if (file[len] != 'b')
		return (0);
	if (file[len - 1] != 'u')
		return (0);
	if (file[len - 2] != 'c')
		return (0);
	if (file[len - 3] != '.')
		return (0);
	return (1);
}

/*
** NO = 0 / SO = 1 / WE = 2 EA = 3
** floor and ceil have either a texture or RGB
** floor texture 28 ceil texture id 29
*/

static void		loop_file(t_parser *p, t_game *game)
{
	p->c = get_next_line(p->fd, &p->str);
	check_resolution(p->str);
	while ((p->c = get_next_line(p->fd, &p->str)) > 0)
	{
		if (p->str[0] == 'R')
			exit_msg("duplicate indicator :\nresolution");
		else if (p->str[0] == 'N' && p->str[1] == 'O')
			init_wall_textures(game, p->str, &p->set[0]);
		else if (p->str[0] == 'S' && p->str[1] == 'O')
			init_wall_textures(game, p->str, &p->set[1]);
		else if (p->str[0] == 'W' && p->str[1] == 'E')
			init_wall_textures(game, p->str, &p->set[2]);
		else if (p->str[0] == 'E' && p->str[1] == 'A')
			init_wall_textures(game, p->str, &p->set[3]);
		else if (p->str[0] == 'S')
			init_sprites(game, p->str, &p->num_of_sprites_id);
		else if (p->str[0] == 'F' || p->str[0] == 'C')
			init_floor_ceil(game, p->str, p->set);
		else if (ft_isdigit(p->str[0]))
			check_map(game, p->str);
		else if (p->str[0] != '\0')
			exit_msg("CUB file misconfiguration !!");
		free(p->str);
	}
}

static int		data_exists(t_game *game)
{
	if (!game->map.grid)
		exit_msg("MAP doesn't exist");
	if (!game->t[0].img || !game->t[1].img || !game->t[2].img\
		|| !game->t[3].img)
		exit_msg("Wall textures Problems");
	return (1);
}

t_game			init_game(char *file)
{
	t_game		game;
	t_parser	p;

	if ((p.fd = open(file, O_RDONLY)) < 0)
		exit_msg("File Not Working !!");
	full_init(&game);
	loop_file(&p, &game);
	if (data_exists(&game))
	{
		game.map.height = ft_strlen(game.map.grid) / game.map.width;
		verify_map(&game);
		verify_sprites(&game, &p);
		set_cam(&game);
		get_all_sprites(&game);
		close(p.fd);
	}
	game.chacha = 0;
	game.kaka = 0;
	game.kaco = 0;
	game.l_up = 0;
	init_music(&game);
	init_gun(&game);
	return (game);
}
