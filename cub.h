#ifndef CUB_H
# define CUB_H

# define WIDTH 800
# define HEIGHT 600

# define SCALE 1 // условный размер каждого квадратика в карте
# define STEP 0.1

# define ESC 53
# define W 13
# define A 0
# define S 1
# define D 2
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124

# include "./gnl/get_next_line_bonus.h"
# include "./libft/libft.h"
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <errno.h>
# include "mlx/mlx.h"
# include <sys/types.h>
# include <math.h>
# include <stddef.h>

typedef struct	s_win //структура для окна
{
	void		*mlx;
	void		*win;
	void		*img;
	void		*addr;
	int			len;
	int			bpp;
	int			endian;
	char		*north;//добавить проверку на открытие текстур
	char		*south;
	char		*west;
	char		*east;
	void		*no;//добавить проверку на открытие текстур
	void		*so;
	void		*we;
	void		*ea;
	u_int32_t	floor;//добавить проверку <255 && >0
	u_int32_t	ceiling;
}				  t_win;

typedef struct	s_point // структура для точки
{
	int			x;
	int			y;
}				  t_point;

typedef struct	s_plr //структура для игрока и луча
{
	float		x;
	float		y;
	float		dir;//середина обзора
	float		start;//левая сторона обзора
	float		end;//правая сторона обзора
}				  t_plr;

typedef struct	s_all // структура для всего вместе
{
	t_win		*win;
	t_plr		*plr;
	char		**map;//сделать проверку на валидность
	// size_t		map_x;
	// size_t		map_y;
	// float			len_ray[WIDTH];
}				  t_all;

//function for get map

void		take_map(char *name, t_all *cub);
void		color(char *str, u_int32_t *color);
u_int32_t	convert_to_decimal(char **splt);
void		x_y_plr(t_all *cub);
void		check_map(char **map);

//functions for free allocate memmory

void	free_content(void *cont);
void	free_all(t_all *all);

//func for window

void	init_window(t_all *cub);

//func for message about errors

int		error_mess(char *error);

//func for render img

void	my_mlx_pixel_put(t_all *cub, int x, int y, int color);
int		image_cub(t_all *cub);
void	minimap(t_all *cub);
void	set_texture(t_all *cub);

//func for keyhook

int	close_win(int key);
int	key_hook(int key, t_all *cub);

//supporting func

int		ft_findchr(char *str, char ch);

#endif