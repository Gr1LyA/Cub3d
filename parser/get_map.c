#include "../cub.h"

static void sub_compare(char *str, char**dest)
{
	while (*str >= 9 && *str <= 13 || *str == ' ')
		str++;
	*dest = ft_strdup(str);
		// printf("dest = '%s'\n", *dest);
	if (!*dest)
		exit (EXIT_FAILURE);
}

static void	compare(char *str, t_all *cub, int flag[2])
{
	// char **color;

	if (!ft_strncmp("NO ", str, 3))
		return (sub_compare(str + 2, &(cub->win->north)));
	else if (!ft_strncmp("SO ", str, 3))
		return (sub_compare(str + 2, &(cub->win->south)));
	else if (!ft_strncmp("WE ", str, 3))
		return (sub_compare(str + 2, &(cub->win->west)));
	else if (!ft_strncmp("EA ", str, 3))
		return (sub_compare(str + 2, &(cub->win->east)));
	//далее условия для цвета пола и потолка
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
	// color = ft_split(str, ',');//возможно цвета лучше перевести в int сразу
}

static void	get_texture(t_list **head, t_all *cub)
{
	size_t	i;
	int		flag[2];

	flag[0] = 0;//флаг на то что был цвет для пола
	flag[1] = 0;//флаг на то что был цвет для потолка
	i = -1;
	while (++i < 6)
	{
		compare((*head)->content, cub, flag);
		(*head) = (*head)->next;
	}
	if (cub->win->north == NULL || cub->win->south == NULL
		|| cub->win->west == NULL || cub->win->east == NULL)
		exit (error_mess("map_error"));
	if (flag[0] != 1 || flag[1] != 1)
		exit (error_mess("map_error"));
}

static void	map_to_mass(t_list *head, t_all *cub, int size)
{
	t_list	*tmp;
	int		i;
	size_t	m;

	if (size <= 0)
		exit (error_mess("map"));
	tmp = head;

	get_texture(&tmp, cub);//получаю пути к текстурам и цветам
	// printf("no = '%s'\nso = '%s'\nwe = '%s'\nea = '%s'\n", cub->win->north, cub->win->south, cub->win->west, cub->win->east);
	
	// printf("\nsize = %d\n\n", size);
	cub->map = ft_calloc(size + 1, sizeof(char *));
	if (!cub->map)
		exit (EXIT_FAILURE);
	i = -1;//после путей до текстур и цветов
	while (++i < size)
	{		
		cub->map[i] = ft_strdup(tmp->content);
		// m = ft_findchr(cub->map[i], '')
		if (!cub->map[i])
			exit (EXIT_FAILURE);
		// printf("%s\n", cub->map[i]);
		tmp = tmp->next;
	}
	ft_lstclear(&head, free_content);
	x_y_plr(cub);
}

void	take_map(char *name, t_all *cub)
{
	int		fd;
	char	*line;
	t_list	*head = NULL;

	fd = open(name, O_RDONLY);
	if (fd == -1)
		exit (error_mess("file"));
	while (get_next_line(fd, &line))
	{
		if (!line)
			exit (EXIT_FAILURE);
		if (!ft_strncmp("", line, 1))
			free(line);
		else
			ft_lstadd_back(&head, ft_lstnew(line));
	}
	if (!line)
			exit (EXIT_FAILURE);
	if (!ft_strncmp("", line, 1))
		free(line);
	else
		ft_lstadd_back(&head, ft_lstnew(line));
	close (fd);
	return (map_to_mass(head, cub, ft_lstsize(head) - 6));
}