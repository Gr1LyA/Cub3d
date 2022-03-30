#include "../cub.h"

int	ft_findchr(char *str, char ch)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != ch)
		i++;
	if (!str[i])
		return (-1);
	return (i);
}
