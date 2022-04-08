#include "../cub.h"

static void	render_cub(t_all *cub);

static int	which_side(t_plr ray, float *st_wall);

static void print_floor_and_ceil(t_all *cub);\

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
	t_ray	ray_dat;

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
			ray.x += PREC * (cos(ray.start));
			ray.y += PREC * (sin(ray.start));
		}
		ray_dat.len_ray = sqrtf(pow(ray.x - cub->plr->x, 2) + pow(ray.y - cub->plr->y, 2));
		ray_dat.side = which_side(ray, &(ray_dat.st_wall));
		print_column(cub, x, fabs(cos(ray.dir - ray.start)), ray_dat);
		ray.start += ((M_PI / 7) * 2) / WIDTH;
		x++;
	}
}

static int	which_side(t_plr ray, float *st_wall)
{
	if (ray.y - floor(ray.y) <= PREC)//so
	{
		*st_wall = (ray.x - floor(ray.x) / SCALE); 
		return (0);
	}
	else if (ray.y - floor(ray.y) < 1 && ray.y - floor(ray.y) > 1 - PREC)//no
	{
		*st_wall = (ray.x - floor(ray.x)) / SCALE; 
		return (1);
	}
	else if (ray.x - floor(ray.x) <= PREC)//ea
	{
		*st_wall = (ray.y - floor(ray.y)) / SCALE; 
		return (2);
	}
	else if (ray.x - floor(ray.x) < 1 && ray.x - floor(ray.x) >= 1 - PREC)//we
	{
		*st_wall = (ray.y - floor(ray.y)) / SCALE;
		return (3);
	}
	return (-1);
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