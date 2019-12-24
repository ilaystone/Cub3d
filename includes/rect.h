/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rect.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhadem <ikhadem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 15:56:48 by ikhadem           #+#    #+#             */
/*   Updated: 2019/12/24 03:45:28 by ikhadem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RECT_H
# define RECT_H

# include "cub3d.h"

typedef struct	s_rect
{
	int			w;
	int			h;
	t_vec2		pos;
	t_color		c;
}				t_rect;

t_rect			new_rect(int w, int h, t_vec2 p, t_color c);
void			add_rect(t_rect r);
void			draw_rect(t_rect r);

#endif