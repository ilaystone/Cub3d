/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhadem <ikhadem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 03:44:15 by ikhadem           #+#    #+#             */
/*   Updated: 2020/01/09 03:34:22 by ikhadem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "cub3d.h"

# define SPRITENUM 1000
# define MAX_WIDTH 2560
# define MAX_HEIGHT 1440
# define MIN_WIDTH 340
# define MIN_HEIGHT 200
# define TITLE "cub3d"

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
	int			move_h;
	double		turn;
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

typedef struct	s_sp_draw
{
	double		spritex;
	double		spritey;
	double		invdet;
	double		transformx;
	double		transformy;
	int			spritescreenx;
	int			sprite_height;
	int			sprite_width;
	int			draw_startx;
	int			draw_endx;
	int			draw_starty;
	int			draw_endy;
	int			stripe;
	int			id;
}				t_sp_draw;

typedef struct	s_sprite
{
	t_vec2		pos;
	char		id;
}				t_sprite;

typedef struct	s_game
{
	t_map		map;
	t_cam		cam;
	t_tex		t[20];
	t_tex		w[6];
	t_fc		dfc;
	t_sprite	slst[SPRITENUM];
	int			is_fc_rgb;
	t_color		color[2];
	int			spcount;
	int			sprite_ordre[SPRITENUM];
	double		zbuff[MAX_WIDTH];
	double		sprite_distance[SPRITENUM];
	Mix_Chunk	*run;
	Mix_Chunk	*gun;
	Mix_Music	*bgm[4];
	int			chacha;
	int			kaka;
	int			kaco;
	int			l_up;
}				t_game;

typedef struct	s_parser
{
	char		set[6];
	char		*str;
	int			c;
	int			fd;
	int			num_of_sprites_id;
}				t_parser;

void			cast_rays(t_game *g);
t_tex			get_texture(char *file_name);
void			draw_walls(t_game *g);
void			cast_floor(t_game *g);
void			draw_sprites(t_game *g);
t_sprite		new_sprite(t_vec2 pos, char id);
void			get_all_sprites(t_game *g);
void			sort_sprites(t_game *g);
int				save_bmp_image();
int				check_extention(char *cub);
t_vec2			init_resolution(char *str);
t_game			init_game(char *file);
void			init_wall_textures(t_game *game, char *str, char *d);
void			check_resolution(char *str);
void			exit_msg(char *msg);
void			init_sprites(t_game *game, char *str, int *num);
void			check_sprite(t_game *game, char *str, int tex_num);
void			init_floor_ceil(t_game *game, char *str, char *set);
void			check_fc_rgb(t_game *game, char *str, int id);
void			check_fc_texture(t_game *game, char *str, int id);
void			set_map(t_game *game, char *str);
void			check_map(t_game *game, char *str);
void			verify_map(t_game *game);
void			verify_sprites(t_game *game, t_parser *p);
void			set_cam(t_game *game);
int				key_press(int key, t_game *g);
int				key_release(int key, t_game *g);
void			update_player_pos(t_game *g);
int				mouse_press(int button, int x, int y, t_game *g);
int				mouse_release(int button, int x, int y, t_game *g);
int				mouse_move(int x, int y, t_game *g);
void			move_camera(t_game *g, double rt);
void			full_init(t_game *g);
void			full_free(t_game *g);
int				kill_game(t_game *g);
void			draw_lifebar();
void			draw_hud();
void			init_gun(t_game *g);
void			init_music(t_game *g);
void			play_music(int key, t_game *g);
char			get_shadow(double distance, char c);
void			hard_core(int key);
void			split_press(int key, t_game *g);
void			draw_gun(t_vec2 pos, t_game *g, int x, int y);

#endif
