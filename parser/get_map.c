#include "../cub.h"

static void	map_to_mass(t_list *head, t_all *cub, int size)
{
	t_list	*tmp;
	size_t	i;

	tmp = head;
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
		// printf("%s\n", cub->map[i]);
	}
	ft_lstclear(&head, free_content);
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
		ft_lstadd_back(&head, ft_lstnew(line));
	}
	if (!line)
			exit (EXIT_FAILURE);
	ft_lstadd_back(&head, ft_lstnew(line));
	return (map_to_mass(head, cub, ft_lstsize(head)));
}