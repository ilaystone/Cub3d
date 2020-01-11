/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhadem <ikhadem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 18:31:11 by ikhadem           #+#    #+#             */
/*   Updated: 2020/01/08 21:43:27 by ikhadem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		get_distances(t_game *g)
{
	int			i;

	i = 0;
	while (i < g->spcount)
	{
		g->sprite_ordre[i] = i;
		g->sprite_distance[i] = ((g->cam.posx - g->slst[i].pos.x) *\
		(g->cam.posx - g->slst[i].pos.x) + (g->cam.posy - g->slst[i].pos.y)\
			* (g->cam.posy - g->slst[i].pos.y));
		i++;
	}
}

static void		calc_position(t_game *g, t_sp_draw *d)
{
	d->spritex = g->slst[g->sprite_ordre[d->id]].pos.x - g->cam.posx;
	d->spritey = g->slst[g->sprite_ordre[d->id]].pos.y - g->cam.posy;
	d->invdet = 1.0 / (g->cam.planex * g->cam.diry - g->cam.dirx *\
		g->cam.planey);
	d->transformx = d->invdet * (g->cam.diry * d->spritex - g->cam.dirx *\
		d->spritey);
	d->transformy = d->invdet * (-g->cam.planey * d->spritex + g->cam.planex *\
		d->spritey);
	d->spritescreenx = (int)((g_win.resolution.x / 2) * (1 + d->transformx /\
		d->transformy));
	d->sprite_height = abs((int)(g_win.resolution.y / d->transformy));
	d->draw_starty = -d->sprite_height / 2 + g_win.resolution.y / 2 + g->l_up;
	if (d->draw_starty < 0)
		d->draw_starty = 0;
	d->draw_endy = d->sprite_height / 2 + g_win.resolution.y / 2 + g->l_up;
	if (d->draw_endy >= g_win.resolution.y)
		d->draw_endy = g_win.resolution.y - 1;
	d->sprite_width = abs((int)(g_win.resolution.y / d->transformy));
	d->draw_startx = -d->sprite_width / 2 + d->spritescreenx;
	d->draw_endx = d->sprite_width / 2 + d->spritescreenx;
	if (d->draw_startx < 0)
		d->draw_startx = 0;
	if (d->draw_endx >= g_win.resolution.x)
		d->draw_endx = g_win.resolution.x - 1;
}

static void		sprite_rendering2(t_game *g, t_draw *v, t_sp_draw *d, int s)
{
	int			pos;
	int			y;

	y = d->draw_starty;
	pos = g->slst[g->sprite_ordre[d->id]].id - 48;
	while (y < d->draw_endy)
	{
		v->d = (y - g->l_up) * 256 - g_win.resolution.y * 128 + d->sprite_height *\
			128;
		v->texy = ((v->d * g->t[pos + 2].h) / d->sprite_height) / 256;
		v->pos = g->t[pos + 2].w * 4 * v->texy + 4 * v->texx;
		v->pos2 = s * 4 + g_win.resolution.x * 4 * y;
		if (g->t[pos + 2].img_ptr[v->pos] != (char)0 &&
			g->t[pos + 2].img_ptr[v->pos + 1] != (char)0 &&
			g->t[pos + 2].img_ptr[v->pos + 2] != (char)0)
		{
			g_win.img_data[v->pos2] = get_shadow(g->sprite_distance[d->id],\
				g->t[pos + 2].img_ptr[v->pos]);
			g_win.img_data[v->pos2 + 1] = get_shadow(g->sprite_distance[d->id],\
				g->t[pos + 2].img_ptr[v->pos + 1]);
			g_win.img_data[v->pos2 + 2] = get_shadow(g->sprite_distance[d->id],\
				g->t[pos + 2].img_ptr[v->pos + 2]);
		}
		y++;
	}
}

static void		sprite_rendering(t_game *g, t_draw *v, t_sp_draw *d)
{
	int			pos;
	int			stripe;

	stripe = d->draw_startx;
	pos = g->slst[g->sprite_ordre[d->id]].id - 48;
	while (stripe < d->draw_endx)
	{
		v->texx = (int)(256 * (stripe - (-d->sprite_width / 2 +\
			d->spritescreenx))) * g->t[pos + 2].w / d->sprite_width / 256;
		if (d->transformy > 0 && stripe > 0 && stripe < g_win.resolution.x\
			&& d->transformy < g->zbuff[stripe])
			sprite_rendering2(g, v, d, stripe);
		stripe++;
	}
}

void			draw_sprites(t_game *g)
{
	t_draw		v;
	t_sp_draw	d;
	int			i;

	i = 0;
	get_distances(g);
	sort_sprites(g);
	while (i < g->spcount)
	{
		d.id = i;
		calc_position(g, &d);
		sprite_rendering(g, &v, &d);
		i++;
	}
}
