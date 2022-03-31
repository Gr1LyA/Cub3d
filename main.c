#include "cub.h"

static void	init(t_all *cub)
{
	cub->win = malloc(sizeof(t_win));
	cub->plr = malloc(sizeof(t_plr));
	if (!cub->win || !cub->plr)
		exit (error_mess("error malloc"));
	cub->win->north = NULL;
	cub->win->south = NULL;
	cub->win->west = NULL;
	cub->win->east = NULL;
}

static void check_print(t_all cub)
{
	printf("x = %f\ny = %f\nno = '%s'\nso = '%s'\nwe = '%s'\nea = '%s'\nfloor = %d\nceiling = %d\n", cub.plr->x, cub.plr->y, cub.win->north, cub.win->south, cub.win->west, cub.win->east, cub.win->floor, cub.win->ceiling);
	for (size_t i = 0; cub.map[i]; i++)
		printf("%s\n", cub.map[i]);
}

int	main(int ac, char **av)
{
	t_all	cub;

	if (ac != 2)
		exit (error_mess("arg"));
	init(&cub);
	take_map(av[1], &cub);
	check_print(cub);
	init_window(&cub);
	free_all(&cub);
	return (0);
}