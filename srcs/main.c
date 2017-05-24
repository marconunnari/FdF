/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 22:00:10 by mnunnari          #+#    #+#             */
/*   Updated: 2017/05/23 22:32:21 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	show(t_point *points, t_fdf_info info)
{
	void	*mlx;
	void	*win;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 600, 600, "mlx 42");
	mlx_key_hook(win,key_handler, 0);
	draw_map(mlx, win, points, info);
	mlx_loop(mlx);
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
	for (size_t i = 0; i < info.rows * info.cols; i++)
		ft_printf("i %d, x: %d, y: %d, z: %d\n",
			i, points[i].x, points[i].y, points[i].z);
	show(points, info);
}

int		main(int argc, char **argv)
{
	if (argc != 2)
		ft_printf("usage: fdf map\n");
	else
		render(argv[1]);
}
