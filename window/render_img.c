#include "../cub.h"
#include <sys/types.h>

static void	render_cub(t_all *cub);

static void	print_column(t_all *cub, size_t x, float cosin_ray, float len_ray, u_int32_t color);

static void print_floor_and_ceil(t_all *cub);

// static int	which_side(t_plr ray, t_plr plr, float pre_last_x, float pre_last_y);

static int	which_side(t_plr ray, t_plr plr);

int	image_cub(t_all *cub)
{
	// void 	*img;
	// int		img_width;
	// int		img_height;
	render_cub(cub);
	minimap(cub);
	mlx_put_image_to_window(cub->win->mlx, cub->win->win, cub->win->img, 0, 0);
	// img = mlx_xpm_file_to_image(cub->win->mlx, cub->win->north, &img_width, &img_height);
	// mlx_put_image_to_window(cub->win->mlx, cub->win->win, img, 0, 0);
	return (0);
}


static void	render_cub(t_all *cub)//функция получения длины векторов
{
	t_plr	ray = *cub->plr; // задаем координаты и направление луча равные координатам игрока
	size_t	x;
	float	len_ray;
	int		side;

	print_floor_and_ceil(cub);
	ray.start = ray.dir - (M_PI / 7); // начало веера лучей
	ray.end = ray.dir + (M_PI / 7); // край веера лучей
	x = 0;
  	while (x < WIDTH)
	{
		ray.x = cub->plr->x; // каждый раз возвращаемся в точку начала
		ray.y = cub->plr->y;
		while (cub->map[(int)(ray.y / SCALE)][(int)(ray.x / SCALE)] != '1')
		{
			ray.x += 0.005 * (cos(ray.start));
			ray.y += 0.005 * (sin(ray.start));
		}
		len_ray = sqrtf(pow(ray.x - cub->plr->x, 2) + pow(ray.y - cub->plr->y, 2));
		side = which_side(ray, *cub->plr);
		// side = which_side(ray, *cub->plr, ray.x - 0.005 * (cos(ray.start)), ray.y - 0.005 * (sin(ray.start)));//узнаем сторону горизонта
		if (side == 0)
			print_column(cub, x, fabs(cos(ray.dir - ray.start)), len_ray, 0x009900 / 2);
		else if (side == 1)
			print_column(cub, x, fabs(cos(ray.dir - ray.start)), len_ray, 0x990099);
		else if (side == 2)
			print_column(cub, x, fabs(cos(ray.dir - ray.start)), len_ray, 0x123456);
		else if (side == 3)
			print_column(cub, x, fabs(cos(ray.dir - ray.start)), len_ray, 0x654321);
		ray.start += ((M_PI / 7) * 2) / WIDTH;
		x++;
	}
}

// static int	which_side(t_plr ray, t_plr plr, float pre_last_x, float pre_last_y)
// {
// 	if (ray.y - floor(ray.y) < ray.x - floor(ray.x))
// 		// && ) //so and no
// 		return (1);
// 	return (0);
// }

static int	which_side(t_plr ray, t_plr plr)
{
	// printf("y = %f\n",ray.y - floor(ray.y));
	// printf("x = %f\n",ray.x - floor(ray.x));
	if (ray.y - floor(ray.y) < 0.005)//so
		return (0);
	else if (ray.y - floor(ray.y) < 1 && ray.y - floor(ray.y) > 0.995)//no
		return (1);
	else if (ray.x - floor(ray.x) <= 0.005)//ea
		return (2);
	else if (ray.x - floor(ray.x) < 1 && ray.x - floor(ray.x) >= 0.995)//we
		return (3);
	return (-1);
}

static void	print_column(t_all *cub, size_t x, float cosin_ray, float len_ray, u_int32_t color)
{
	float	y;
	float	start_y;
	float	len_column;

	len_column = (((HEIGHT / len_ray)) / cosin_ray);
	if (len_column < 1)
		return ;
	if (len_column > HEIGHT)
		start_y = 0;
	else
		start_y = (HEIGHT - len_column) / 2;
	y = start_y;
	while (y < HEIGHT - start_y)
	{
		my_mlx_pixel_put(cub, x, y, color);
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
