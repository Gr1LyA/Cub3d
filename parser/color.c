#include "../cub.h"

void	color(char *str, u_int32_t *color)
{
	char		**splt;
	size_t		i;

	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	splt = ft_split(str, ',');
	if (!splt)
		exit (error_mess("malloc"));
	i = -1;
	while (splt[++i])
	{
		if (i >= 3 || !(ft_atoi(splt[i]) >= 0 && ft_atoi(splt[i]) <= 255))
			exit (error_mess("rgb error"));
	}
	*color = convert_to_decimal(splt);
	i = -1;
	while (splt[++i])
		free(splt[i]);
	free(splt);
}
