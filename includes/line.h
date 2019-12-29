/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhadem <ikhadem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 14:53:48 by ikhadem           #+#    #+#             */
/*   Updated: 2019/12/25 19:40:07 by ikhadem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINE_H
# define LINE_H

# include "cub3d.h"

typedef struct	s_line
{
	t_vec2		p1;
	t_vec2		p2;
	t_color		c;
}				t_line;

typedef struct	s_plot
{
	int			dx;
	int			sx;
	int			dy;
	int			sy;
	int			err;
	int			e2;
}				t_plot;

t_line			new_line(t_vec2 p1, t_vec2 p2, t_color c);
void			add_line(t_line l);;
void			draw_line(t_line l);

#endif