/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhadem <ikhadem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 20:02:50 by ikhadem           #+#    #+#             */
/*   Updated: 2019/12/16 04:45:48 by ikhadem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

int		main()
{
	t_map		map;
	t_player	player;
	int		j;

	j = 0;
	map.width = 29;
	map.height = 14;
	map.map = ft_strdup("111111111111111111111111111111p00000000110000000000000000110110000011100000020000010001100100000000000000000000100011011000001110000000000001000110000000001100000111011110001111101111111110111000000100011111011111111101110101001000111000000110101011100000010001100020000000000011000000100011000000000000000110101001000111000000110101011111011110N011111011111110101111101111000111111111111111111111111111111");
	canvas_init(29 * 32, 14 * 32, "CUB3D");
	while (map.map[j] != '\0')
	{
		if (map.map[j] != '1')
		{
			add_rect(new_rect(32, 32, new_point((j % map.width) * 32, (j / map.width) * 32), new_color(255, 255, 255)));
		}
		if (map.map[j] == 'p')
		{
			player.pos.x = (j % map.width) * 32;
			player.pos.y = (j / map.width) * 32;
		}
		j++;
	}
	j = 0;
	while (j < 29 * 32)
	{
		add_line(new_line(new_point(j, 0), new_point(j, 14 * 32),
				new_color(0, 0, 0)), new_point(0, 0), new_point(0, 0));
		j += 32;
	}
	j = 0;
	while (j < 14 * 32)
	{
		add_line(new_line(new_point(0, j ), new_point(32 * 29, j),
				new_color(0, 0, 0)), new_point(0, 0), new_point(0, 0));
		j += 32;
	}
	add_rect(new_rect(32, 32, player.pos, new_color(0, 0, 250)));
	mlx_put_image_to_window(g_win.ptr, g_win.win, g_win.img_ptr, 0, 0);
	mlx_loop(g_win.ptr);
	return (0);
}
