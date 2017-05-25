/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 21:49:45 by mnunnari          #+#    #+#             */
/*   Updated: 2017/05/25 22:53:11 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	drawline(t_image image, t_point p1, t_point p2)
{
	int	swap;
	int	dx;
	int	dy;
	int	x;
	int	y;
	int	d;
	int	ix;
	int	iy;
	int	i;
	int	rgb;

//	ft_printf("p1 [%d, %d], p2 [%d, %d]\n", p1.x, p1.y, p2.x, p2.y);
	rgb = 0x00FFFFFF;
	fill_pixel(image, p1.x, p1.y, rgb);
	fill_pixel(image, p2.x, p2.y, rgb);
	dx = p2.x - p1.x;
	dy = p2.y - p1.y;
	swap = 0;
	if (abs(dx) < abs(dy))
	{
		ft_swap_ints(&dx, &dy);
		swap = 1;
	}
	dx = abs(dx);
	dy = abs(dy);
	x = p1.x;
	y = p1.y;
	d = 2 * dy - dx;
	ix = p2.x >= p1.x ? 1 : -1;
	iy = p2.y >= p1.y ? 1 : -1;
	i = 0;
	while (i < dx)
	{
		x = x + ix;
		if (d > 0)
		{
			y = y + iy;
			d = d + 2 * (dy - dx);
		}
		else
		{
			if (swap)
			{
				y = y + iy;
				x = x - ix;
			}
			d = d + 2 * dy;
		}
		fill_pixel(image, x, y, rgb);
		i++;
	}
}
