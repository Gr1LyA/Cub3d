#include "../cub.h"

int	error_mess(char *error)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(error, 2);
	return (1);
}
