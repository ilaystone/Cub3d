/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhadem <ikhadem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 01:08:25 by ikhadem           #+#    #+#             */
/*   Updated: 2020/01/03 02:01:44 by ikhadem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void		exit_msg(char *msg)
{
	ft_puterror(msg);
	ft_putchar('\n');
	exit(-1);
}

void		check_resolution(char *str)
{
	t_vec2		res;
	if (str[0] == 'R')
	{
		res = init_resolution(str);
		canvas_init(res, TITLE);
	}
	else
		exit_msg("Resolution must be set at the TOP of File");
}

void			check_sprite(t_game *game, char *str, int tex_num)
{
	if (game->t[4 + tex_num].img != NULL)
	{
		ft_puterror("duplicate indicator for:\n sprite at number : ");
		ft_putnbr(tex_num);
		exit(-1);
	}
	else
	{
		game->t[4 + tex_num] = get_texture(str);
	}
}

void			check_fc_rgb(t_game *game, char *str, int id)
{
	game->is_fc_rgb = 1;
	int r;
	int g;
	int b;
	if (ft_isdigit(str[0]))
	{
		game->color[id] = get_color_from_string(str);
	}
	else
		exit_msg("Wrong RGB format for F / C");
}

void			check_fc_texture(t_game *game, char *str, int id)
{
	game->is_fc_rgb = 0;
	if (game->t[28 + id].img != NULL)
	{
		ft_puterror("duplicate indicator for:\n sprite at : ");
		ft_puterror(id == 0 ? "FT" : "CT");
		exit(-1);
	}
	else
	{
		game->t[28 + id] = get_texture(str);
	}
}
