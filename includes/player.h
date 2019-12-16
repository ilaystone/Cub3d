/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhadem <ikhadem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 04:15:33 by ikhadem           #+#    #+#             */
/*   Updated: 2019/12/16 04:41:08 by ikhadem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

# include "cub3d.h"

typedef struct	s_player
{
	t_point		pos;
	float		radius;
	int			turn_direction;
	int			walk_direction;
	float		rotation_angle;
	float		move_speed;
	float		rotation_speed;
}				t_player;


#endif