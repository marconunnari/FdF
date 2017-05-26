/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 22:00:10 by mnunnari          #+#    #+#             */
/*   Updated: 2017/05/26 15:47:37 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	show(t_point *points, t_fdf_info info)
{
	void	*mlx;
	void	*win;
	void	*imageptr;
	t_image	image;

	mlx = mlx_init();
	win = mlx_new_window(mlx, SW, SH, "mlx 42");
	mlx_key_hook(win, key_handler, 0);
	imageptr = mlx_new_image(mlx, info.mapwidth + 2, SH - 1);
	image.img = mlx_get_data_addr(imageptr,
			&image.bpp, &image.linesize, &image.endian);
	(void)points;
	drawmap(image, points, info);
	mlx_put_image_to_window(mlx, win, imageptr, info.ox, 0);
	mlx_loop(mlx);
}

void	render(char *filename)
{
	t_fdf_info	info;
	int			**alts;
	t_point		*points;

	info = get_fdf_info(filename);
	ft_printf("rows: %d\n", info.rows);
	ft_printf("cols: %d\n", info.cols);
	alts = get_altitudes(filename, info);
	points = get_points(info, alts);
	show(points, info);
}

int		main(int argc, char **argv)
{
	if (argc != 2)
		ft_printf("usage: fdf map\n");
	else
		render(argv[1]);
}
