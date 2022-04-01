#include "../cub.h"

static void	render_cub(t_all *cub);

static void	print_square(size_t x, size_t y, t_all *cub, u_int32_t color);

// static void	print_ray(t_all *cub);

static void	ft_cast_rays(t_all *cub);

// static void	print_line(size_t x, size_t y, t_all *cub, u_int32_t color);

int	image_cub(t_all *cub)
{
	render_cub(cub);
	mlx_put_image_to_window(cub->win->mlx, cub->win->win, cub->win->img, 0, 0);
	return (0);
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
	// print_square(cub->plr->x, cub->plr->y, cub, 0x000fff);//отрисовываю персонажа
	// print_ray(cub);
	ft_cast_rays(cub);
}

// static void	print_ray(t_all *cub)
// {
// 	t_plr	ray = *cub->plr; // задаем координаты луча равные координатам игрока

// 	while (cub->map[(int)(ray.y / SCALE)][(int)(ray.x / SCALE)] != '1')
// 		// && cub->map[(int)ceil(ray.y / SCALE)][(int)ceil(ray.x / SCALE)] != '1')
// 	{
// 		// printf("ALLOO\n");
// 		ray.x += cos(ray.dir);
// 		ray.y += sin(ray.dir);
// 		printf("ray.x = %f\nray.y = %f", ray.x, ray.y);
// 		my_mlx_pixel_put(cub, ray.x, ray.y, 0x990099);
// 	}
// }

static void	ft_cast_rays(t_all *cub)
{
	t_plr	ray = *cub->plr; // задаем координаты и направление луча равные координатам игрока
	
	ray.start = ray.dir - M_PI_4; // начало веера лучей
	ray.end = ray.dir + M_PI_4; // край веера лучей
  	while (ray.start <= ray.end)
	{
		ray.x = cub->plr->x; // каждый раз возвращаемся в точку начала
		ray.y = cub->plr->y;
		while (cub->map[(int)(ray.y / SCALE)][(int)(ray.x / SCALE)] != '1')
		{
			ray.x += cos(ray.start);
			ray.y += sin(ray.start);
			my_mlx_pixel_put(cub, ray.x, ray.y, 0x990099);
		}
		ray.start += M_PI_2 / 50;
	}
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
