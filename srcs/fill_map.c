/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/11 23:28:23 by mnunnari          #+#    #+#             */
/*   Updated: 2017/06/12 00:07:27 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point			project(int x, int y, int z, t_fdf_info info)
{
	t_point		p;

	p.x = (x - y) * info.tilewidth;
	p.x += (info.rows - 1) * info.tilewidth;
	p.y = (x + y) * info.tilewidth / 2;
	p.y += info.oy;
	p.y -= z;
	return (p);
}

void			fill_map(t_image image, t_fdf_info info)
{
	size_t	x;
	size_t	y;
	int		z;
	t_point	top;
	t_point	bottom;
	int		color;

	y = 0;
	while (y < info.rows)
	{
		x = 0;
		while (x < info.cols)
		{
			z = info.alts[y][x];
			top = project(x, y, z, info);
			bottom = project(x, y, 0, info);
			color = 0x00FFFFFF;
			fill_rect(image, top, bottom, color);
			x++;
		}
		y++;
	}
}
