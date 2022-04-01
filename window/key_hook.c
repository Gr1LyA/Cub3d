#include "../cub.h"

static void key_plr(int key, t_all *cub);

int	key_hook(int key, t_all *cub)
{
	// printf("key = %d\n", key);
	if (key == ESC)
		exit (0);
	else
		key_plr(key, cub);
	image_cub(cub);
	return (0);
}

static void key_plr(int key, t_all *cub)
{
	if (key == W)
	{
		if (cub->map[(int)floor((cub->plr->y - 10.) / SCALE)][(int)floor(cub->plr->x / SCALE)] != '1')
			cub->plr->y -= SCALE;
	}
	if (key == A)
	{
		if (cub->map[(int)floor((cub->plr->y) / SCALE)][(int)floor((cub->plr->x  - 10.)/ SCALE)] != '1')
			cub->plr->x -= SCALE;
	}
	if (key == S)
	{
		if (cub->map[(int)floor((cub->plr->y + 10. + (float)SCALE / 2) / SCALE)][(int)floor(cub->plr->x / SCALE)] != '1')
			cub->plr->y += SCALE;
	}
	if (key == D)
	{
		if (cub->map[(int)floor((cub->plr->y) / SCALE)][(int)floor((cub->plr->x  + 10. + (float)SCALE / 2)/ SCALE)] != '1')
			cub->plr->x += SCALE;
	}
}

int	close_win(int key)
{
	(void)key;
	exit (0);
}