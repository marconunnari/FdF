/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 22:28:28 by mnunnari          #+#    #+#             */
/*   Updated: 2017/05/28 21:35:27 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		rotate(t_key_param *param, int dir)
{
	t_image			image;
	t_point			*points;

	if ((param->info.coeff == 2 && dir == -1) ||
		(param->info.coeff == 6 && dir == 1))
	{
		ft_printf("Can't rotate more than this\n");
		return ;
	}
	param->info.coeff += dir;
	derive_info(&param->info);
	points = get_points(param->info, param->info.alts);
	mlx_destroy_image(param->mlx, param->imageptr);
	param->imageptr = mlx_new_image(param->mlx, param->info.mapwidth + 2, SW - 1);
	image.img = mlx_get_data_addr(param->imageptr, &image.bpp, &image.linesize, &image.endian);
	drawmap(image, points, param->info);
	mlx_put_image_to_window(param->mlx, param->win, param->imageptr, param->info.ox, 0);
}

int		key_handler(int keycode, void *param)
{
	ft_printf("key event %d\n", keycode);
	if (keycode == 65362 || keycode == 126)
		rotate((t_key_param*)param, 1);
	if (keycode == 65364 || keycode == 125)
		rotate((t_key_param*)param, -1);
	if (keycode == 53 || keycode == 65307)
		exit(0);
	return (0);
}
