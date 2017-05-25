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
			points[i].x = (col * info.tilewidth - row * info.tilewidth);
			points[i].x += (info.rows - 1) * info.tilewidth;
			points[i].y = (row * info.tilewidth + col * info.tilewidth) / 2;
			points[i].y -= points[i].z;
			points[i].y += info.oy;
			i++;
			col++;
		}
		row++;
	}
	return (points);
}
