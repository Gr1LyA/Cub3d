#include "../cub.h"

static void	render_cub(t_all *cub);

static void	ft_len_rays(t_all *cub);

static void print_floor_and_ceil(t_all *cub);

int	image_cub(t_all *cub)
{
	render_cub(cub);
	mlx_put_image_to_window(cub->win->mlx, cub->win->win, cub->win->img, 0, 0);
	return (0);
}

static void	render_cub(t_all *cub)
{
	size_t	y;
	size_t	x;
	size_t	start_y;
	size_t	len_column;
	

	ft_len_rays(cub);
	x = 0;
	// printf("len_ray[500] = %f\n", cub->len_ray[500]);
	print_floor_and_ceil(cub);
	while (x < WIDTH)
	{
		// if (x == 500)
		// 	printf()
		// y = (HEIGHT - cub->len_ray[x]) / 2;
		// len_column = HEIGHT - ((cub->len_ray[x] / 2) * 4) * 2 / ;
		start_y = (cub->len_ray[x] / 2) * 4;
		y = start_y;
		// printf("start_y = %zu, end_y = %d, x = %zu\n, len_ray = %f", y, cub->len_wall[x] + (HEIGHT - cub->len_wall[x]) / 2, x, cub->len_wall[x]);
		// while (y < cub->len_ray[x] + (HEIGHT - cub->len_ray[x]) / 2)
		while (y < HEIGHT - start_y)
		{
			// printf("y = %f\n", y);
			my_mlx_pixel_put(cub, x, y, 0x990099);
			y++;
		}
		x++;
	}
	minimap(cub);
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

static void	ft_len_rays(t_all *cub)//функция получения длины векторов
{
	t_plr	ray = *cub->plr; // задаем координаты и направление луча равные координатам игрока
	size_t	i;

	ray.start = ray.dir - M_PI_4; // начало веера лучей
	ray.end = ray.dir + M_PI_4; // край веера лучей
	i = 0;
  	while (i < WIDTH)
	{
		ray.x = cub->plr->x; // каждый раз возвращаемся в точку начала
		ray.y = cub->plr->y;
		while (cub->map[(int)(ray.y / SCALE)][(int)(ray.x / SCALE)] != '1')
		{
			// if (i == 0)
				// ("ray.x = %f\nray.y = %f", ray.x, ray.y);
			ray.x += cos(ray.start);
			ray.y += sin(ray.start);
		}
		ray.start += M_PI_2 / 1000;
		cub->len_ray[i] = sqrtf(pow(ray.x - cub->plr->x, 2) + pow(ray.y - cub->plr->y, 2));
		// if (i == 500)
			// printf("x1 = %f\nx2 = %f\ny1 = %f\ny2 = %f\nlen_ray = %f", ray.x, cub->plr->x, ray.y, cub->plr->y, cub->len_ray[500]);
		i++;
	}
	// printf("i = %zu\n", i);
}
