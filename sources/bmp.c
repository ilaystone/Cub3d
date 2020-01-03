/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhadem <ikhadem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/31 14:17:03 by ikhadem           #+#    #+#             */
/*   Updated: 2020/01/02 00:21:48 by ikhadem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static t_bmp	init_bmph(void)
{
	t_bmp		res;

	res.id[0] = 'B';
	res.id[1] = 'M';
	res.file_size = 54 + 4 * (int)g_win.resolution.x * (int)g_win.resolution.y;
	res.unused = 0;
	res.offset = 54;
	res.dib = 54 - 14;
	res.width = (int)g_win.resolution.x;
	res.height = -1 * (int)g_win.resolution.y;
	res.plane[0] = 1;
	res.plane[1] = 0;
	res.bpp[0] = 32;
	res.bpp[1] = 0;
	res.compression = 0;
	res.raw_bitmap_size = 4 * (int)g_win.resolution.x * (int)g_win.resolution.y;
	res.resx = (int)g_win.resolution.x;
	res.resy = (int)g_win.resolution.y;
	res.number_of_colors = 0;
	res.important_colors = 0;
	return (res);
}

int				save_bmp_image(void)
{
	t_bmp		img;
	int			file;

	file = open("cub3D.bmp", O_WRONLY | O_CREAT | O_TRUNC | O_APPEND, 0777);
	img = init_bmph();
	write(file, &img, 54);
	write(file, g_win.img_data, img.raw_bitmap_size);
	return (1);
}
