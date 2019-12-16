/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhadem <ikhadem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 05:38:19 by ikhadem           #+#    #+#             */
/*   Updated: 2019/12/16 03:13:35 by ikhadem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_H
# define POINT_H

# include "cub3d.h"

typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;

t_point			new_point(int x, int y);
void			add_point(t_point p, t_color c);
void			draw_point(t_point p);

#endif
