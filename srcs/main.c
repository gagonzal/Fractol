
#include "fractol.h"

int		exitfractol(void)
{
	exit (1);
	return (0);
}

int	main(int ac, char **av)
{

	t_mlx 	*mlx;
	t_frac	*frac;
	if (ac > 2)
	{
		return(0);
//		return(ft_errors(1));
	}
	if (!(mlx = init_window(av[1])))
	{
//		return (ft_error(2));
		return  (0);
	}
	frac = init_frac(av[1]);
	draw_fractal(av[1], frac, mlx);	
	mlx_hook(mlx->win, 17, 0L, exitfractol, NULL);
	mlx_loop(mlx->mlx);
	return (0);
}
