/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 22:00:10 by mnunnari          #+#    #+#             */
/*   Updated: 2017/05/28 21:51:04 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	show(t_point *points, t_fdf_info info)
{
	void			*mlx;
	void			*win;
	void			*imageptr;
	t_image			image;
	t_key_param		key_param;

	mlx = mlx_init();
	win = mlx_new_window(mlx, SW, SW, "mlx 42");
	imageptr = mlx_new_image(mlx, info.mapwidth + 2, SW - 1);
	image.img = mlx_get_data_addr(imageptr,
			&image.bpp, &image.linesize, &image.endian);
	drawmap(image, points, info);
	mlx_put_image_to_window(mlx, win, imageptr, info.ox, 0);
	key_param.mlx = mlx;
	key_param.win = win;
	key_param.imageptr = imageptr;
	key_param.info = info;
	mlx_key_hook(win, key_handler, &key_param);
	mlx_loop(mlx);
}

void	render(char *filename)
{
	t_fdf_info	info;
	t_point		*points;

	info = get_fdf_info(filename);
	info.alts = get_altitudes(filename, info);
	info.coeff = 2;
	derive_info(&info);
	points = get_points(info, info.alts);
	show(points, info);
}

int		main(int argc, char **argv)
{
	if (argc != 2)
		ft_printf("usage: fdf map\n");
	else
		render(argv[1]);
}
