#include "cub.h"

int	main(int ac, char **av)
{
	t_all	cub;

	printf("A:LO");
	if (ac != 2)
		exit (error_mess("arg"));
	take_map(av[1], &cub);
	init_window(&cub);
	free_all(&cub);
	return (0);
}