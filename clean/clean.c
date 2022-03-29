#include "../cub.h"

void	free_content(void *cont)
{
	free(cont);
}

static void	free_map(t_all *cub);

void	free_all(t_all *cub)
{
	free_map(cub);
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