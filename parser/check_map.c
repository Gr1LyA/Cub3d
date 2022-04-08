#include "../cub.h"

static void	check_space_middle(char **map, size_t j);

static int	check_char(char s);

static void	check_null(char **map);

void	check_map(char **map)
{
	size_t	i;
	size_t	j;

	i = -1;
	while (map[++i])
	{
		if (!ft_strncmp(map[i], "", ft_strlen(map[i])))
			exit (error_mess("map error"));
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] != ' ' && map[i][j] != '1' && map[i][j] != '0'
				&& map[i][j] != 'W' && map[i][j] != 'E' && map[i][j] != 'S'
				&& map[i][j] != 'N')
				exit (error_mess("map error"));
		}
	}
	if (i < 2)
		exit (error_mess("map error"));
	check_space_first(map, 0);
	j = 0;
	while (++j < i - 1)
		check_space_middle(map, j);
	check_space_last(map, i - 1);
	check_null(map);
}

static void	check_null(char **map)
{
	size_t	i;
	size_t	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (check_char(map[i][j]) && j == 0)
				exit (error_mess("map error"));
			else if (check_char(map[i][j]))
			{
				if (!map[i + 1] || j > ft_strlen(map[i + 1]) - 1
					|| i == 0 || j > ft_strlen(map[i - 1]) - 1)
					exit (error_mess("map error"));
				if (map[i][j - 1] != '1')
					exit (error_mess("map error"));
				while (check_char(map[i][j]))
					j++;
				if (!map[i][j] || map[i][j] != '1')
					exit (error_mess("map error"));
			}
		}
	}
}

static int	check_char(char s)
{
	if (s == '0' || s == 'N' || s == 'S' || s == 'E'
		|| s == 'W')
		return (1);
	return (0);
}

static void	check_space_middle(char **map, size_t j)
{
	check_space_last(map, j);
	check_space_first(map, j);
}
