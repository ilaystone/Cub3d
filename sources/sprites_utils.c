/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhadem <ikhadem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 21:50:19 by ikhadem           #+#    #+#             */
/*   Updated: 2019/12/31 03:16:54 by ikhadem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_sprite	new_sprite(t_vec2 pos, char id)
{
	t_sprite	new;

	new.pos = pos;
	new.id = id;
	return (new);
}

void		get_all_sprites(t_game *g)
{
	int		i;

	i = 0;
	while (g->map.grid[i] != '\0')
	{
		if (g->map.grid[i] != '1' && g->map.grid[i] != '0' && g->map.grid[i] != 'N')
		{
			g->slst[g->spcount] = new_sprite(new_vec2(i % g->map.width + 0.5,\
				i / g->map.width + 0.5), g->map.grid[i]);
			g->spcount++;
		}
		i++;
	}
}

void		ft_swap(int *a, int *b)
{
	int c;

	c = *a;
	*a = *b;
	*b = c;
}

void		sort_sprites(t_game *g)
{
	int i;
	int j;

	i = 0;
	while (i  < g->spcount)
	{
		j = i;
		while (j < g->spcount)
		{
			if (ceil(g->sprite_distance[i] )< ceil(g->sprite_distance[j]))
				ft_swap(&g->sprite_ordre[i], &g->sprite_ordre[j]);
			j++;
		}
		i++;
	}
}