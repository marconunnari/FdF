#include "fdf.h"

int		my_key_funct(int keycode, void *param)
{
	(void)param;
	printf("key event %d\n", keycode);
	if (keycode == 53 || keycode == 65307)
		exit(0);
	return (0);
}

int		my_mouse_funct(int button,int x,int y,void *param)
{
	(void)param;
	printf("button %d, x %d, y %d\n", button, x, y);
	return (0);
}

int		main(int argc, char **argv)
{
	void	*mlx;
	void	*win;
	t_point	p1;
	t_point	p2;

	if (argc != 5)
	{
		printf("usage: a.out x1 y1 x2 y2\n");
		exit(0);
	}
	setbuf(stdout, NULL);
	mlx = mlx_init();
	win = mlx_new_window(mlx, 400, 400, "mlx 42");
	mlx_key_hook(win, my_key_funct, 0);
	mlx_mouse_hook(win, my_mouse_funct, 0);
	p1.x = atoi(argv[1]);
	p1.y = atoi(argv[2]);
	p2.x = atoi(argv[3]);
	p2.y = atoi(argv[4]);
	drawline(mlx, win, p1, p2);
	mlx_loop(mlx);
}
