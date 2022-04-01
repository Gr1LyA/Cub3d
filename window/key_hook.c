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
		if (cub->map[(int)((cub->plr->y - STEP) / SCALE)][(int)(cub->plr->x / SCALE)] != '1')
			cub->plr->y -= STEP;
	}
	if (key == A)
	{
		if (cub->map[(int)((cub->plr->y) / SCALE)][(int)((cub->plr->x  - STEP)/ SCALE)] != '1')
			cub->plr->x -= STEP;
	}
	if (key == S)
	{
		if (cub->map[(int)((cub->plr->y + STEP + SCALE / 2) / SCALE)][(int)(cub->plr->x / SCALE)] != '1')
			cub->plr->y += STEP;
	}
	if (key == D)
	{
		if (cub->map[(int)((cub->plr->y) / SCALE)][(int)((cub->plr->x  + STEP + SCALE / 2)/ SCALE)] != '1')
			cub->plr->x += STEP;
	}
}

int	close_win(int key)
{
	(void)key;
	exit (0);
}