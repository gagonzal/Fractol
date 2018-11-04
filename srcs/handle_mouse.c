
#include "../includes/fractol.h"

void zoom_in(t_frac *frac, int x, int y)
{
	frac->x0 += x - WIN_W / 2;
	frac->y0 += y - WIN_H / 2;
	frac->zoom *= 1.2;
	frac->x0 *= 1.2;
	frac->y0 *= 1.2;
	frac->x0 += WIN_W / 10 - 2;
	frac->y0 += WIN_H / 10 - 2;
}

void	zoom_out(t_frac *frac, int x, int y)
{
	frac->x0 += x - WIN_W / 2;
	frac->y0 += y - WIN_H / 2;
	frac->zoom *= 0.8;
	frac->x0 *= 0.8;
	frac->y0 *= 0.8;
	frac->x0 -= WIN_W / 10 - 2;
	frac->y0 -= WIN_H / 10 - 2;
}

int	handle_mouse(int input, int x, int y, t_mlx *mlx)
{
	if (y < 3)
		return (0);
	if (input == 1 && mlx->frac->zoom <= 2000000000)
		zoom_in(mlx->frac, x, y);
	if (input == 2 && mlx->frac->zoom >= 20)
		zoom_out(mlx->frac, x, y);
	if (input == 4 && mlx->frac->zoom <= 2000000000)
		zoom_in(mlx->frac, x, y);
	if (input == 5 && mlx->frac->zoom >= 20)
		zoom_out(mlx->frac, x, y);
	draw_fractal(mlx->frac, mlx);
	return (0);
}
