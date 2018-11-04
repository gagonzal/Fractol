

#include "../includes/fractol.h"

t_frac	*init_frac(char *name)
{
	t_frac	*frac;
	if (!(frac = malloc(sizeof(t_frac))))
		return (NULL);
	if (!(ft_strcmp(name, "mandelbrot")))
	{
//		ft_putendl("ok");
		frac->x1 = -2.3;
		frac->y1 = -1.2;
		frac->zoom = 200;
		frac->flag= 0;
	}
	if (!(ft_strcmp(name, "julia")))
	{
		frac->x1 = -1.6;
		frac->y1 = -1.2;
		frac->c_r = 0.285;
		frac->c_i = 0.01;
		frac->zoom = 200;
		frac->flag = 1;
	}
	if (!(ft_strcmp(name, "burningship")))
	{
		ft_putendl("ok");
		frac->x1 = -2.5;
		frac->y1 = -2;
		frac->zoom = 150;
		frac->flag = 3;
	}
	frac->juliamouse = 1;
	frac->nb_iter = 155;
	frac->x0 = 0;
	frac->y0 = 0;
	return (frac);
}

t_mlx	*init_window(char *name)
{
	t_mlx *mlx;

	if (!(mlx = malloc(sizeof(t_mlx))))
		return (NULL);
	if (!(mlx->mlx = mlx_init()))
	{
		ft_memdel((void**)(&mlx));
		return (NULL);
	}
	if (!(mlx->win = mlx_new_window(mlx->mlx, WIN_W, WIN_H, name)))
	{
		mlx_destroy_window(mlx->mlx, mlx->win);
		return (NULL);
	}
	if (!(mlx->img_ptr = mlx_new_image(mlx->mlx, WIN_W, WIN_H)))
		return (NULL);
	mlx->img =(int *) mlx_get_data_addr(mlx->img_ptr, &mlx-> bpp, &mlx->size_line, &mlx->endian);
	return (mlx);
}
