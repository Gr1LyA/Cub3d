#include "../cub.h"

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
				cub->plr->y = (float)i;
				cub->plr->x = (float)j;
				flag++;
			}
		}
	}
	if (flag != 1)
		exit (error_mess("error plr\n"));
}