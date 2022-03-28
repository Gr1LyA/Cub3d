#include "cub.h"

int	main(int ac, char **av)
{
	t_all	cub;
	t_list	lst;

	if (take_map(av[1], &cub))
		return (1);
	free_all(&cub);
	return (0);
}