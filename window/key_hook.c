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
		cub->plr->y -= 10.;
	if (key == A)
		cub->plr->x -= 10.;
	if (key == S)
		cub->plr->y += 10.;
	if (key == D)
		cub->plr->x += 10.;
}

int	close_win(int key)
{
	(void)key;
	exit (0);
}