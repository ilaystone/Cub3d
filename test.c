/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhadem <ikhadem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 03:38:07 by ikhadem           #+#    #+#             */
/*   Updated: 2020/01/05 03:48:31 by ikhadem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "minilibx/mlx.h"

typedef struct	s_tex
{
	int			bpp;
	int			size_line;
	int			endian;
	int			w;
	int			h;
	void		*img;
	char		*img_ptr;
	double		wall_x;
	int			tex_x;
	double		step;
	double		tex_pos;
}				t_tex;

t_tex		get_texture(char *file_name, void *ptr)
{
	t_tex	data;

	data.img = mlx_png_file_to_image(ptr, file_name, &data.w, &data.h);
	data.img_ptr = mlx_get_data_addr(data.img, &data.bpp, &data.size_line,\
						&data.endian);
	return (data);
}

void	Animate(t_tex	*t)
{
	
}

int     main()
{
	t_tex	t[10];

	void	*ptr;
	void	*win;
	void	*img_ptr;
	char	*Data;
	int		endian;
	int		bpp;
	int		size_line;

	t[0] = get_texture("./animated/")

	ptr = mlx_init();
	win = mlx_new_window(ptr, 800, 450, "Testo Animation");
	img_ptr = mlx_new_image(ptr, 800, 450);
	Data = mlx_get_data_addr(img_ptr, &bpp, &size_line, &endian);
	mlx_loop(ptr);
    return (0);
}