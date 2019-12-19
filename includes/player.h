/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhadem <ikhadem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 04:15:33 by ikhadem           #+#    #+#             */
/*   Updated: 2019/12/18 18:08:13 by ikhadem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

# include "cub3d.h"

typedef struct	s_player
{
	t_point		pos;
	double		radius;
	double		FOV;
	double		turn_direction;
	double		walk_direction;
	double		rotation_angle;
	double		move_speed;
	double		rotation_speed;
}				t_player;


#endif