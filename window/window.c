#include "../cub.h"

void	init_window(t_all *cub)
{
	cub->win->mlx = mlx_init();
	cub->win->win = mlx_new_window(cub->win->mlx, WIDTH, HEIGHT, "Cub");
	mlx_hook(cub->win->win, 2, 0, key_hook, cub);
	mlx_hook(cub->win->win, 17, 0, close_win, NULL);
	cub->win->img = mlx_new_image(cub->win->mlx, WIDTH, HEIGHT);
	cub->win->addr = mlx_get_data_addr(cub->win->img, &cub->win->bpp
		, &cub->win->len, &cub->win->endian);
	set_texture(cub);
	image_cub(cub);
	mlx_loop(cub->win->mlx);
}