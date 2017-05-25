/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_pixel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 20:00:34 by mnunnari          #+#    #+#             */
/*   Updated: 2017/05/25 22:02:44 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			fill_pixel(t_image image, int x, int y, int color)
{
	unsigned long long		i;

//	ft_printf("bpp %d, linesize %llu \n", image.bpp, image.linesize);
	i = (image.linesize * y) + 4 * x;
//	ft_printf("x %d, y %d, i %d, color %#x\n", x, y, i, color);
	image.img[i] = color & 0xFF;
//	ft_printf("%#hhx \n", image.img[i]);
	image.img[i + 1] = (color >> 8) & 0xFF;
//	ft_printf("%#hhx \n", image.img[i + 1]);
	image.img[i + 2] = (color >> 16) & 0xFF;
//	ft_printf("%#hhx \n", image.img[i + 2]);
	image.img[i + 3] = (color >> 24) & 0xFF;
//	ft_printf("%#hhx \n", image.img[i + 3]);
}
