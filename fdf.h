#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include <stdlib.h>
# include "mlx.h"
# include <math.h>

typedef	struct	s_point
{
	int	x;
	int	y;
}		t_point;

void		drawline(void *mlx, void *win, t_point p1, t_point p2);

#endif
