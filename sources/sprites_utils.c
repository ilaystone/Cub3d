/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhadem <ikhadem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 21:50:19 by ikhadem           #+#    #+#             */
/*   Updated: 2020/01/04 00:31:02 by ikhadem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		ft_swap_int(int *a, int *b)
{
	int			c;

	c = *a;
	*a = *b;
	*b = c;
}

static void		ft_swap_double(double *a, double *b)
{
	double		c;

	c = *a;
	*a = *b;
	*b = c;
}

t_sprite		new_sprite(t_vec2 pos, char id)
{
	t_sprite	new;

	new.pos = pos;
	new.id = id;
	return (new);
}

void			get_all_sprites(t_game *g)
{
	int			i;

	i = 0;
	while (g->map.grid[i] != '\0')
	{
		if (g->map.grid[i] != '1' && g->map.grid[i] != '0')
		{
			g->slst[g->spcount] = new_sprite(new_vec2(i % g->map.width + 0.5,\
				i / g->map.width + 0.5), g->map.grid[i]);
			g->spcount++;
		}
		i++;
	}
}

void			sort_sprites(t_game *g)
{
	int			i;
	int			j;

	i = 0;
	while (i < g->spcount)
	{
		j = i;
		while (j < g->spcount)
		{
			if (ceil(g->sprite_distance[i]) < ceil(g->sprite_distance[j]))
			{
				ft_swap_int(&g->sprite_ordre[i], &g->sprite_ordre[j]);
				ft_swap_double(&g->sprite_distance[i], &g->sprite_distance[j]);
			}
			j++;
		}
		i++;
	}
}
