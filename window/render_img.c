#include "../cub.h"

static void	render_cub(t_all *cub);

static void	print_column(t_all *cub, size_t x, float cosin_ray, float len_ray);

static void print_floor_and_ceil(t_all *cub);

int	image_cub(t_all *cub)
{
	render_cub(cub);
	mlx_put_image_to_window(cub->win->mlx, cub->win->win, cub->win->img, 0, 0);
	return (0);
}


static void	render_cub(t_all *cub)//функция получения длины векторов
{
	t_plr	ray = *cub->plr; // задаем координаты и направление луча равные координатам игрока
	size_t	x;
	float	len_ray;

	print_floor_and_ceil(cub);
	ray.start = ray.dir - M_PI_4; // начало веера лучей
	ray.end = ray.dir + M_PI_4; // край веера лучей
	x = 0;
  	while (x < WIDTH)
	{
		ray.x = cub->plr->x; // каждый раз возвращаемся в точку начала
		ray.y = cub->plr->y;
		while (cub->map[(int)round(ray.y / SCALE)][(int)round(ray.x / SCALE)] != '1')
		{
			ray.x += cos(ray.start);
			ray.y += sin(ray.start);
		}
		len_ray = sqrtf(pow(ray.x - cub->plr->x, 2) + pow(ray.y - cub->plr->y, 2));
		print_column(cub, x, fabs(cos(ray.dir - ray.start)), len_ray);
		ray.start += M_PI_2 / 1000;
		x++;
	}
	minimap(cub);
}

static void	print_column(t_all *cub, size_t x, float cosin_ray, float len_ray)
{
	size_t	y;
	size_t	start_y;
	float	len_column;

	if (len_ray > HEIGHT)
		return ;
	// len_column = (((HEIGHT / len_ray)) / 1) * 10;
	len_column = (((HEIGHT / len_ray)) / cosin_ray) * 10;
	start_y = (HEIGHT - len_column) / 2;
	y = start_y;
	while (y < HEIGHT - start_y)
	{
		my_mlx_pixel_put(cub, x, y, 0x990099);
		y++;
	}
}

static void print_floor_and_ceil(t_all *cub)
{
	size_t	x;
	size_t	y;

	x = -1;
	while (++x < WIDTH)
	{
		y = -1;
		while (++y < HEIGHT)
		{
			if (y < HEIGHT / 2)
				my_mlx_pixel_put(cub, x, y, cub->win->ceiling);
			else
				my_mlx_pixel_put(cub, x, y, cub->win->floor);
		}
	}
}
