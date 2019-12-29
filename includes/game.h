/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhadem <ikhadem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 03:44:15 by ikhadem           #+#    #+#             */
/*   Updated: 2019/12/29 11:50:28 by ikhadem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "cub3d.h"

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
	int			tex_num;
}				t_cam;

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
typedef struct	s_game
{
	t_map		map;
	t_cam		cam;
	t_tex		t[6];
	t_fc		dfc;
}				t_game;

void			cast_rays(t_game *g);
t_tex			get_texture(char *file_name);
void			draw_walls(t_game *g);
void			cast_floor(t_game *g);

#endif
