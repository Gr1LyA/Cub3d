#include "../cub.h"

static void	sub_print_column(t_all *cub, size_t x, float len_column, t_ray ray);

unsigned int	*get_tex(int sum, t_ray ray, t_all cub);

void	print_column(t_all *cub, size_t x, float cosin_ray, t_ray ray)
{
	int				y;
	int				start_y;
	float			len_column;
	unsigned int	*tex;
	int				sum;

	len_column = ((((float)HEIGHT / ray.len_ray)) / cosin_ray);
	if (len_column < 1)
		return ;
	if (len_column > HEIGHT)
		return (sub_print_column(cub, x, len_column, ray));
	else
		start_y = (HEIGHT - len_column) / 2;
	y = start_y;
	while (y < HEIGHT - start_y)
	{
		sum = (int)(64 * floor((float)(y - start_y) / ((float)len_column / 64)) + 64. * ray.st_wall);
		tex = get_tex(sum, ray, *cub);
		my_mlx_pixel_put(cub, x, y, *tex);
		y++;
	}
}

unsigned int	*get_tex(int sum, t_ray ray, t_all cub)
{
	if (ray.side == 0)
		return (&cub.win->so[(int)sum]);
	else if (ray.side == 1)
		return (&cub.win->no[(int)sum]);
	else if (ray.side == 2)
		return (&cub.win->ea[(int)sum]);
	else if (ray.side == 3)
		return (&cub.win->we[(int)sum]);
	return (&cub.win->we[1]);
}

static void	sub_print_column(t_all *cub, size_t x, float len_column, t_ray ray)
{
	size_t			y;
	size_t			pix_y;
	unsigned int	*tex;
	int				sum;

	y = -1;
	pix_y = (len_column - HEIGHT) / 2;
	while (++y < HEIGHT)
	{
		sum = 64 * floor((float)(y + pix_y) / ((float)len_column / 64)) + 64. * ray.st_wall;
		tex = get_tex(sum, ray, *cub);
		my_mlx_pixel_put(cub, x, y, *tex);
	}
}

