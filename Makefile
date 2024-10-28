SRCS = main.c controls.c utils.c parser.c parser_utils.c \
		gnl/get_next_line_bonus.c

OBJS = $(SRCS:.c=.o)

LIBFT = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
MLX_DIR = minilibx-linux
MLX = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm
NAME = so_long
INCLUDES = -I$(MLX_DIR) -I.
LIBFT = -L./libft -lft


all: $(NAME)

$(MLX_DIR)/libmlx.a:
	$(MAKE) -C $(MLX_DIR)
$(NAME): $(OBJS) $(MLX_DIR)/libmlx.a
	make -C libft
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX) -o $(NAME)

clean:
	make clean -C ./libft
	make clean -C $(MLX_DIR)
	rm -f $(OBJS) 

fclean: clean
	make fclean -C ./libft
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re