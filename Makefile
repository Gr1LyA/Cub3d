NAME = cub3D
PARSER = get_map.c color.c rgb_to_int.c x_y.c
CLEAN = clean.c
ERROR = error.c
WINDOW = window.c render_img.c pixel_put.c key_hook.c minimap.c
TOOLS = tools.c
GNL = get_next_line_bonus.c get_next_line_utils_bonus.c
SRCS =	$(addprefix gnl/, $(GNL)) \
		$(addprefix tools/, $(TOOLS)) \
		$(addprefix window/, $(WINDOW)) \
		$(addprefix error/, $(ERROR)) \
		$(addprefix parser/, $(PARSER)) \
		$(addprefix clean/, $(CLEAN)) \
		main.c 
OBJS = ${SRCS:.c=.o}
CC = gcc -fsanitize=address

$(NAME): $(OBJS) cub.h Makefile
		make bonus -C ./libft
		make -C ./libft
		make -C ./mlx
		$(CC) $(OBJS) -Lmlx -lmlx -framework OpenGL -framework AppKit -L ./libft -lft -o $(NAME)

# $(NAME): $(OBJS) cub.h Makefile
# 		make bonus -C ./libft
# 		make -C ./libft
# 		make -C ./minilibx-linux
# 		$(CC) $(OBJS) -I cub.h -L ./minilibx-linux -lmlx -lXext -lX11 -lm -L ./libft -lft -o $(NAME)

all:	$(NAME)

clean:
		make clean -C ./libft
		rm -rf $(OBJS) ./parser/hex.txt

fclean:	clean
		rm -rf $(NAME)
		make fclean -C ./libft
		make clean -C ./mlx

re:	fclean re all clean

.PHONY: clean