/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhadem <ikhadem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 04:07:59 by ikhadem           #+#    #+#             */
/*   Updated: 2019/12/29 17:35:09 by ikhadem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	canvas_init(t_vec2 pos, char *title)
{
	g_win.resolution = pos;
	g_win.ptr = mlx_init();
	g_win.win = mlx_new_window(g_win.ptr, pos.x, pos.y, title);
	g_win.img_ptr = mlx_new_image(g_win.ptr, pos.x, pos.y);
	g_win.img_data = mlx_get_data_addr(g_win.img_ptr, &g_win.bpp,\
				&g_win.size_line, &g_win.endian);
}

void	reset_image(void)
{
	mlx_destroy_image(g_win.ptr, g_win.img_ptr);
	g_win.img_ptr = mlx_new_image(g_win.ptr, g_win.resolution.x,\
				g_win.resolution.y);
}
