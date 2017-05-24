#include "fdf.h"

void			draw_map(void *mlx, void *win,
		t_point *points, t_fdf_info info)
{
	size_t	i;

	(void)mlx; (void)win; (void)points;
	i = 0;
	while (i < info.rows * info.cols - 1)
	{
		if (points[i].x / 20 == (int)info.cols)
		{
			drawline(mlx, win, points[i], points[i + info.cols]);
		}
		else if (points[i].y / 20 == (int)info.rows)
		{
			drawline(mlx, win, points[i], points[i + 1]);
		}
		else
		{
			drawline(mlx, win, points[i], points[i + 1]);
			drawline(mlx, win, points[i], points[i + info.cols]);
		}
		i++;
	}
}
