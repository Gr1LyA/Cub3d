#include "cub.h"

static void	init(t_all *cub)
{
	cub->win = malloc(sizeof(t_win));
	cub->plr = malloc(sizeof(t_plr));
	if (!cub->win || !cub->plr)
		exit (0);
	cub->win->north = NULL;
	cub->win->south = NULL;
	cub->win->west = NULL;
	cub->win->east = NULL;
}

int	main(int ac, char **av)
{
	t_all	cub;

	if (ac != 2)
		exit (error_mess("arg"));
	init(&cub);
	take_map(av[1], &cub);
	exit (0);
	init_window(&cub);
	free_all(&cub);
	return (0);
}