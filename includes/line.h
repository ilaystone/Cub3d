/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhadem <ikhadem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 14:53:48 by ikhadem           #+#    #+#             */
/*   Updated: 2019/12/24 16:26:15 by ikhadem          ###   ########.fr       */
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

t_line			new_line(t_vec2 p1, t_vec2 p2, t_color c);
void			add_line(t_line l);;
void			draw_line(t_line l);

#endif