/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 19:14:25 by mnunnari          #+#    #+#             */
/*   Updated: 2017/05/24 20:56:17 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			drawmap(void *mlx, void *win,
		t_point *points, t_fdf_info info)
{
	size_t	i;

	i = 0;
	while (i < info.rows * info.cols)
	{
		if (i == info.rows * info.cols - 1)
			;
		else if ((i + 1) % info.cols == 0)
			drawline(mlx, win, points[i], points[i + info.cols]);
		else if (i / info.cols == info.rows - 1)
			drawline(mlx, win, points[i], points[i + 1]);
		else
		{
			drawline(mlx, win, points[i], points[i + 1]);
			drawline(mlx, win, points[i], points[i + info.cols]);
		}
//		t_point origin = {SH / 2, SW / 2, 0};
//		drawline(mlx, win, origin, points[i]);
		i++;
	}
}
