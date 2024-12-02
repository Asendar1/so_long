SRCSDIR = sources/
SRCS = $(addprefix $(SRCSDIR), main.c controls.c utils.c utils2.c parser.c parser_utils.c draw.c file_manage.c flood.c movement.c)

OBJSDIR = objects/

OBJS = $(SRCS:$(SRCSDIR)%.c=$(OBJSDIR)%.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -Iincludes -g

MLX_DIR = minilibx-linux
MLX = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm
INCLUDES = -I$(MLX_DIR) -I.

NAME = so_long

LIBFT = libft/libft.a
LIBFT_LIB = -L./libft -lft -Ilibft

FT_PRINTF = ft_printf/libftprintf.a
FT_PRINTF_LIB = -L./ft_printf -lftprintf

GREEN = \033[32m
WHITE = \033[37m
RESET = \033[0m

all: $(NAME)

$(MLX_DIR)/libmlx.a:
	@echo "$(WHITE)Compiling MLX...$(RESET)"
	@$(MAKE) -C $(MLX_DIR) -s
	@echo "$(GREEN)Compiling MLX: Done$(RESET)"

$(NAME): $(OBJS) $(MLX_DIR)/libmlx.a $(LIBFT) $(FT_PRINTF)
	@echo "$(WHITE)Compiling $(NAME)...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT_LIB) -Ilibft $(FT_PRINTF_LIB) $(MLX) -o $(NAME)
	@echo "$(GREEN)Compiling $(NAME): Done$(RESET)"

$(OBJSDIR):
	@mkdir -p $(OBJSDIR)

$(OBJSDIR)%.o: $(SRCSDIR)%.c | $(OBJSDIR)
	@echo "$(WHITE)Compiling $@...$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(GREEN)Compiling $@: Done$(RESET)"

$(LIBFT):
	@make -C libft -s

$(FT_PRINTF):
	@make -C ft_printf -s

clean:
	@echo "$(WHITE)Cleaning...$(RESET)"
	@make -s fclean -C libft
	@make -s clean -C $(MLX_DIR)
	@make -s fclean -C ft_printf
	@rm -f $(OBJS)
	@echo "$(GREEN)Cleaning: Done$(RESET)"

fclean: clean
	@echo "$(WHITE)Full Cleaning...$(RESET)"
	@make -s fclean -C libft
	@make -s fclean -C ft_printf
	@rm -f $(NAME)
	@echo "$(GREEN)Full Cleaning: Done$(RESET)"

re: fclean all

.PHONY: all clean fclean re
