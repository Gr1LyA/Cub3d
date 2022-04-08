#include "../cub.h"

static void	map_to_mass(t_list *head, t_all *cub, int size)
{
	t_list	*tmp;
	int		i;

	if (size <= 0)
		exit (error_mess("map"));
	tmp = head;
	get_texture(&tmp, cub);
	cub->map = ft_calloc(size + 1, sizeof(char *));
	if (!cub->map)
		exit (EXIT_FAILURE);
	i = -1;
	while (++i < size)
	{		
		cub->map[i] = ft_strdup(tmp->content);
		if (!cub->map[i])
			exit (EXIT_FAILURE);
		tmp = tmp->next;
	}
	ft_lstclear(&head, free_content);
	x_y_plr(cub);
}

static void	sub_take_map(char **line, t_all *cub, t_list *head, int fd)
{
	if (!*line)
		exit (EXIT_FAILURE);
	if (!ft_strncmp("", *line, 1))
		free(*line);
	else
		ft_lstadd_back(&head, ft_lstnew(*line));
	close (fd);
	return (map_to_mass(head, cub, ft_lstsize(head) - 6));
}

void	take_map(char *name, t_all *cub)
{
	int		fd;
	char	*line;
	t_list	*head;
	int		i;

	head = NULL;
	fd = open(name, O_RDONLY);
	if (fd == -1)
		exit (error_mess("file"));
	i = 0;
	while (get_next_line(fd, &line))
	{
		if (!line)
			exit (EXIT_FAILURE);
		if (!ft_strncmp("", line, 1) && i < 7)
			free(line);
		else
		{
			ft_lstadd_back(&head, ft_lstnew(line));
			i++;
		}
	}
	return (sub_take_map(&line, cub, head, fd));
}
