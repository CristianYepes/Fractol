NAME	= fractol

CC		= gcc
CFLAGS	=  -Werror -Wextra -Wall

MLX_PATH = minilibx-linux/
MLX_NAME = libmlx.a
MLX = $(MLX_PATH)$(MLX_NAME)
MLX_REPO = https://github.com/42Paris/minilibx-linux.git


LIBFT_PATH = libft/
LIBFT_NAME = libft.a
LIBFT = $(LIBFT_PATH)$(LIBFT_NAME)

INC = 	-I ./includes/\
		-I ./libft/\
		-I ./minilibx-linux\

SRC_PATH = src/
SRC =	color_palettes/palette_interpolated.c \
		color_palettes/palette_special.c \
		color_palettes/palette_striped.c \
		fractol_math/burning_ship.c \
		fractol_math/julia.c \
		fractol_math/mandelbrot.c \
		color_manager.c \
		exit_utils.c \
		fractol_evets.c \
		fractol_render.c \
		fractol.c \
		help_user.c \
		init.c \
		iter_utils.c \
		parser.c \


SRCS = $(addprefix $(SRC_PATH), $(SRC))

OBJ_PATH = obj/
OBJS = $(SRCS:$(SRC_PATH)%=$(OBJ_PATH)%.o)

all : $(MLX) $(LIBFT) $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%
	@mkdir -p $(dir $@)
	@echo "\033[0;33mCompiling $< ...\033[0m"
	@$(CC) $(CFLAGS) -c $< -o $@ $(INC)

$(MLX_PATH):
	@echo "\033[1;34mCloning MiniLibX repository...\033[0m"
	@git clone --depth 1 $(MLX_REPO) $(MLX_PATH)

$(MLX): $(MLX_PATH)
	@echo "\033[1;34mMaking MiniLibX...\033[0m"
	@make -sC $(MLX_PATH)

$(LIBFT):
	@echo "\033[1;34mMaking libft...\033[0m"
	@make -sC $(LIBFT_PATH)

$(NAME): $(OBJS)
	@echo "\033[1;34mCompiling Fractol\033[0m"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX) $(LIBFT) $(INC) -lXext -lX11 -lm
	@echo "\033[1;32m✅ Fractol compiled successfully!\033[0m"

bonus: all

clean:
	@echo "\033[1;31mRemoving .o object files...\033[0m"
	@rm -rf $(OBJ_PATH)
	@make clean -C $(MLX_PATH)
	@make clean -C $(LIBFT_PATH)

fclean: clean
	@echo "\033[1;31mRemoving fractol...\033[0m"
	@rm -f $(NAME)
	@rm -f $(LIBFT_PATH)$(LIBFT_NAME)

re: fclean all

.PHONY: all re clean fclean bonus
