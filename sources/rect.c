/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rect.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhadem <ikhadem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 16:01:01 by ikhadem           #+#    #+#             */
/*   Updated: 2019/12/16 03:14:05 by ikhadem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/cub3d.h"

t_rect		new_rect(int w, int h, t_point p, t_color c)
{
	t_rect r;
	r.w = w;
	r.h = h;
	r.pos = p;
	r.c = c;
	return (r);
}

void		add_rect(t_rect r)
{
	int		i;
	int		j;

	j = r.pos.y;
	while (j <= r.pos.y + r.h)
	{
		i = r.pos.x;
		while (i <= r.pos.x + r.w)
		{
			add_point(new_point(i, j), r.c);
			i++;
		}
		j++;
	}
}

void		draw_rect(t_rect r)
{
	add_rect(r);
	mlx_put_image_to_window(g_win.ptr, g_win.win, g_win.img_ptr, 0, 0);
}