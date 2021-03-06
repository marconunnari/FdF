/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_points.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 15:47:07 by mnunnari          #+#    #+#             */
/*   Updated: 2017/05/28 21:50:06 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
			points[i].y = (row + col) * info.tilewidth / info.coeff;
			points[i].y -= points[i].z * info.coeff;
			points[i].y += info.oy;
			i++;
			col++;
		}
		row++;
	}
	return (points);
}
