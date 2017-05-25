/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 22:00:10 by mnunnari          #+#    #+#             */
/*   Updated: 2017/05/25 22:02:23 by mnunnari         ###   ########.fr       */
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
	mlx_key_hook(win,key_handler, 0);
	imageptr = mlx_new_image(mlx, info.mapwidth + 2, SH - 1);
	image.img = mlx_get_data_addr(imageptr, &image.bpp, &image.linesize, &image.endian);
	(void)points;
	drawmap(image, points, info);
	/*
	t_point p1 = {0, 0, 0};
	t_point p2 = {info.mapwidth, 0, 0};
	t_point p3 = {0, SH - 2, 0};
	t_point p4 = {info.mapwidth, SH - 2, 0};
	drawline(image, p1, p2);
	drawline(image, p1, p3);
	drawline(image, p3, p4);
	drawline(image, p2, p4);
	*/
	mlx_put_image_to_window(mlx, win, imageptr, info.ox, 0);
	mlx_loop(mlx);
}

void	print_points(t_fdf_info info, t_point *points)
{
	for (size_t i = 0; i < info.rows * info.cols; i++)
		ft_printf("i %d, x: %d, y: %d, z: %d\n",
			i, points[i].x, points[i].y, points[i].z);
}

void	render(char *filename)
{
	t_fdf_info	info;
	int		**alts;
	t_point		*points;

	info = get_fdf_info(filename);
	ft_printf("rows: %d\n", info.rows);
	ft_printf("cols: %d\n", info.cols);
	alts = get_altitudes(filename, info);
	points = get_points(info, alts);
//	print_points(info, points);
	show(points, info);
}

int		main(int argc, char **argv)
{
	if (argc != 2)
		ft_printf("usage: fdf map\n");
	else
		render(argv[1]);
}
