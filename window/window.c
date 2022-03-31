#include "../cub.h"

static int	close_win(int key)
{
	(void)key;
	exit (0);
}

static int	key_hook(int key, t_all *cub)
{
	// printf("key = %d\n", key);
	if (key == ESC)
		exit (0);
	if (key == W)
		cub->plr->y -= 10. / SCALE;
	if (key == A)
		cub->plr->x -= 10. / SCALE;
	if (key == S)
		cub->plr->y += 10. / SCALE;
	if (key == D)
		cub->plr->x += 10. / SCALE;
		// image_cub(cub);
	return (0);
}

void	init_window(t_all *cub)
{
	cub->win->mlx = mlx_init();
	cub->win->win = mlx_new_window(cub->win->mlx, WIDTH, HEIGHT, "Cub");
	mlx_key_hook(cub->win->win, key_hook, cub);
	mlx_hook(cub->win->win, 17, 0, close_win, NULL);
	// image_cub(cub);
	mlx_loop_hook(cub->win->mlx, image_cub, cub);
	mlx_loop(cub->win->mlx);
}