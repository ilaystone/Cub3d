/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhadem <ikhadem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 18:31:11 by ikhadem           #+#    #+#             */
/*   Updated: 2019/12/31 02:50:41 by ikhadem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void		draw_sprites(t_game *g)
{
	t_draw v;

	for (int i = 0; i < g->spcount; i++)
	{
		g->sprite_ordre[i] = i;
		g->sprite_distance[i] = ((g->cam.posx - g->slst[i].pos.x) *\
			(g->cam.posx - g->slst[i].pos.x) + (g->cam.posy - g->slst[i].pos.y)\
			* (g->cam.posy - g->slst[i].pos.y));
	}
	sort_sprites(g);
	for (int i = 0; i < g->spcount; i++)
	{
		double spriteX = g->slst[g->sprite_ordre[i]].pos.x - g->cam.posx;
		double spritey = g->slst[g->sprite_ordre[i]].pos.y - g->cam.posy;
		double invDet = 1.0 / (g->cam.planex * g->cam.diry - g->cam.dirx * g->cam.planey);
		double transformx = invDet * (g->cam.diry * spriteX - g->cam.dirx * spritey);
		double transformy = invDet * (-g->cam.planey * spriteX + g->cam.planex * spritey);
		int spritescreenx = (int)((g_win.resolution.x / 2) * (1 + transformx / transformy));
		int sprite_height = abs((int)(g_win.resolution.y / transformy));
		int	draw_starty = -sprite_height / 2 + g_win.resolution.y / 2;
		if (draw_starty < 0)
			draw_starty = 0;
		int draw_endy = sprite_height / 2 + g_win.resolution.y / 2;
		if (draw_endy >= g_win.resolution.y)
			draw_endy = g_win.resolution.y - 1;
		int sprite_width = abs((int)(g_win.resolution.y / transformy));
		int draw_startx = -sprite_width / 2 + spritescreenx;
		int draw_endx = sprite_width / 2 + spritescreenx;
		if (draw_startx < 0)
			draw_startx = 0;
		if (draw_endx >= g_win.resolution.x)
			draw_endx = g_win.resolution.x - 1;
		for (int stripe = draw_startx; stripe < draw_endx; stripe++)
		{
			v.texx = (int)(256 * (stripe - (-sprite_width / 2 + spritescreenx))) * g->t[6].w / sprite_width / 256;
			if (transformy > 0 && stripe > 0 && stripe < g_win.resolution.x && transformy < g->zbuff[stripe])
				for (int y = draw_starty; y < draw_endy; y++)
				{
					v.d = y * 256 - g_win.resolution.y * 128 + sprite_height * 128;
					v.texy = ((v.d * g->t[6].h) / sprite_height) / 256;
					v.pos = g->t[6].w * 4 * v.texy + 4 * v.texx;
					v.pos2 = stripe * 4 + g_win.resolution.x * 4 * y;
					if (g->t[6].img_ptr[v.pos] != (char)0 &&
						g->t[6].img_ptr[v.pos + 1] != (char)0 &&
						g->t[6].img_ptr[v.pos + 2] != (char)0)
					{
						g_win.img_data[v.pos2] = g->t[6].img_ptr[v.pos];
						g_win.img_data[v.pos2 + 1] = g->t[6].img_ptr[v.pos + 1];
						g_win.img_data[v.pos2 + 2] = g->t[6].img_ptr[v.pos + 2];
					}
				}
		}
	}
}