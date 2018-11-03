

#ifndef FRACTOL_H
# define FRACTOL_H

#include "../libft/libft.h"
#include "../minilibx_mac/mlx.h"
# define WIN_W 1920
# define WIN_H 1080


typedef struct s_mlx
{
	char	*mlx;
	char	*win;
	char	*img_ptr;
	int		*img;
	int		bpp;
	int		endian;
	int		size_line;

}				t_mlx;

typedef struct s_frac
{
	double	x1;
	double	y1;
	unsigned long int	zoom;
	int	nb_iter;
	double	c_r;
	double	c_i;
	double	z_r;
	double	z_i;
	int		size_line;
	int		endian;
	int		bpp;

}				t_frac;

t_frac	*init_frac(char *name);
t_mlx	*init_window(char *name);
void	draw_fractal(char *name, t_frac *frac, t_mlx *mlx);

#endif
