

#include "../includes/fractol.h"

double		ft_abs(double c)
{
	return((c < 0) ? -c : c);
}

void	draw_ship(double x, double y, t_frac *frac, t_mlx *mlx)
{
	double R;
	double I;
	int i;
	double tmp;

	i = 0;
	R = 0;
	I = 0;
	while (R + I < (1 << 16) && i < frac->nb_iter)
	{
		tmp = R - I + frac->c_r;
		frac->z_i = ft_abs(2 * frac->z_r * frac->z_i) + frac->c_i;
		frac->z_r = ft_abs(tmp);
		R = frac->z_r * frac->z_r;
		I = frac->z_i * frac->z_i;
		i++;
	}
	set_pixel(i, frac, x, y, mlx);
}

void	print_burningship(t_frac *frac, t_mlx *mlx)
{
	double x;
	double y;

	y = 0;
	while (++y < WIN_H)
	{
		x = 0;
		while (x < WIN_W)
		{
			frac->z_r = 0;
			frac->z_i = 0;
			frac->c_r = x / frac->zoom + frac->x1;
			frac->c_i = y / frac->zoom + frac->y1;
			draw_ship(x, y, frac, mlx);
			x++;
		}
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img_ptr, 0, 0);
}
