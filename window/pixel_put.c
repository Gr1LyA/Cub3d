#include "../cub.h"

void	my_mlx_pixel_put(t_all *cub, int x, int y, int color)
{
	char	*dst;

	dst = cub->win->addr + (y * cub->win->len + x * (cub->win->bpp / 8));
	*(unsigned int *)dst = color;
}