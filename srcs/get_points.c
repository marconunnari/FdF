#include "fdf.h"

t_point			*get_points(t_fdf_info info, int **alts)
{
	t_point		*points;
	size_t		row;
	size_t		col;
	size_t		i;

	points = (t_point*)malloc(sizeof(t_point) * info.rows * info.cols);
	i = 0;
	row = 0;
	while (row < info.rows)
	{
		col = 0;
		while (col < info.cols)
		{
			points[i].z = alts[row][col];
			points[i].x = (col * WIDTH - row * WIDTH);
			points[i].x += (info.rows - 1) * WIDTH;
			points[i].y = (row * WIDTH + col * WIDTH);
			points[i].y -= points[i].z * 2;
			i++;
			col++;
		}
		row++;
	}
	return (points);
}
