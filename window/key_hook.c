#include "../cub.h"

static void key_plr(int key, t_all *cub);

static void row_plr(int key, t_all *cub);

int	key_hook(int key, t_all *cub)
{
	if (key == ESC)
		exit (0);
	key_plr(key, cub);
	row_plr(key, cub);
	image_cub(cub);
	return (0);
}

static void row_plr(int key, t_all *cub)
{
	// printf("key = %d\n, cub->plr->dir = %f", key, cub->plr->dir);

	if (key == LEFT)
		cub->plr->dir -= 0.25;
	if (key == RIGHT)
		cub->plr->dir += 0.25;
	// printf("cub->plr->dir = %f\n",cub->plr->dir);
}

static void key_plr(int key, t_all *cub)
{
	if (key == W)
	{
		// if (cub->map[(int)((cub->plr->y - STEP) / SCALE)][(int)(cub->plr->x / SCALE)] != '1')
			cub->plr->y -= STEP;
	}
	if (key == A)
	{
		// if (cub->map[(int)((cub->plr->y) / SCALE)][(int)((cub->plr->x  - STEP)/ SCALE)] != '1')
			cub->plr->x -= STEP;
	}
	if (key == S)
	{
		// if (cub->map[(int)((cub->plr->y + STEP) / SCALE)][(int)(cub->plr->x / SCALE)] != '1')
			cub->plr->y += STEP;
	}
	if (key == D)
	{
		// if (cub->map[(int)((cub->plr->y) / SCALE)][(int)((cub->plr->x  + STEP)/ SCALE)] != '1')
			cub->plr->x += STEP;
	}
}

int	close_win(int key)
{
	(void)key;
	exit (0);
}