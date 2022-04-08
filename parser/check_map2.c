#include "../cub.h"

static void	kostyl(char **map, size_t j, size_t *st_sp, size_t *en_sp);

void	check_space_first(char **map, size_t j)
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
		kostyl(map, j, &st_sp, &en_sp);
		while (map[j + 1][st_sp] && st_sp < en_sp)
		{
			if (map[j + 1][st_sp] != ' ' && map[j + 1][st_sp] != '1')
				exit (error_mess("map error"));
			st_sp++;
		}
	}
}

void	check_space_last(char **map, size_t j)
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
		kostyl(map, j, &st_sp, &en_sp);
		while (map[j - 1][st_sp] && st_sp < en_sp)
		{
			if (map[j - 1][st_sp] != ' ' && map[j - 1][st_sp] != '1')
				exit (error_mess("map error"));
			st_sp++;
		}
	}
}

static void	kostyl(char **map, size_t j, size_t *st_sp, size_t *en_sp)
{
	if (*st_sp != 0)
		(*st_sp) -= 1;
	if (map[j][*en_sp])
		(*en_sp) += 1;
}
