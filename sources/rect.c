/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rect.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhadem <ikhadem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 16:01:01 by ikhadem           #+#    #+#             */
/*   Updated: 2019/12/15 18:39:45 by ikhadem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/cub3d.h"

t_rect		new_rect(int w, int h, t_point p)
{
	t_rect r;
	r.w = w;
	r.h = h;
	r.pos = p;
	return (r);
}

void		add_rect(t_rect r)
{
	int		y;

	y = r.pos.y;
	while (y <= r.pos.y + r.h)
	{
		add_line(new_line(new_point(r.pos.x, y),
						new_point(r.pos.x + r.w, y)),
						new_point(0, 0), new_point(0, 0));
		y++;
	}
}

void		draw_rect(t_rect r)
{
	add_rect(r);
	mlx_put_image_to_window(g_win.ptr, g_win.win, g_win.img_ptr, 0, 0);
}