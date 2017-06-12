/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/11 23:28:23 by mnunnari          #+#    #+#             */
/*   Updated: 2017/06/13 00:31:22 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point			project(int x, int y, int z, t_fdf_info info)
{
	t_point		p;

	x = x * info.tilewidth;
	y = y * info.tilewidth;
	p.x = x - y;
	p.x += (info.rows - 1) * info.tilewidth;
	p.y = floor((y + x) / 2);
	p.y += info.oy;
	p.y -= z;
	return (p);
}

int				rgb(unsigned char r, unsigned char g, unsigned char b)
{
	int		color;

	color = 0;
	color |= r << 16;
	color |= g << 8;
	color |= b;
	return (color);
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
			z /= 2;
			color = rgb(244 - 30 * z, 164 - 20 * z, 98 - 10 * z);
			fill_rect(image, top, bottom, color);
			x++;
		}
		y++;
	}
}
