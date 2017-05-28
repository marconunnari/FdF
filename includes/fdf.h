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

typedef	struct	s_point
{
	int			x;
	int			y;
	int			z;
}				t_point;

typedef	struct	s_rect
{
	int			swap;
	int			dx;
	int			dy;
	int			ix;
	int			iy;
}				t_rect;

typedef	struct	s_fdf_info
{
	size_t		rows;
	size_t		cols;
	size_t		tilewidth;
	size_t		mapwidth;
	size_t		mapheight;
	size_t		oy;
	size_t		ox;
	unsigned char	coeff;
	int		**alts;
}				t_fdf_info;

typedef	struct	s_key_param
{
	void		*mlx;
	void		*win;
	void		*imageptr;
	t_fdf_info	info;
}				t_key_param;

typedef	struct	s_image
{
	char		*img;
	int			bpp;
	int			linesize;
	int			endian;
}				t_image;

int				key_handler(int keycode, void *param);
t_fdf_info		get_fdf_info(char *filename);
void			derive_info(t_fdf_info *info);
int				**get_altitudes(char *filename, t_fdf_info info);
t_point			*get_points(t_fdf_info, int **altitudes);
void			drawline(t_image image, t_point p1, t_point p2);
void			drawmap(t_image image, t_point *points, t_fdf_info info);
void			fill_pixel(t_image img, int x, int y, int color);
#endif
