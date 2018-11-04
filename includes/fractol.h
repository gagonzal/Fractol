

#ifndef FRACTOL_H
# define FRACTOL_H

#include "../libft/libft.h"
#include "../minilibx_mac/mlx.h"
# define WIN_W 680
# define WIN_H 480

typedef struct 			s_frac
{
	double				x1;
	double				y1;
	unsigned long int	zoom;
	int					nb_iter;
	double				c_r;
	double				c_i;
	double				z_r;
	double				z_i;
	int					size_line;
	int					endian;
	int					bpp;
	int					flag;
	int					juliamouse;
	double				x0;
	double				y0;
}						t_frac;

typedef struct s_mlx
{
	char	*mlx;
	char	*win;
	char	*img_ptr;
	int		*img;
	int		bpp;
	int		endian;
	int		size_line;
	t_frac  *frac;

}				t_mlx;
t_frac	*init_frac(char *name);
t_mlx	*init_window(char *name);
void	draw_fractal(t_frac *frac, t_mlx *mlx);
void	set_pixel(int i, t_frac *frac, double x, double y, t_mlx *mlx);
void	print_julia(t_frac *frac, t_mlx *mlx);
void	print_burningship(t_frac *frac, t_mlx *mlx);
int		handle_key(int key, t_mlx *mlx);
int		handle_mouse(int input, int x, int y, t_mlx *mlx);

#endif
