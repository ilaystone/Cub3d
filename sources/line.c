/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhadem <ikhadem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 14:53:23 by ikhadem           #+#    #+#             */
/*   Updated: 2019/12/24 18:21:12 by ikhadem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_line		new_line(t_vec2 p1, t_vec2 p2, t_color c)
{
	t_line	l;

	l.p1 = p1;
	l.p2 = p2;
	l.c = c;
	return (l);
}

void	add_line(t_line l)
{
	int min;
	int max;
	int i;

	min = l.p1.y;
	max = l.p2.y;
	if (l.p1.y > l.p2.y)
	{
		min = l.p2.y;
		max = l.p1.y;
	}
	i = min;
	while (i < max)
	{
		add_vec2(new_vec2(l.p1.x, i), l.c);
		i++;
	}
}

void		draw_line(t_line l)
{
	add_line(l);
	mlx_put_image_to_window(g_win.ptr, g_win.win, g_win.img_ptr, 0, 0);
}