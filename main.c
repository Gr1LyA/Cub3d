#include "cub.h"

static void	init(t_all *cub)
{
	cub->win = malloc(sizeof(t_win));
	cub->plr = malloc(sizeof(t_plr));
	if (!cub->win || !cub->plr)
		exit (error_mess("error malloc"));
	cub->win->nor = NULL;
	cub->win->sou = NULL;
	cub->win->wes = NULL;
	cub->win->eas = NULL;
}

int	main(int ac, char **av)
{
	t_all	cub;

	if (ac != 2)
		exit (error_mess("arg error"));
	if (ft_strncmp(av[1] + ft_strlen(av[1]) - 4, ".cub", 5))
		exit (error_mess("error map"));
	init(&cub);
	take_map(av[1], &cub);
	check_map(cub.map);
	init_window(&cub);
	free_all(&cub);
	return (0);
}
