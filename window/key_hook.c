#include "../cub.h"

static void	key_plr(int key, t_all *cub);

static void	row_plr(int key, t_all *cub);

static void	kostyl_key_plr(int key, t_all *cub, float prev_x, float prev_y);

int	key_hook(int key, t_all *cub)
{
	if (key == ESC)
	{
		free_all(cub);
		exit (0);
	}
	key_plr(key, cub);
	row_plr(key, cub);
	image_cub(cub);
	return (0);
}

static void	row_plr(int key, t_all *cub)
{
	if (key == LEFT)
		cub->plr->dir -= (0.1 * M_PI);
	if (key == RIGHT)
		cub->plr->dir += (0.1 * M_PI);
}

static void	key_plr(int key, t_all *cub)
{
	float	prev_x;
	float	prev_y;

	prev_x = cub->plr->x;
	prev_y = cub->plr->y;
	if (key == W)
	{
		cub->plr->x += STEP * cos(cub->plr->dir);
		cub->plr->y += STEP * sin(cub->plr->dir);
	}
	if (key == A)
	{
		cub->plr->x -= STEP * cos(cub->plr->dir + (M_PI / 2));
		cub->plr->y -= STEP * sin(cub->plr->dir + (M_PI / 2));
	}
	kostyl_key_plr(key, cub, prev_x, prev_y);
}

static void	kostyl_key_plr(int key, t_all *cub, float prev_x, float prev_y)
{
	if (key == S)
	{
		cub->plr->x -= STEP * cos(cub->plr->dir);
		cub->plr->y -= STEP * sin(cub->plr->dir);
	}
	if (key == D)
	{
		cub->plr->x -= STEP * cos(cub->plr->dir - (M_PI / 2));
		cub->plr->y -= STEP * sin(cub->plr->dir - (M_PI / 2));
	}
	if (cub->map[(int)cub->plr->y][(int)cub->plr->x] == '1')
	{
		cub->plr->x = prev_x;
		cub->plr->y = prev_y;
	}
}

int	close_win(int key, t_all *cub)
{
	(void)key;
	free_all(cub);
	exit (0);
}
