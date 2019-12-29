/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhadem <ikhadem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 03:49:07 by ikhadem           #+#    #+#             */
/*   Updated: 2019/12/29 11:46:26 by ikhadem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"


t_tex	get_texture(char *file_name)
{
	t_tex	data;

	data.img = mlx_png_file_to_image(g_win.ptr, file_name, &data.w, &data.h);
	data.img_ptr = mlx_get_data_addr(data.img, &data.bpp, &data.size_line,\
						&data.endian);
	return (data);
}

int		get_side(t_game *g)
{
	int j;
	int a;

	j = g->map.width * g->cam.mapy + g->cam.mapx;
	if (g->cam.side == 0 && g->cam.raydirx > 0)
		a = 0; // north
	if (g->cam.side == 0 && g->cam.raydirx < 0)
		a = 1; // south
	if (g->cam.side == 1 && g->cam.raydiry > 0)
		a = 2; // east
	if (g->cam.side == 1 && g->cam.raydiry < 0)
		a = 3; // west
	return (a);
}

void	draw_walls(t_game *g)
{
	int		a;

	a = get_side(g);
	if (g->cam.side == 0)
		g->t[a].wall_x = g->cam.posy + g->cam.perpewalldist * g->cam.raydiry;
	else
		g->t[a].wall_x = g->cam.posx + g->cam.perpewalldist * g->cam.raydirx;
	g->t[a].wall_x -= floor(g->t[a].wall_x);
	g->t[a].tex_x = (int)(g->t[a].wall_x * (double)(g->t[a].w));
	if (g->cam.side == 0 && g->cam.raydirx > 0)
		g->t[a].tex_x = g->t[a].w - g->t[a].tex_x - 1;
	if (g->cam.side == 1 && g->cam.raydiry < 0)
		g->t[a].tex_x = g->t[a].w - g->t[a].tex_x - 1;
	for (int y = g->cam.drawstart; y < g->cam.drawend; y++)
	{
		int d = y * 256 - g_win.resolution.y * 128 + g->cam.lineheight * 128;
		int texy = ((d * g->t[a].h) / g->cam.lineheight) / 256;
		int pos = g->t[a].h * texy * 4 +  g->t[a].tex_x  * 4;
		int pos2 = g->cam.id * 4 + g_win.resolution.x * 4 * y;
		g_win.img_data[pos2] = g->t[a].img_ptr[pos];
		g_win.img_data[pos2 + 1] = g->t[a].img_ptr[pos + 1];
		g_win.img_data[pos2 + 2] = g->t[a].img_ptr[pos + 2];
	}
}