
#include "fractol.h"

int	julia_mouse(int x, int y, t_mlx *mlx)
{
	if (!mlx->frac->juliamouse || y < 3 || x < 0 || x > WIN_W || y > WIN_H)
		return (0);
	mlx->frac->c_r = x * (3.0 / WIN_W) - 1.5;
	mlx->frac->c_i = y * (3.0 / WIN_H) - 1.5;
	draw_fractal(mlx->frac, mlx);
	return (0);
}

int		exitfractol(void)
{
	exit (1);
	return (0);
}

int	ft_error(int flag)
{
	if (flag == 1)
		ft_putendl("usage : ./fractol <mandelbrot> / <julia> / <burningship>");
	if (flag == 2)
		ft_putendl("./fractol : coulnd t init window");
	return (0);
}

int	main(int ac, char **av)
{

	t_mlx 	*mlx;
	t_frac	*frac;
	if (ac < 2)
		return(ft_error(1));
	if (!(mlx = init_window(av[1])))
		return  (ft_error(2));
	frac = init_frac(av[1]);
	draw_fractal(frac, mlx);	
	mlx_hook(mlx->win, 17, 0L, exitfractol, NULL);
	mlx->frac = frac;
	mlx_key_hook(mlx->win, handle_key, mlx);
	mlx_mouse_hook(mlx->win, handle_mouse, mlx);
	if (av[1][0] == 'j')
		mlx_hook(mlx->win, 6, (1L << 6), julia_mouse, mlx);
	mlx_loop(mlx->mlx);
	return (0);
}
