/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 19:14:25 by mnunnari          #+#    #+#             */
/*   Updated: 2017/05/25 21:04:09 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				is_last_col(int i, t_fdf_info info)
{
	return ((i + 1) % info.cols == 0);
}

int				is_last_row(int i, t_fdf_info info)
{
	return (i / info.cols == info.rows - 1);
}

void			drawmap(t_image image,
		t_point *points, t_fdf_info info)
{
	size_t	i;

	i = 0;
	while (i < info.rows * info.cols - 1)
	{
		if (!is_last_col(i, info))
			drawline(image, points[i], points[i + 1]);
		if (!is_last_row(i, info))
			drawline(image, points[i], points[i + info.cols]);
		i++;
	}
}
