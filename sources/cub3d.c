/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhadem <ikhadem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 04:07:59 by ikhadem           #+#    #+#             */
/*   Updated: 2019/12/16 18:06:03 by ikhadem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include <mlx.h>

void	canvas_init(int w, int h, char *title)
{
	g_win.ptr = mlx_init();
	g_win.win = mlx_new_window(g_win.ptr, w, h, title);
	g_win.img_ptr = mlx_new_image(g_win.ptr, w, h);
	g_win.img_data = mlx_get_data_addr(g_win.img_ptr, &g_win.bpp, &g_win.size_line, &g_win.endian);
}
