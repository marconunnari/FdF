#include "fdf.h"

t_point			*get_points(t_fdf_info info, int **alts)
{
	t_point		*points;
	size_t		row;
	size_t		col;
	size_t		width;
	size_t		i;

	points = (t_point*)malloc(sizeof(t_point) * info.rows * info.cols);
	i = 0;
	row = 0;
	width = 361 / info.cols;
	if (width < 1)
		width = 1;
	while (row < info.rows)
	{
		col = 0;
		while (col < info.cols)
		{
			points[i].z = alts[row][col];
			points[i].x = (col * width - row * width);
			points[i].x += (info.rows - 1) * width;
			points[i].y = (row * width + col * width) / 2;
			points[i].y -= points[i].z * 1;
			i++;
			col++;
		}
		row++;
	}
	return (points);
}
