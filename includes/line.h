/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhadem <ikhadem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 14:53:48 by ikhadem           #+#    #+#             */
/*   Updated: 2019/12/16 03:16:52 by ikhadem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINE_H
# define LINE_H

# include "cub3d.h"

typedef struct	s_line
{
	t_point		p1;
	t_point		p2;
	t_color		c;
}				t_line;

t_line			new_line(t_point p1, t_point p2, t_color c);
void			add_line(t_line l, t_point d, t_point s);
void			draw_line(t_line l);

#endif