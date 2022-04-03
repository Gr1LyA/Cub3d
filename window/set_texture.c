#include "../cub.h"

void	set_texture(t_all *cub)
{
	void	*img;
	int		tmp[5];

	img = mlx_xpm_file_to_image(cub->win->mlx, cub->win->north, &tmp[0], &tmp[1]);
	cub->win->no = (int *)mlx_get_data_addr(img,
			&tmp[2], &tmp[3], &tmp[4]);
	img = mlx_xpm_file_to_image(cub->win->mlx, cub->win->south, &tmp[0], &tmp[1]);
	cub->win->so = (int *)mlx_get_data_addr(img,
			&tmp[2], &tmp[3], &tmp[4]);
	img = mlx_xpm_file_to_image(cub->win->mlx, cub->win->west, &tmp[0], &tmp[1]);
	cub->win->we = (int *)mlx_get_data_addr(img,
			&tmp[2], &tmp[3], &tmp[4]);
	img = mlx_xpm_file_to_image(cub->win->mlx, cub->win->east, &tmp[0], &tmp[1]);
	cub->win->ea = (int *)mlx_get_data_addr(img,
			&tmp[2], &tmp[3], &tmp[4]);
	if (cub->win->no == NULL || cub->win->so == NULL
		|| cub->win->we == NULL || cub->win->ea == NULL)
		exit (error_mess("path error"));
}