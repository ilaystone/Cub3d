/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhadem <ikhadem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 02:58:50 by ikhadem           #+#    #+#             */
/*   Updated: 2019/12/29 17:56:00 by ikhadem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

# include "cub3d.h"

typedef struct	s_color
{
	int			r;
	int			g;
	int			b;
	int			a;
}				t_color;

t_color			new_color(int r, int g, int b, int a);

#endif
