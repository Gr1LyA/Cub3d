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
	mlx_destroy_image(cub->win->mlx, cub->i[0]);
	mlx_destroy_image(cub->win->mlx, cub->i[1]);
	mlx_destroy_image(cub->win->mlx, cub->i[2]);
	mlx_destroy_image(cub->win->mlx, cub->i[3]);
	mlx_destroy_window(cub->win->mlx, cub->win->win);
	mlx_destroy_display(cub->win->mlx);
	free(cub->win->nor);
	free(cub->win->sou);
	free(cub->win->wes);
	free(cub->win->eas);
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
