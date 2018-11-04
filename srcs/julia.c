
#include "../includes/fractol.h"
#include <stdio.h>

void	draw_julia(int x, int y, t_frac *frac, t_mlx *mlx)
{
	double R;
	double I;
	double tmp;
	int i;

	R = frac->z_r * frac->z_r;
	I = frac->z_i * frac->z_i;
	i = 0;
	while (R + I < 4 && i < frac->nb_iter)
	{
		tmp = frac->z_r;
		frac->z_r = R - I + frac->c_r;
		frac->z_i = 2 * frac->z_i * tmp + frac->c_i;
		R = frac->z_r * frac->z_r;
		I = frac->z_i * frac->z_i;
		i++;
	}
	set_pixel(i, frac, x, y, mlx);
}


void	print_julia(t_frac *frac, t_mlx *mlx)
{
	double x;
	double y;

	y = 0;
//	printf("%lf\n", frac->c_r);
//	printf("%lf\n", frac->c_i);
	while (y < WIN_H)
	{
		x = 0;
		while (x < WIN_W)
		{
			frac->z_r = x / frac->zoom + frac->x1;
			frac->z_i = y / frac->zoom + frac->y1;
			draw_julia(x, y, frac, mlx);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx->img, mlx->win, mlx->img_ptr, 0, 0);
}
