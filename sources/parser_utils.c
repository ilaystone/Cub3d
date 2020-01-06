/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhadem <ikhadem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/01 18:18:25 by ikhadem           #+#    #+#             */
/*   Updated: 2020/01/05 18:19:07 by ikhadem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_vec2		init_resolution(char *str)
{
	int		width;
	int		height;

	width = 0;
	height = 0;
	str++;
	while (ft_isspace(*str))
		str++;
	width = ft_atoi(str);
	while (ft_isdigit(*str))
		str++;
	height = ft_atoi(str);
	if (width > MAX_WIDTH || width < MIN_WIDTH)
		exit_msg("resolution width sould be between 2560 and 340!");
	if (height > MAX_HEIGHT || height < MIN_HEIGHT)
		exit_msg("resolution height sould be between 1440 and 200");
	return (new_vec2(width, height));
}

void		init_wall_textures(t_game *game, char *str, char *d)
{
	int		side;

	if (*d == 1)
	{
		ft_puterror("duplicate indicator :\n");
		ft_putchar(str[0]);
		ft_putchar(str[1]);
		exit(-1);
	}
	else
	{
		*d = 1;
		if (str[0] == 'N')
			side = NORTH;
		if (str[0] == 'S')
			side = SOUTH;
		if (str[0] == 'W')
			side = WEST;
		if (str[0] == 'E')
			side = EAST;
		str += 2;
		while (ft_isspace(*str))
			str++;
	}
	game->t[side] = get_texture(str);
}

void		init_sprites(t_game *game, char *str, int *num)
{
	int		tex_num;

	tex_num = 0;
	*num += 1;
	if (str[1] == ' ')
		tex_num = 0;
	else if (ft_isdigit(str[1]))
		tex_num = ft_atoi(str + 1);
	str += 2;
	while (ft_isspace(*str))
		str++;
	check_sprite(game, str, tex_num);
}

void		init_floor_ceil(t_game *game, char *str, char *set)
{
	int		id;

	id = (str[0] == 'F') ? 0 : 1;
	if (id == 0 && set[4] != '1')
		set[4] = '1';
	else if (id == 1 && set[5] != '1')
		set[5] = '1';
	else
		exit_msg("duplicate param for ceil / floor");
	if (str[1] == 'T')
	{
		str += 2;
		while (ft_isspace(*str))
			str++;
		check_fc_texture(game, str, id);
	}
	else if (str[1] == ' ')
	{
		str += 2;
		while (ft_isspace(*str))
			str++;
		check_fc_rgb(game, str, id);
	}
	else
		exit_msg("Floor indicator must be :\n-RGB form F\n-Texture form FT");
}

void		check_map(t_game *game, char *str)
{
	int			i;
	int			size;

	i = 0;
	size = ft_strlen(str);
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]) && str[i] != 'N' && str[i] != 'S'\
			&& str[i] != 'E' && str[i] != 'W')
		{
			ft_puterror("map should contain digits only and ");
			ft_puterror("one player directional 'N' 'W' 'E' 'S'\n");
			exit(-1);
		}
		i++;
	}
	game->map.width = (game->map.width != 0) ? game->map.width : size;
	if (size != game->map.width)
		exit_msg("Verify that the map is a sqaured matrix form");
	set_map(game, str);
}
