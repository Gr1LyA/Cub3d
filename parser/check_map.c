#include "../cub.h"

static void	check_str(char **map, size_t i);

static void	check_space_middle(char **map, size_t i, size_t *j);

static void	check_space_first(char **map, size_t i, size_t *j);

static void	check_space_last(char **map, size_t i, size_t *j);

void	check_map(char **map)
{
	size_t	i;

	i = -1;
	while (map[++i])
		check_str(map, i);
}

static void	check_str(char **map, size_t i)
{
	size_t	j;
	size_t	start_space;
	size_t	end_space;

	j = -1;
	while (map[i][++j])
	{
		if (map[i][j] != '0' && map[i][j] != '1'
			&& map[i][j] != 'N' && map[i][j] != 'S'
			&& map[i][j] != 'E' && map[i][j] != 'W'
			&& map[i][j] != ' ')
			exit (error_mess("error map"));
		if (map[i][j] == ' ' && i == 0)
			check_space_first(map, i, &j);
		else if (map[i][j] == ' ' && map[i + 1] == NULL)
			check_space_last(map, i, &j);
	}
}

static void	check_space_first(char **map, size_t i, size_t *j)
{
	size_t	start_space;
	size_t	end_space;
	size_t	len_next_line;

	start_space = *j;
	end_space = start_space;
	while (map[i][end_space] == ' ' && map[i][end_space] != '\0')
		end_space++;
	if (start_space != 0 && map[i][start_space - 1] != '1'
		|| start_space != 0 && (map[i + 1][start_space - 1] != '1' && map[i + 1][start_space - 1] != ' '))
		exit (error_mess("map error"));
	if (map[i][end_space] != '1' && map[i][end_space] != '\0')
		exit (error_mess("map error"));
	//осталось проверить след строку
	// len_next_line = ft_strlen(map[i + 1]);
	// if
}

static void	check_space_last(char **map, size_t i, size_t *j)
{

}

static void	check_space_middle(char **map, size_t i, size_t *j)
{
	size_t	start_space;
	size_t	end_space;

	start_space = *j;
	end_space = start_space;
	while (map[i][*j] == ' ')
		end_space++;
	if (map[i][end_space] != '1' && map[i][end_space] != '\0')
		exit (error_mess("map error"));
}