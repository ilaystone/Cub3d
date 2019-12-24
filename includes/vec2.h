/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhadem <ikhadem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 05:38:19 by ikhadem           #+#    #+#             */
/*   Updated: 2019/12/24 03:45:25 by ikhadem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC2_H
# define VEC2_H

# include "cub3d.h"

typedef struct	s_vec2
{
	double		x;
	double		y;
}				t_vec2;

t_vec2			new_vec2(double x, double y);
void			add_vec2(t_vec2 p, t_color c);
void			draw_vec2(t_vec2 p);

#endif
