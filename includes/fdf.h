#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include "mlx.h"
# include <math.h>
# include "libft.h"
#include <fcntl.h>
#include <unistd.h>

typedef	struct	s_point
{
	int	x;
	int	y;
}		t_point;

void		drawline(void *mlx, void *win, t_point p1, t_point p2);

int			key_handler(int keycode, void *param);
int			**parse_file(char *filename);
#endif
