#include "../cub.h"
#include <stddef.h>
#include <sys/types.h>

static void	render_cub(t_all *cub);

int	image_cub(t_all *cub)
{
	t_win	*img;

	img = cub->win;
	img->img = mlx_new_image(cub->win->mlx, WIDTH, HEIGHT);
	img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->len, &img->endian);
	render_cub(cub);
	mlx_put_image_to_window(cub->win->mlx, cub->win->win, img->img, 0, 0);
	free(img->img);
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
	// printf("\n\n ALLOOOOO \n\n");
	y = 0;
	while (cub->map[i])
	{
		j = 0;
		x = 0;
		while (cub->map[i][j])
		{
			if (cub->map[i][j] == '1')
				print_square(x, y, cub, 0xffffff);//отрисовываю карту
			j++;
			x += SCALE;
		}
		y += SCALE;
		i++;
	}
	print_square(cub->plr->x * SCALE, cub->plr->y * SCALE, cub, 0x000fff);//отрисовываю персонажа
}

// static void	render_cub(t_all *cub)
// {
// 	// int x;
// 	// int y;

// 	// y = 100;
// 	// while (y < 200)
// 	// {
// 	// 	x = 100;
// 	// 	while (x < 200)
// 	// 	{
// 	// 		my_mlx_pixel_put(cub, x, y, 0xffffff);
// 	// 		x++;
// 	// 	}
// 	// 	y++;
// 	// }
// }
