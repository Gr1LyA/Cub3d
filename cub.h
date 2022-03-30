#ifndef CUB_H
# define CUB_H

#include <sys/types.h>
# define SCALE 16 // условный размер каждого квадратика в карте
# define WIDTH 500
# define HEIGHT 500

# define ESC 65307
# define W 119
# define A 97
# define S 115
# define D 100
# define UP 65362
# define DOWN 65364
# define LEFT 65361
# define RIGHT 65363

# include "./gnl/get_next_line.h"
# include "./libft/libft.h"
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <errno.h>
# include "minilibx-linux/mlx.h"

typedef struct	s_win //структура для окна
{
	void		*mlx;
	void		*win;
	void		*img;
	void		*addr;
	int			line_l;
	int			bpp;
	int			en;
	char		*north;
	char		*south;
	char		*west;
	char		*east;
	u_int32_t	floor;
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
	float		dir;
	float		start;
	float		end;
}				  t_plr;

typedef struct	s_all // структура для всего вместе
{
	t_win		*win;
	t_plr		*plr;
	char		**map;
}				  t_all;

//function for get map

void		take_map(char *name, t_all *cub);
void		color(char *str, u_int32_t *color);
u_int32_t	convert_to_decimal(char **splt);
u_int32_t	exponentiation(u_int32_t num, size_t stepen);

//functions for free allocate memmory

void	free_content(void *cont);
void	free_all(t_all *all);

//func for window

void	init_window(t_all *cub);

//func for message about errors

int		error_mess(char *error);

#endif