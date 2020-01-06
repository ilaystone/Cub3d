/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhadem <ikhadem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 21:39:25 by ikhadem           #+#    #+#             */
/*   Updated: 2020/01/04 00:30:46 by ikhadem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		set_map(t_game *game, char *str)
{
	char	*tmp;

	tmp = game->map.grid;
	game->map.grid = ft_strjoin(game->map.grid, str);
	if (tmp != NULL)
		free(tmp);
}

void		verify_map(t_game *game)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < game->map.width)
		if (game->map.grid[i++] != '1')
			exit_msg("map should be delimited by '1'(Walls) !!");
	while (j < game->map.height - 2)
	{
		if (game->map.grid[i] != '1')
			exit_msg("map should be delimited by '1'(Walls) !!");
		i += (game->map.width - 1);
		if (game->map.grid[i] != '1')
			exit_msg("map should be delimited by '1'(Walls) !!");
		i++;
		j++;
	}
	while (i < game->map.width * game->map.height)
		if (game->map.grid[i++] != '1')
			exit_msg("map should be delimited by '1'(Walls) !!");
}

void		verify_sprites(t_game *game, t_parser *p)
{
	char	id;
	int		count;
	int		i;

	id = '2';
	count = 0;
	i = 0;
	while (game->map.grid[i] != '\0')
	{
		if (game->map.grid[i] == id)
		{
			id++;
			count++;
		}
		i++;
	}
	if (p->num_of_sprites_id != count)
	{
		printf("%d %d", p->num_of_sprites_id, count);
		exit_msg("number of sprites id's and textures mismatch");
	}
}
