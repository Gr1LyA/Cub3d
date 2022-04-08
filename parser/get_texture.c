#include "../cub.h"

static void	sub_compare(char *str, char**dest)
{
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	*dest = ft_strdup(str);
	if (!*dest)
		exit (EXIT_FAILURE);
}

static void	compare(char *str, t_all *cub, int flag[2])
{
	if (!ft_strncmp("NO ", str, 3))
		return (sub_compare(str + 2, &(cub->win->nor)));
	else if (!ft_strncmp("SO ", str, 3))
		return (sub_compare(str + 2, &(cub->win->sou)));
	else if (!ft_strncmp("WE ", str, 3))
		return (sub_compare(str + 2, &(cub->win->wes)));
	else if (!ft_strncmp("EA ", str, 3))
		return (sub_compare(str + 2, &(cub->win->eas)));
	if (!ft_strncmp("F  ", str, 2))
	{
		color(str + 1, &(cub->win->floor));
		flag[0]++;
	}
	else if (!ft_strncmp("C  ", str, 2))
	{
		color(str + 1, &(cub->win->ceiling));
		flag[1]++;
	}
}

void	get_texture(t_list **head, t_all *cub)
{
	size_t	i;
	int		flag[2];

	flag[0] = 0;
	flag[1] = 0;
	i = -1;
	while (++i < 6)
	{
		compare((*head)->content, cub, flag);
		(*head) = (*head)->next;
	}
	if (cub->win->nor == NULL || cub->win->sou == NULL
		|| cub->win->wes == NULL || cub->win->eas == NULL)
		exit (error_mess("map_error"));
	if (flag[0] != 1 || flag[1] != 1)
		exit (error_mess("map_error"));
}
