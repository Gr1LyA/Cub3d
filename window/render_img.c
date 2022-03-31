#include "../cub.h"

static void	render_cub(t_all *cub);

static void	paint_black(t_all *cub);

int	image_cub(t_all *cub)
{
	render_cub(cub);
	mlx_put_image_to_window(cub->win->mlx, cub->win->win, cub->win->img, 0, 0);
	return (0);
}

static void	print_square(size_t x, size_t y, t_all *cub, u_int32_t color)
{
	size_t	i;
	size_t	j;

	i = y;
	while (i < (y + SCALE))
	{
		j = x;
		while (j < (x + SCALE))
		{
			my_mlx_pixel_put(cub, j, i, color);
			j++;
		}
		i++;
	}
}

static void	render_cub(t_all *cub)
{
	size_t	i;
	size_t	j;
	size_t	x;
	size_t	y;

	i = 0;
	y = 0;
	while (cub->map[i])
	{
		j = 0;
		x = 0;
		while (cub->map[i][j])
		{
			if (cub->map[i][j] == '1')
				print_square(x, y, cub, 0xffffff);//отрисовываю карту
			else
				print_square(x, y, cub, 0x000000);
			j++;
			x += SCALE;
		}
		y += SCALE;
		i++;
	}
	print_square(cub->plr->x, cub->plr->y, cub, 0x000fff);//отрисовываю персонажа
}
