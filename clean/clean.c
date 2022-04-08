#include "../cub.h"

static void	free_map(t_all *cub);

void	free_content(void *cont)
{
	free(cont);
}

void	free_all(t_all *cub)
{
	free_map(cub);
	mlx_destroy_image(cub->win->mlx, cub->win->img);
	mlx_destroy_image(cub->win->mlx, cub->img[0]);
	mlx_destroy_image(cub->win->mlx, cub->img[1]);
	mlx_destroy_image(cub->win->mlx, cub->img[2]);
	mlx_destroy_image(cub->win->mlx, cub->img[3]);
	mlx_destroy_window(cub->win->mlx, cub->win->win);
	mlx_destroy_display(cub->win->mlx);
	free(cub->win->north);
	free(cub->win->south);
	free(cub->win->west);
	free(cub->win->east);
	free(cub->win);
	free(cub->plr);
}

static void	free_map(t_all *cub)
{
	size_t	i;

	i = -1;
	while (cub->map[++i])
		free(cub->map[i]);
	free(cub->map);
}
