
#include "../includes/fractol.h"

void	set_pixel(int i, t_frac *frac, double x, double y, t_mlx *mlx)
{
	if (i == frac->nb_iter)
		mlx->img[(int)x + (int)y * WIN_W] = 0;
	else if (i > frac->nb_iter / 3)
		mlx->img[(int)x + (int)y * WIN_W] = ((i * 0xFF / frac->nb_iter) << 8);
	else
		mlx->img[(int)x + (int)y * WIN_W] = ((i * 0xFF / frac->nb_iter + 30) << 16);
}

void	draw_mandel(int x, int y, t_frac *frac, t_mlx *mlx)
{
	double R;
	double I;
	double tmp;
	int i;

	i = 0;
	R = 0;
	I = 0;
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

void	draw_fractal(char *name, t_frac *frac, t_mlx *mlx)
{
	double x;
	double y;

	(void)name;
	y = 0;
	while (y < WIN_H)
	{
		x = 0;
		while (x < WIN_W)
		{
			frac->z_r = 0;
			frac->z_i = 0;
			frac->c_r = x / frac->zoom + frac->x1;
			frac->c_i = y / frac->zoom + frac->y1;
			draw_mandel(x, y, frac, mlx);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx->img, mlx->win, mlx->img_ptr, 0, 0);
}
