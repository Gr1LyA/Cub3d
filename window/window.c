#include "../cub.h"

static int	close_win(int key)
{
	(void)key;
	exit (0);
}

static int	key_hook(int key, t_all *cub)
{
	// printf("key = %d\n", key);
	if (key == 65307)
		exit (0);
	return (0);
}

void	init_window(t_all *cub)
{
	cub->win->mlx = mlx_init();
	cub->win->win = mlx_new_window(cub->win->mlx, WIDTH, HEIGHT, "Cub");
	// mlx_hook(cub->win->win, 0, 0, key_hook, cub);
	mlx_key_hook(cub->win->win, key_hook, cub);
	mlx_hook(cub->win->win, 17, 0, close_win, NULL);
	// mlx_loop_hook(cub->win->mlx, get_image, vars);
	mlx_loop(cub->win->mlx);
}