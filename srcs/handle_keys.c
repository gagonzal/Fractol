

#include "../includes/fractol.h"

int	handle_key(int key, t_mlx *mlx)
{
	if (key == 34 && mlx->frac->nb_iter <= 1000)
		mlx->frac->nb_iter += 25;
	else if (key == 40 && mlx->frac->nb_iter > 25)
		mlx->frac->nb_iter += 25;
	else if (key == 49)
		mlx->frac->juliamouse = (mlx->frac->juliamouse ? 0 : 1);
	else if (key == 53)
		exit (0);
	draw_fractal(mlx->frac, mlx);
	return (0);
}
