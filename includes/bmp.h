/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhadem <ikhadem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/01 15:57:31 by ikhadem           #+#    #+#             */
/*   Updated: 2020/01/07 03:16:11 by ikhadem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BMP_H
# define BMP_H

# include "cub3d.h"
# pragma pack(push, 1)

typedef struct	s_bmp
{
	char		id[2];
	int			file_size;
	int			unused;
	int			offset;
	int			dib;
	int			width;
	int			height;
	char		plane[2];
	char		bpp[2];
	int			compression;
	int			raw_bitmap_size;
	int			resx;
	int			resy;
	int			number_of_colors;
	int			important_colors;
}				t_bmp;

# pragma pack(pop)
#endif
