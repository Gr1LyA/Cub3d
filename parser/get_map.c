#include "../cub.h"

static int	map_to_mass(t_list *head, t_all *cub, int size)
{
	t_list	*tmp;
	size_t	i;

	tmp = head;
	cub->map = ft_calloc(size + 1, sizeof(char *));
	if (!cub->map)
		return (1);
	i = -1;
	while (++i < size)
	{
		cub->map[i] = ft_strdup(tmp->content);
		if (!cub->map[i])
			return (1);
		tmp = tmp->next;
		printf("%s\n", cub->map[i]);
	}
	ft_lstclear(&head, free_content);
	return (0);
}

int	take_map(char *name, t_all *cub)
{
	int		fd;
	char	*line;
	t_list	*head = NULL;

	fd = open(name, O_RDONLY);
	while (get_next_line(fd, &line))
	{
		if (!line)
			return (1);
		ft_lstadd_back(&head, ft_lstnew(line));
	}
	if (!line)
			return (1);
	ft_lstadd_back(&head, ft_lstnew(line));
	return (map_to_mass(head, cub, ft_lstsize(head)));
}