#include "../cub.h"

int	close_win(int key)
{
	(void)key;
	exit (0);
}

int	key_hook(int key, t_all *cub)
{
	// printf("key = %d\n", key);
	if (key == ESC)
		exit (0);
	if (key == W)
		cub->plr->y -= 10. / SCALE;
	if (key == A)
		cub->plr->x -= 10. / SCALE;
	if (key == S)
		cub->plr->y += 10. / SCALE;
	if (key == D)
		cub->plr->x += 10. / SCALE;
	image_cub(cub);
	return (0);
}