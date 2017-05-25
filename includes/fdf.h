#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include "mlx.h"
# include <math.h>
# include "libft.h"
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>

# define SW 800
# define SH 800

typedef	struct	s_point
{
	int	x;
	int	y;
	int	z;
}		t_point;

typedef	struct	s_fdf_info
{
	size_t	rows;
	size_t	cols;
}		t_fdf_info;

void			drawline(void *mlx, void *win, t_point p1, t_point p2);
int				key_handler(int keycode, void *param);
t_fdf_info		get_fdf_info(char *filename);
int				**get_altitudes(char *filename, t_fdf_info info);
t_point			*get_points(t_fdf_info, int **altitudes);
void			drawmap(void *mlx, void *win, t_point *points, t_fdf_info info);
#endif
