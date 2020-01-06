/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhadem <ikhadem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 03:00:34 by ikhadem           #+#    #+#             */
/*   Updated: 2020/01/04 00:30:27 by ikhadem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_color		new_color(int r, int g, int b, int a)
{
	t_color	c;

	c.r = r;
	c.g = g;
	c.b = b;
	c.a = a;
	return (c);
}

t_color		get_color_from_string(char *str)
{
	int		r;
	int		g;
	int		b;

	r = ft_atoi(str);
	while (ft_isdigit(*str))
		str++;
	str++;
	g = ft_atoi(str);
	while (ft_isdigit(*str))
		str++;
	str++;
	b = ft_atoi(str);
	if (r < 0 || g < 0 || b < 0 || r > 255 || g > 255 || b > 255)
		exit_msg("Wrong RGB format for F / C");
	return (new_color(r, g, b, 0));
}
