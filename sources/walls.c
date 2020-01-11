/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhadem <ikhadem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 03:49:07 by ikhadem           #+#    #+#             */
/*   Updated: 2020/01/08 05:39:43 by ikhadem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_tex		get_texture(char *file_name)
{
	t_tex	data;

	data.img = mlx_png_file_to_image(g_win.ptr, file_name, &data.w, &data.h);
	if (!data.img)
	{
		ft_puterror("please verify the path !!\n");
		exit(-1);
	}
	data.img_ptr = mlx_get_data_addr(data.img, &data.bpp, &data.size_line,\
						&data.endian);
	return (data);
}

int			get_side(t_game *g)
{
	int		j;
	int		a;

	j = g->map.width * g->cam.mapy + g->cam.mapx;
	if (g->cam.side == 0 && g->cam.raydirx > 0)
		a = NORTH;
	if (g->cam.side == 0 && g->cam.raydirx < 0)
		a = SOUTH;
	if (g->cam.side == 1 && g->cam.raydiry > 0)
		a = EAST;
	if (g->cam.side == 1 && g->cam.raydiry < 0)
		a = WEST;
	return (a);
}

static void	draw_line_stripe(t_game *g, t_draw *v)
{
	while (v->y < g->cam.drawend)
	{
		v->d = (v->y - g->l_up) * 256 - g_win.resolution.y * 128 +\
			g->cam.lineheight * 128;
		v->texy = ((v->d * g->t[v->a].h) / g->cam.lineheight) / 256;
		v->pos = g->t[v->a].h * v->texy * 4 + g->t[v->a].tex_x * 4;
		v->pos2 = g->cam.id * 4 + g_win.resolution.x * 4 * v->y;
		g_win.img_data[v->pos2] = get_shadow(g->cam.perpewalldist,\
			g->t[v->a].img_ptr[v->pos]);
		g_win.img_data[v->pos2 + 1] = get_shadow(g->cam.perpewalldist,\
			g->t[v->a].img_ptr[v->pos + 1]);
		g_win.img_data[v->pos2 + 2] = get_shadow(g->cam.perpewalldist,\
			g->t[v->a].img_ptr[v->pos + 2]);
		v->y++;
	}
}

void		draw_walls(t_game *g)
{
	t_draw	v;

	v.a = get_side(g);
	v.y = g->cam.drawstart;
	if (g->cam.side == 0)
		g->t[v.a].wall_x = g->cam.posy + g->cam.perpewalldist * g->cam.raydiry;
	else
		g->t[v.a].wall_x = g->cam.posx + g->cam.perpewalldist * g->cam.raydirx;
	g->t[v.a].wall_x -= floor(g->t[v.a].wall_x);
	g->t[v.a].tex_x = (int)(g->t[v.a].wall_x * (double)(g->t[v.a].w));
	if (g->cam.side == 0 && g->cam.raydirx > 0)
		g->t[v.a].tex_x = g->t[v.a].w - g->t[v.a].tex_x - 1;
	if (g->cam.side == 1 && g->cam.raydiry < 0)
		g->t[v.a].tex_x = g->t[v.a].w - g->t[v.a].tex_x - 1;
	draw_line_stripe(g, &v);
}
