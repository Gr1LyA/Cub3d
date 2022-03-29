#include "../cub.h"

static void	find_config(char *str, t_all *cub)
{
		// char tmp;

		// if (!ft_strncmp("NO ", str, 3) || !ft_strncmp("SO ", str, 3)
		// 	|| !ft_strncmp("WE ", str, 3) || !ft_strncmp("EA ", str, 3))
		// {
		// 	while (*str >= 9 && *str <= 13)
		// 		str++;
		// }
}

void	check_map(t_all *cub)
{
	size_t	i;
	size_t	j;

	i = -1;
	while (cub->map[++i])
	{
		while (!ft_strncmp("\n", cub->map[i], 2))
			i++;
		find_config(cub->map[i], cub);
	}
}