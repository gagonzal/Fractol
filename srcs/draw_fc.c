
#include "../includes/fractol.h"

void	set_pixel(int i, t_frac *frac, double x, double y, t_mlx *mlx)
{
	if (i == frac->nb_iter)
		mlx->img[(int)(x - frac->x0) + (int)(y - frac->y0) * WIN_W] = 0;
	else if (i > frac->nb_iter / 3)
		mlx->img[(int)(x - frac->x0) + (int)(y - frac->y0) \
		   	* WIN_W] = ((i * 0xFF / frac->nb_iter) << 8);
	else
		mlx->img[(int)(x - frac->x0) + (int)(y - frac->y0) \
		   	* WIN_W] = ((i * 0xFF / frac->nb_iter + 30) << 16);
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
void	print_mandelbrot(t_frac *frac, t_mlx *mlx)
{
	double x;
	double y;

	y = frac->y0;
	while (++y < WIN_H + frac->y0)
	{
		x = frac->x0;
		while (x < WIN_W + frac->x0)
		{
			frac->z_r = 0;
			frac->z_i = 0;
			frac->c_r = x / frac->zoom + frac->x1;
			frac->c_i = y / frac->zoom + frac->y1;
			draw_mandel(x, y, frac, mlx);
			x++;
		}
	}
	mlx_put_image_to_window(mlx->img, mlx->win, mlx->img_ptr, 0, 0);
}
void	draw_fractal(t_frac *frac, t_mlx *mlx)
{

	if (frac->flag == 0)
	{
		print_mandelbrot(frac, mlx);
	}
	else if(frac->flag == 1)
	{
		print_julia(frac, mlx);
	}
	else
		print_burningship(frac, mlx);
	/*
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
	mlx_put_image_to_window(mlx->img, mlx->win, mlx->img_ptr, 0, 0);*/
}
