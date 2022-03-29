NAME = cub
PARSER = get_map.c check_map.c
CLEAN = clean.c
ERROR = error.c
WINDOW = window.c
GNL = get_next_line.c get_next_line_utils.c
SRCS =	$(addprefix gnl/, $(GNL)) \
		$(addprefix window/, $(WINDOW)) \
		$(addprefix error/, $(ERROR)) \
		$(addprefix parser/, $(PARSER)) \
		$(addprefix clean/, $(CLEAN)) \
		main.c 
OBJS = ${SRCS:.c=.o}
CC = gcc -g#-fsanitize=address

$(NAME): $(OBJS) cub.h Makefile
		make bonus -C ./libft
		make -C ./libft
		make -C ./mlx
		$(CC) $(OBJS) -Lmlx -lmlx -framework OpenGL -framework AppKit -L ./libft -lft -o $(NAME)

# $(NAME): $(OBJS) cub.h Makefile
# 		make bonus -C ./libft
# 		make -C ./libft
# 		make -C ./mlx
# 		$(CC) $(OBJS) -L ./mlx -lmlx -lXext -lX11 -lm -L ./libft -lft -o $(NAME)

all:	$(NAME)

clean:
		make clean -C ./libft
		rm -rf $(OBJS)

fclean:	clean
		rm -rf $(NAME)
		make fclean -C ./libft
		make clean -C ./mlx

re:	fclean re all clean

.PHONY: clean