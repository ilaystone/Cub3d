/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhadem <ikhadem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 01:11:18 by ikhadem           #+#    #+#             */
/*   Updated: 2020/01/06 02:36:17 by ikhadem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	set_north(t_game *game, int *i, int id)
{
	*i += 1;
	game->map.grid[id] = '0';
	game->cam.posx = (int)(id % game->map.width);
	game->cam.posy = (int)(id / game->map.width);
	game->cam.dirx = 0;
	game->cam.diry = -1;
	game->cam.planex = -0.66;
	game->cam.planey = 0;
}

static void	set_south(t_game *game, int *i, int id)
{
	*i += 1;
	game->map.grid[id] = '0';
	game->cam.posx = (int)(id % game->map.width);
	game->cam.posy = (int)(id / game->map.width);
	game->cam.dirx = 0;
	game->cam.diry = 1;
	game->cam.planex = 0.66;
	game->cam.planey = 0;
}

static void	set_west(t_game *game, int *i, int id)
{
	*i += 1;
	game->map.grid[id] = '0';
	game->cam.posx = (int)(id % game->map.width);
	game->cam.posy = (int)(id / game->map.width);
	game->cam.dirx = -1;
	game->cam.diry = 0;
	game->cam.planex = 0;
	game->cam.planey = 0.66;
}

static void	set_east(t_game *game, int *i, int id)
{
	*i += 1;
	game->map.grid[id] = '0';
	game->cam.posx = (int)(id % game->map.width);
	game->cam.posy = (int)(id / game->map.width);
	game->cam.dirx = 1;
	game->cam.diry = 0;
	game->cam.planex = 0;
	game->cam.planey = -0.66;
}

void		set_cam(t_game *game)
{
	int		i;
	int		player_set;

	i = 0;
	player_set = 0;
	while (game->map.grid[i] != '\0')
	{
		if (game->map.grid[i] == 'N')
			set_north(game, &player_set, i);
		else if (game->map.grid[i] == 'S')
			set_south(game, &player_set, i);
		else if (game->map.grid[i] == 'W')
			set_west(game, &player_set, i);
		else if (game->map.grid[i] == 'E')
			set_east(game, &player_set, i);
		i++;
	}
	if (player_set != 1)
		exit_msg("PLayer is duplicated or not found!!");
}
