/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhadem <ikhadem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 05:38:19 by ikhadem           #+#    #+#             */
/*   Updated: 2019/12/18 18:09:49 by ikhadem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_H
# define POINT_H

# include "cub3d.h"

typedef struct	s_point
{
	double		x;
	double		y;
}				t_point;

t_point			new_point(double x, double y);
void			add_point(t_point p, t_color c);
void			draw_point(t_point p);

#endif
