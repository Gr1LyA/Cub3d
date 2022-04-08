#include "../cub.h"

void	set_texture(t_all *cub)
{
	int		tmp[5];

	cub->img[0] = mlx_xpm_file_to_image(cub->win->mlx, cub->win->north, &tmp[0], &tmp[1]);
	if (!cub->img[0])
		exit (error_mess("path error"));
	cub->win->no = (unsigned int *)mlx_get_data_addr(cub->img[0],
			&tmp[2], &tmp[3], &tmp[4]);
	cub->img[1] = mlx_xpm_file_to_image(cub->win->mlx, cub->win->south, &tmp[0], &tmp[1]);
	if (!cub->img[1])
		exit (error_mess("path error"));
	cub->win->so = (unsigned int *)mlx_get_data_addr(cub->img[1],
			&tmp[2], &tmp[3], &tmp[4]);
	cub->img[2] = mlx_xpm_file_to_image(cub->win->mlx, cub->win->west, &tmp[0], &tmp[1]);
	if (!cub->img[2])
		exit (error_mess("path error"));
	cub->win->we = (unsigned int *)mlx_get_data_addr(cub->img[2],
			&tmp[2], &tmp[3], &tmp[4]);
	cub->img[3] = mlx_xpm_file_to_image(cub->win->mlx, cub->win->east, &tmp[0], &tmp[1]);
	if (!cub->img[3])
		exit (error_mess("path error"));
	cub->win->ea = (unsigned int *)mlx_get_data_addr(cub->img[3],
			&tmp[2], &tmp[3], &tmp[4]);
}