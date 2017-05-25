/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 22:00:10 by mnunnari          #+#    #+#             */
/*   Updated: 2017/05/24 19:14:20 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	show(t_point *points, t_fdf_info info)
{
	void	*mlx;
	void	*win;

	mlx = mlx_init();
	win = mlx_new_window(mlx, SW, SH, "mlx 42");
	mlx_key_hook(win,key_handler, 0);
	drawmap(mlx, win, points, info);

	t_point p1 = {info.ox, 0,0};
	t_point p2 = {info.mapwidth + info.ox, 0, 0};
	t_point p3 = {info.ox, SH - 1, 0};
	t_point p4 = {info.mapwidth + info.ox, SH - 1, 0};
	drawline(mlx, win, p1, p2);
	drawline(mlx, win, p1, p3);
	drawline(mlx, win, p3, p4);
	drawline(mlx, win, p2, p4);

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
