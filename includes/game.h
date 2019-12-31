/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhadem <ikhadem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 03:44:15 by ikhadem           #+#    #+#             */
/*   Updated: 2019/12/30 22:41:03 by ikhadem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "cub3d.h"

# define SPRITENUM 1000
# define MAX_WIDTH 2560
# define MAX_HEIGHT 1440

typedef struct	s_map
{
	int			width;
	int			height;
	char		*grid;
}				t_map;

typedef struct	s_cam
{
	double		posx;
	double		posy;
	double		dirx;
	double		diry;
	double		planex;
	double		planey;
	double		camerax;
	double		raydirx;
	double		raydiry;
	int			mapx;
	int			mapy;
	double		sidedistx;
	double		sidedisty;
	double		deltadistx;
	double		deltadisty;
	double		perpewalldist;
	int			stepx;
	int			stepy;
	int			hit;
	int			side;
	int			lineheight;
	int			drawstart;
	int			drawend;
	int			id;
	int			move;
	int			turn;
}				t_cam;

typedef struct	s_draw
{
	int			a;
	int			d;
	int			y;
	int			texy;
	int			texx;
	int			pos;
	int			pos2;
}				t_draw;
typedef struct	s_tex
{
	int			bpp;
	int			size_line;
	int			endian;
	int			w;
	int			h;
	void		*img;
	char		*img_ptr;
	double		wall_x;
	int			tex_x;
	double		step;
	double		tex_pos;
}				t_tex;

typedef struct	s_fc
{
	double		fxwall;
	double		fywall;
	double		distwall;
	double		distplayer;
	double		currentdist;
	double		weight;
	double		fx;
	double		fy;
	int			texx;
	int			texy;
}				t_fc;

typedef struct  s_sprite
{
	t_vec2			pos;
    char         	id;
}               t_sprite;

typedef struct	s_game
{
	t_map		map;
	t_cam		cam;
	t_tex		t[7];
	t_fc		dfc;
	t_sprite	slst[SPRITENUM];
	int			spcount;
	int			sprite_ordre[SPRITENUM];
	double		zbuff[MAX_WIDTH];
	double		sprite_distance[SPRITENUM];
}				t_game;


void			cast_rays(t_game *g);
t_tex			get_texture(char *file_name);
void			draw_walls(t_game *g);
void			cast_floor(t_game *g);
void			draw_sprites(t_game *g);
t_sprite		new_sprite(t_vec2 pos, char id);
void			get_all_sprites(t_game *g);
void			sort_sprites(t_game *g);

#endif
