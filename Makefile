NAME = cub
PARSER = get_map.c
CLEAN = clean.c
ERROR = 
GNL = get_next_line.c get_next_line_utils.c
SRCS =	$(addprefix gnl/, $(GNL)) \
		$(addprefix parser/, $(PARSER)) \
		$(addprefix clean/, $(CLEAN)) \
		main.c 
OBJS = ${SRCS:.c=.o}
CC = gcc #-fsanitize=address

$(NAME): $(OBJS) cub.h Makefile
		make bonus -C ./libft
		make -C ./libft
		make -C ./mlx
		$(CC) $(OBJS) -Lmlx -lmlx -framework OpenGL -framework AppKit -L ./libft -lft -o $(NAME)

linux: $(OBJS) cub.h Makefile
		make bonus -C ./libft
		make -C ./libft
		make -C ./minilibx-linux
		$(CC) $(OBJS) -L ./minilibx-linux -lmlx -lXext -lX11 -lm -L ./libft -lft -o $(NAME)

all:	$(NAME)

clean:
		make clean -C ./libft
		rm -rf $(OBJS) fractol

fclean:	clean
		rm -rf $(NAME)
		make fclean -C ./libft
		make clean -C ./minilibx-linux

re:	fclean re all clean

.PHONY: clean