#include "minilibx/mlx.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct s_color
{
	int r;
	int g;
	int b;
	int a;
} t_color;

int main()
{
	void *ptr = mlx_init();
	int w, h;
	void *win = mlx_new_window(ptr, 1600, 900, "cub3d");
	void *img = mlx_png_file_to_image(ptr, "./Archive/1.png", &w, &h);
	void *imgw = mlx_new_image(ptr, 1600, 900);
	int b, s, e;
	int b2, s2, e2;
	char *image_data = mlx_get_data_addr(img, &b, &s, &e);
	char *image_dataw = mlx_get_data_addr(imgw, &b2, &s2, &e2);
	for (int x = 0; x < 200; x++)
	{
		for (int y = 0; y < 100; y++)
		{
			int a = 4 * x + 4 * 1600 * y;
			int nx = x * (float)w / 200;
			int ny = y * (float)h / 100;
			int b = 4 * nx + 4 * w * ny;
			image_dataw[a] = image_data[b];
			image_dataw[a + 1] = image_data[b + 1];
			image_dataw[a + 2] = image_data[b + 2];
		}
	}
	mlx_put_image_to_window(ptr, win, imgw, 0, 0);
	mlx_loop(ptr);
	return (0);
}
