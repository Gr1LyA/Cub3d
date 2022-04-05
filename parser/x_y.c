#include "../cub.h"

static void plr_ray(char s, t_all *cub);

static void spawn(char s, t_all *cub, size_t i, size_t j);

void	x_y_plr(t_all *cub)
{
	size_t	i;
	size_t	j;
	char	s;
	int		flag;

	i = -1;
	flag = 0;
	while (cub->map[++i])
	{
		j = -1;
		while (cub->map[i][++j])
		{
			s = cub->map[i][j];
			if (s == 'N' || s == 'W' || s == 'E' || s == 'S')
			{
				spawn(s, cub, i, j);
				flag++;
				plr_ray(s, cub);
			}
		}
	}
	if (flag != 1)
		exit (error_mess("error plr\n"));
}

static void spawn(char s, t_all *cub, size_t i, size_t j)
{
	cub->plr->y = (float)i * SCALE + ((float)SCALE / 2);
	cub->plr->x = (float)j * SCALE + ((float)SCALE / 2);
}

static void plr_ray(char s, t_all *cub)
{
	if (s == 'N')
		cub->plr->dir = - M_PI_2;
	else if (s == 'S')
		cub->plr->dir = + M_PI_2;
	else if (s == 'W')
		cub->plr->dir = M_PI;
	else if (s == 'E')
		cub->plr->dir = 0;
	// cub->plr->start = cub->plr->dir - M_PI_4;
	// cub->plr->end = cub->plr->dir + M_PI_4;
}