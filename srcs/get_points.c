#include "fdf.h"

t_point			*get_points(t_fdf_info info, int **alts)
{
	t_point		*points;
	size_t		row;
	size_t		col;
	size_t		i;

	points = (t_point*)malloc(sizeof(t_point) * info.rows * info.cols);
	i = 0;
	row = 1;
	while (row <= info.rows)
	{
		col = 1;
		while (col <= info.cols)
		{
			points[i].y = 20 * row;
			points[i].x = 20 * col;
			points[i].z = alts[row -1][col - 1];
			i++;
			col++;
		}
		row++;
	}
	return (points);
}
