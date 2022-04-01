#include "../cub.h"

void	color(char *str, u_int32_t *color)
{
	u_int32_t	tmp;
	char		**splt;
	size_t		i;

	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	splt = ft_split(str, ',');
	if (!splt)
		exit (error_mess("malloc"));
	i = 0;
	while (splt[i])
		i++;
	if (i != 3)
		exit (error_mess("error splt"));
	*color = convert_to_decimal(splt);
	i = -1;
	while (splt[++i])
		free(splt[i]);
	free(splt);
}