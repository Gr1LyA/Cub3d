#include "../cub.h"

static void key_plr(int key, t_all *cub);

static void row_plr(int key, t_all *cub);

static int	wall(t_all *cub, float x, float y);

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

static void row_plr(int key, t_all *cub)
{
	if (key == LEFT)
		cub->plr->dir -= (0.1 * M_PI);
	if (key == RIGHT)
		cub->plr->dir += (0.1 * M_PI);
}

static void key_plr(int key, t_all *cub)
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
	if (!wall(cub, cub->plr->x, cub->plr->y))
	{
		cub->plr->x = prev_x;
		cub->plr->y = prev_y;
	}
}

static int	wall(t_all *cub, float x, float y)//вернуть один если можно шагнуть
{
	if (cub->map[(int)y][(int)x] == '1')
		return (0);
	return (1);
}

int	close_win(int key, t_all *cub)
{
	(void)key;
	free_all(cub);
	exit (0);
}