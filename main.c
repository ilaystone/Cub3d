/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhadem <ikhadem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 20:02:50 by ikhadem           #+#    #+#             */
/*   Updated: 2019/12/15 22:05:50 by ikhadem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

int		main(void)
{
	canvas_init(&g_win, 500, 500, "cub3d");
	//draw_rect(new_rect(200, 200, new_point(100, 100)));
	draw_line(new_line(new_point(0, 0), new_point(100, 150)));
	mlx_loop(g_win.ptr);
	return (0);
}
