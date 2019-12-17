/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhadem <ikhadem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 00:03:04 by ikhadem           #+#    #+#             */
/*   Updated: 2019/12/17 17:01:05 by ikhadem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "./cub3d.h"

typedef struct	s_map
{
	int			width;
	int			height;
	char		*map;
	t_player	player;
}				t_map;

#endif
