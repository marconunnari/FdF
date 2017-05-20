
#include <stdio.h>
#include <stdlib.h>
#include "mlx.h"
#include <math.h>

int		my_key_funct(int keycode, void *param)
{
	printf("key event %d\n", keycode);
	if (keycode == 53)
		exit(0);
	return (0);
}

int		my_mouse_funct(int button,int x,int y,void *param)
{
	printf("button %d, x %d, y %d\n", button, x, y);
	return (0);
}

void	drawline(void *mlx, void *win, int x1, int y1, int x2, int y2)
{
	mlx_pixel_put (mlx, win, x1, y1, 0x00FFFFFF);
	mlx_pixel_put (mlx, win, x2, y2, 0x00FFFFFF);
}

int		main(int argc, char **argv)
{
	void	*mlx;
	void	*win;

	if (argc != 5)
		exit(0);
	setbuf(stdout, NULL);
	mlx = mlx_init();
	win = mlx_new_window(mlx, 400, 400, "mlx 42");
	mlx_key_hook(win, my_key_funct, 0);
	mlx_mouse_hook(win, my_mouse_funct, 0);
	drawline(mlx, win, atoi(argv[1]), atoi(argv[2]), atoi(argv[3]), atoi(argv[4]));
	mlx_loop(mlx);
}
