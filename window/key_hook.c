#include "../cub.h"

static void key_plr(int key, t_all *cub);

static void row_plr(int key, t_all *cub);

static int	wall(t_all *cub, float x, float y);

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
		cub->plr->dir -= (0.1 * M_PI);
	if (key == RIGHT)
		cub->plr->dir += (0.1 * M_PI);
	// printf("cub->plr->dir = %f\n",cub->plr->dir);
}

static void key_plr(int key, t_all *cub)
{
	if (key == W && wall(cub, cub->plr->x + STEP * cos(cub->plr->dir),
		cub->plr->y + STEP * sin(cub->plr->dir)))
	{
		// if (cub->map[(int)((cub->plr->y - STEP) / SCALE)][(int)(cub->plr->x / SCALE)] != '1')
			// cub->plr->y -= STEP;
		cub->plr->x += STEP * cos(cub->plr->dir);
		cub->plr->y += STEP * sin(cub->plr->dir);
	}
	if (key == A && wall(cub, cub->plr->x - STEP * cos(cub->plr->dir + (M_PI / 2)),
		cub->plr->y - STEP * cos(cub->plr->dir + (M_PI / 2))))
	{
		// if (cub->map[(int)((cub->plr->y) / SCALE)][(int)((cub->plr->x  - STEP)/ SCALE)] != '1')
			// cub->plr->x -= STEP;
		cub->plr->x -= STEP * cos(cub->plr->dir + (M_PI / 2));
		cub->plr->y -= STEP * sin(cub->plr->dir + (M_PI / 2));
	}
	if (key == S && wall(cub, cub->plr->x - STEP * cos(cub->plr->dir),
		cub->plr->y - STEP * sin(cub->plr->dir)))
	{
		// if (cub->map[(int)((cub->plr->y + STEP) / SCALE)][(int)(cub->plr->x / SCALE)] != '1')
			// cub->plr->y += STEP;
		cub->plr->x -= STEP * cos(cub->plr->dir);
		cub->plr->y -= STEP * sin(cub->plr->dir);
	}
	if (key == D && wall(cub, cub->plr->x - STEP * cos(cub->plr->dir - (M_PI / 2)),
		cub->plr->y - STEP * cos(cub->plr->dir - (M_PI / 2))))
	{
		cub->plr->x -= STEP * cos(cub->plr->dir - (M_PI / 2));
		cub->plr->y -= STEP * sin(cub->plr->dir - (M_PI / 2));
		// if (cub->map[(int)((cub->plr->y) / SCALE)][(int)((cub->plr->x  + STEP)/ SCALE)] != '1')
			// cub->plr->x += STEP;
	}
}

static int	wall(t_all *cub, float x, float y)
{
	// if (cub->map[(int)(x)][(int)(y)] == '1' && x >= 0 && y >= 0)// && ceil(x) == floor(x) && ceil(y) == floor(y))
	// printf("x = %f, y = %f\n", x, y);
	// if (x >= ft_strlen(cub->map[(int)y]) || cub->map[(int)(x)][(int)(y)] == '1')
	// 	return (0);
	return (1);
}

int	close_win(int key)
{
	(void)key;
	exit (0);
}