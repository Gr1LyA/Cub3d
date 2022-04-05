#include "../cub.h"

static void	check_wall(char **map, size_t i, size_t j);

static void	check_space_first(char **map, size_t j);

static void	check_space_last(char **map, size_t j);

static void	check_space_middle(char **map, size_t j);

static int	check_char(char s);

static void check_null(char **map);

void	check_map(char **map)
{
	size_t	i;
	size_t	j;

	i = -1;
	while (map[++i])//первая и последняя строка могут быть единицы и пробелы
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] != ' ' && map[i][j] != '1' && map[i][j] != '0'
				&& map[i][j] != 'W'  && map[i][j] != 'E' && map[i][j] != 'S'
				&& map[i][j] != 'N')
				exit (error_mess("map error"));
		}
	}
	if (i < 2)
		exit (error_mess("map error"));
	check_space_first(map, 0);
	j = 0;
	while (++j < i - 1)
		check_space_middle(map, j);//начинаю со второй строки
	check_space_last(map, i - 1);
	check_null(map);
}

static void check_null(char **map)
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

static void	check_space_first(char **map, size_t j)
{
	size_t	i;
	size_t	st_sp;
	size_t	en_sp;

	i = 0;
	while (map[j][i])
	{
		while (map[j][i] && map[j][i] != ' ')
			i++;
		if (!map[j][i])
			return ;
		st_sp = i;
		en_sp = i;
		while (map[j][en_sp] && map[j][en_sp] == ' ')
			en_sp++;
		i += (en_sp - st_sp);		
		if (st_sp != 0)
			st_sp -= 1;
		if (map[j][en_sp])
			en_sp += 1;
		while (map[j + 1][st_sp] && st_sp < en_sp)
		{
			if (map[j + 1][st_sp] != ' ' && map[j + 1][st_sp] != '1')
				exit (error_mess("map error"));
			st_sp++;
		}
	}
}

static void	check_space_last(char **map, size_t j)
{
	size_t	i;
	size_t	st_sp;
	size_t	en_sp;
	printf("j = %zu\n", j);

	i = 0;
	while (map[j][i])
	{
		while (map[j][i] && map[j][i] != ' ')
			i++;
		if (!map[j][i])
			return ;
		st_sp = i;
		en_sp = i;
		while (map[j][en_sp] && map[j][en_sp] == ' ')
			en_sp++;
		i += (en_sp - st_sp);		
		if (st_sp != 0)
			st_sp -= 1;
		if (map[j][en_sp])
			en_sp += 1;
		while (map[j - 1][st_sp] && st_sp < en_sp)
		{
			if (map[j - 1][st_sp] != ' ' && map[j - 1][st_sp] != '1')
				exit (error_mess("map error"));
			st_sp++;
		}
	}
}

static void	check_space_middle(char **map, size_t j)
{
	check_space_last(map, j);
	check_space_first(map, j);
}
