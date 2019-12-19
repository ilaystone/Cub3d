/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhadem <ikhadem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 20:02:50 by ikhadem           #+#    #+#             */
/*   Updated: 2019/12/18 22:12:48 by ikhadem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"
#include <string.h>
#include <stdio.h>

int	key_press(int key, t_map *m)
{
	if(key == K_ESC)
		exit(0);
	if (key == K_UP)
		m->player.walk_direction = 1;
	if (key == K_DOWN)
		m->player.walk_direction = -1;
	if (key == K_LEFT)
		m->player.turn_direction = -1;
	if (key == K_RIGHT)
		m->player.turn_direction = 1;
	return (1);
}

int	key_release(int key, t_map *m)
{
	if (key == K_UP)
		m->player.walk_direction = 0;
	if (key == K_DOWN)
		m->player.walk_direction = 0;
	if (key == K_LEFT)
		m->player.turn_direction = 0;
	if (key == K_RIGHT)
		m->player.turn_direction = 0;
	return (1);
}

void create_new_map(t_map *map)
{
	int			j;

	j	 = 0;
	while (map->map[j] != '\0')
	{
		add_rect(new_rect(32, 32, new_point((j % map->width) * 32, (j / map->width) * 32), new_color(0, 0, 0)));
		if (map->map[j] != '1')
		{
			add_rect(new_rect(32, 32, new_point((j % map->width) * 32, (j / map->width) * 32), new_color(255, 255, 255)));
		}
		if (map->map[j] == 'p')
		{
			map->map[j] = '0';
			map->player.pos.x = (j % map->width) * 32 + 16;
			map->player.pos.y = (j / map->width) * 32 + 16;
		}
		j++;
	}
	j = 32;
	while (j < 29 * 32)
	{
		add_line(new_line(new_point(j, 0), new_point(j, 14 * 32), new_color(0, 0, 0)));
		j += 32;
	}
	j = 32;
	while (j < 14 * 32)
	{
		add_line(new_line(new_point(0, j ), new_point(32 * 29, j), new_color(0, 0, 0)));
		j += 32;
	}
}

double normalize_angle(double a)
{
	if (a > 2 * M_PI)
		return (a - 2 * M_PI);
	else if (a <= 0)
		return (a + 2 * M_PI);
	return (a);
}

int		is_wall(t_map *map, int x, int y)
{
	int j;
	int sx;
	int sy;

	sx = (map->player.pos.x + x) / 32;
	sy = ((map->player.pos.y + y) / 32);
	j = sy * map->width + sx;
	if (map->map[j] != '0')
		return (1);
	return (0);
}

void update_player_pos(t_map *map)
{
	double x;
	double y;
	double move_step;

	map->player.rotation_angle += map->player.rotation_speed * map->player.turn_direction;
	map->player.rotation_angle = normalize_angle(map->player.rotation_angle);
	move_step = map->player.move_speed * map->player.walk_direction;
	x = cos(map->player.rotation_angle) * move_step;
	y = sin(map->player.rotation_angle) * move_step;
	if (!is_wall(map, floor(x), floor(y)))
	{
		map->player.pos.x += round(x);
		map->player.pos.y += round(y);
	}
}

void cast_one_ray(t_map *map, double angle)
{
	add_line(new_line(new_point(map->player.pos.x, map->player.pos.y),
						new_point(round(map->player.pos.x + cos(angle) * 28 * 3), round(map->player.pos.y + sin(angle) * 28 * 3)),
						new_color(250, 0, 0)));
}

void cast_rays(t_map *map)
{
	int i;
	double angle;
	double step;
	double num_rays;

	i = 0;
	num_rays = map->width;
	step = map->player.FOV / num_rays;
	angle = map->player.rotation_angle - (map->player.FOV / 2);
	while (i < map->width)
	{
		cast_one_ray(map, angle);
		angle += step;
		i++;
	}
}

int update(t_map *map)
{
	create_new_map(map);
	update_player_pos(map);
	//add_rect(new_rect(32, 32, new_point(map->player.pos.x - 16, map->player.pos.y - 16), new_color(0, 0, 250)));
	add_line(new_line(new_point(map->player.pos.x, map->player.pos.y ),
						new_point((int)(map->player.pos.x + cos(map->player.rotation_angle) * 32 * 3), (int)(map->player.pos.y + sin(map->player.rotation_angle) * 32 * 3)),
						new_color(0, 0, 250)));
	cast_rays(map);
	mlx_put_image_to_window(g_win.ptr, g_win.win, g_win.img_ptr, 0, 0);
	return (0);
}

int		main()
{
	t_map map;

	map.width = 29;
	map.height = 14;
	map.map = strdup("111111111111111111111111111111p00000000110000000000000000110110000011100000020000010001100100000000000000000000100011011000001110000000000001000110000000001100000111011110001111101111111110111000000100011111011111111101110101001000111000000110101011100000010001100020000000000011000000100011000000000000000110101001000111000000110101011111011110N011111011111110101111101111000111111111111111111111111111111");
	map.player.radius = 3;
	map.player.FOV = 60 * (M_PI / 180);
	map.player.turn_direction = 0;
	map.player.walk_direction = 0;
	map.player.rotation_angle = M_PI / 2;
	map.player.move_speed = 2.0;
	map.player.rotation_speed = 5 * M_PI / 180;
	canvas_init(29 * 32, 14 * 32, "CUB3D");
	mlx_hook(g_win.win, 2, 0, key_press, &map);
	mlx_hook(g_win.win, 3, 0, key_release, &map);
	mlx_loop_hook(g_win.ptr, update, &map);
	mlx_loop(g_win.ptr);
	return (0);
}