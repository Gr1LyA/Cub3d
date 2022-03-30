#include "../cub.h"

static void	render_cub(t_all *cub);

int	image_cub(t_all *cub)
{
	t_win	*img;

	img = cub->win;
	img->img = mlx_new_image(cub->win->mlx, WIDTH, HEIGHT);
	img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->len, &img->endian);
	render_cub(cub);
	mlx_put_image_to_window(cub->win->mlx, cub->win->win, img->img, 0, 0);
	return (0);
}

static void	render_cub(t_all *cub)
{
	int x;
	int y;

	y = 100;
	while (y < 200)
	{
		x = 100;
		while (x < 200)
		{
			my_mlx_pixel_put(*cub, x, y, 0xffffff);
			x++;
		}
		y++;
	}
}
