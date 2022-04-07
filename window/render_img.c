#include "../cub.h"

static void	render_cub(t_all *cub);

static void	print_column(t_all *cub, size_t x, float cosin_ray, t_ray ray);

static void print_floor_and_ceil(t_all *cub);

// static int	which_side(t_plr ray, t_plr plr, float pre_last_x, float pre_last_y);

static int	which_side(t_plr ray, t_plr plr, float *st_wall);

static void	sub_print_column(t_all *cub, size_t x, float cosin_ray, float len_column, t_ray ray);

unsigned int	*get_tex(int sum, t_ray ray, t_all cub);

int	image_cub(t_all *cub)
{
	render_cub(cub);
	// minimap(cub);
	// for (int y = 0; y < HEIGHT; y++)
	// {
		// for (int x = 0; x < WIDTH; x++)
		// {
			// my_mlx_pixel_put(cub, x, y, cub->win->ea[(int)(64 * floor((float)y / ((float)HEIGHT / 64)) + (float)x * 64. / WIDTH)]);
			// my_mlx_pixel_put(cub, x, y, cub->win->ea[(int)(64 * floor((float)y  / (HEIGHT - y)) + (float)x * 64. / WIDTH)]);
			// my_mlx_pixel_put(cub, x, y, cub->win->ea[(int)(64 * floor((float)y * (float)HEIGHT / 64) + (float)x * 64. / WIDTH)]);
		// }
	// }
	mlx_put_image_to_window(cub->win->mlx, cub->win->win, cub->win->img, 0, 0);
	return (0);
}


static void	render_cub(t_all *cub)//функция получения длины векторов
{
	t_plr	ray = *cub->plr; // задаем координаты и направление луча равные координатам игрока
	size_t	x;
	t_ray	ray_dat;
	// float	len_ray;
	// int		side;
	// float	st_wall;

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
		ray_dat.len_ray = sqrtf(pow(ray.x - cub->plr->x, 2) + pow(ray.y - cub->plr->y, 2));
		ray_dat.side = which_side(ray, *cub->plr, &(ray_dat.st_wall));
		print_column(cub, x, fabs(cos(ray.dir - ray.start)), ray_dat);
		ray.start += ((M_PI / 7) * 2) / WIDTH;
		x++;
	}
}

static int	which_side(t_plr ray, t_plr plr, float *st_wall)
{
	if (ray.y - floor(ray.y) <= 0.005)//so
	{
		*st_wall = (ray.x - floor(ray.x) / SCALE); 
		return (0);
	}
	else if (ray.y - floor(ray.y) < 1 && ray.y - floor(ray.y) > 0.995)//no
	{
		*st_wall = (ray.x - floor(ray.x)) / SCALE; 
		return (1);
	}
	else if (ray.x - floor(ray.x) <= 0.005)//ea
	{
		*st_wall = (ray.y - floor(ray.y)) / SCALE; 
		return (2);
	}
	else if (ray.x - floor(ray.x) < 1 && ray.x - floor(ray.x) >= 0.995)//we
	{
		*st_wall = (ray.y - floor(ray.y)) / SCALE;
		return (3);
	}
	return (-1);
}

static void	print_column(t_all *cub, size_t x, float cosin_ray, t_ray ray)
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
		return (sub_print_column(cub, x, cosin_ray, len_column, ray));
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

static void	sub_print_column(t_all *cub, size_t x, float cosin_ray, float len_column, t_ray ray)
{
	size_t	y;
	size_t	pix_y;
	unsigned int	*tex;

	y = -1;
	pix_y = (len_column - HEIGHT) / 2;
	while (++y < HEIGHT)
	{
		tex = &cub->win->no[(int)(64 * floor((float)(y + pix_y) / ((float)len_column / 64)) + 64. * ray.st_wall)];
		my_mlx_pixel_put(cub, x, y, *tex);
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
