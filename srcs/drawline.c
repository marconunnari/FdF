/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 21:49:45 by mnunnari          #+#    #+#             */
/*   Updated: 2017/05/24 20:12:09 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	drawline(void *mlx, void *win, t_point p1, t_point p2)
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

//	ft_printf("p1 [%d, %d], p2 [%d, %d]\n", p1.x, p1.y, p2.x, p2.y);
	mlx_pixel_put(mlx, win, p1.x, p1.y, 0x00FFFFFF);
	mlx_pixel_put(mlx, win, p2.x, p2.y, 0x00FFFFFF);
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
		mlx_pixel_put(mlx, win, x, y, 0x00FFFFFF);
		i++;
	}
}
