#include "../cub.h"

static void	sub_set_texture(int t[5], t_all *cub);

void	set_texture(t_all *cub)
{
	int		t[5];

	cub->i[0] = mlx_xpm_file_to_image(cub->win->mlx, cub->win->nor,
			&t[0], &t[1]);
	if (!cub->i[0])
		exit (error_mess("path error"));
	cub->win->no = (unsigned int *)mlx_get_data_addr(cub->i[0],
			&t[2], &t[3], &t[4]);
	cub->i[1] = mlx_xpm_file_to_image(cub->win->mlx, cub->win->sou,
			&t[0], &t[1]);
	if (!cub->i[1])
		exit (error_mess("path error"));
	cub->win->so = (unsigned int *)mlx_get_data_addr(cub->i[1],
			&t[2], &t[3], &t[4]);
	sub_set_texture(t, cub);
}

static void	sub_set_texture(int t[5], t_all *cub)
{
	cub->i[2] = mlx_xpm_file_to_image(cub->win->mlx, cub->win->wes,
			&t[0], &t[1]);
	if (!cub->i[2])
		exit (error_mess("path error"));
	cub->win->we = (unsigned int *)mlx_get_data_addr(cub->i[2],
			&t[2], &t[3], &t[4]);
	cub->i[3] = mlx_xpm_file_to_image(cub->win->mlx, cub->win->eas,
			&t[0], &t[1]);
	if (!cub->i[3])
		exit (error_mess("path error"));
	cub->win->ea = (unsigned int *)mlx_get_data_addr(cub->i[3],
			&t[2], &t[3], &t[4]);
}
