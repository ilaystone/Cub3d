/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhadem <ikhadem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 04:07:59 by ikhadem           #+#    #+#             */
/*   Updated: 2019/12/15 04:21:28 by ikhadem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	display_init(t_display *win, int w, int h, char *title)
{
	win->ptr = mlx_init();
	win->win = mlx_new_window(win->ptr, w, h, title);
	win->img_ptr = mlx_new_image(win->ptr, w, h);
	win->img_data = mlx_get_data_addr(win->img_ptr, &win->bpp, &win->size_line, &win->endian);
}
