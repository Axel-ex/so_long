NAME		=	so_long

NAME_MAC	=	so_long_mac

SRC			=	main.c map.c checks.c init.c\
			sprite.c render.c close.c moves.c\
			utils.c

SRC_BONUS	=	main_bonus.c map_bonus.c checks_bonus.c init_bonus.c\
			load_sprite_bonus.c render_bonus.c close_bonus.c moves_bonus.c\
			utils_bonus.c load_zombies_bonus.c move_zombies_bonus.c\
			animations_bonus.c

SRC_DIR 	= srcs/

SRC_BONUS_DIR = srcs_bonus/

OBJ_DIR		=	obj/

OBJ			=	$(SRC:.c=.o)

OBJ_BONUS 	=	$(SRC_BONUS:.c=.o)

INC			=	includes

FLAGS		=	-Wall -Wextra -Werror

LIBFT		=	libft.a

LIBMLX		=	libmlx.a

MLX_DIR		=	mlx_linux/

MLX_FALGS	=	-Lmlx_linux -Imlx_linux -lXext -lX11 -lm

MODE 		=	linux

ifeq ($(MODE), mac)
	FLAGS += -D MACOS=1
	MLX_FLAGS = -Lmlx -framework OpenGL -framework AppKit
	MLX_DIR = mlx/
endif

GREEN		= \033[38;5;47m
YELLOW		= \033[38;5;226m
RED			= \033[38;5;196m
RESET 		= \033[0m

#GENERAL RULES
%.o:$(SRC_DIR)%.c $(OBJ_DIR)
	@cc $(FLAGS) -c $< -o $(<:.c=.o)
	@@@mv $(SRC_DIR)*.o $(OBJ_DIR)

%.o:$(SRC_BONUS_DIR)%.c $(OBJ_DIR)
	@@cc $(FLAGS) -c $< -o $(<:.c=.o)
	@mv $(SRC_BONUS_DIR)*.o $(OBJ_DIR)

all: $(NAME) | $(OBJ)

$(NAME): $(OBJ) $(LIBFT) $(LIBMLX) | $(OBJ_DIR)
	@cc $(FLAGS) $(MLX_FLAGS) -L$(OBJ_DIR) -I $(INC) $(addprefix $(OBJ_DIR),$(OBJ)) $(OBJ_DIR)$(LIBFT) $(MLX_DIR)$(LIBMLX) -o $(NAME)
	@echo "[$(GREEN)compiling$(RESET)]: $(NAME)"
	
$(LIBFT): | $(OBJ_DIR)
	@make -C Libft/
	@mv Libft/$(LIBFT) $(OBJ_DIR)
	@echo "[$(GREEN)compiling$(RESET)]: $(LIBFT)"

$(LIBMLX): | $(OBJ_DIR)
	@make -C $(MLX_DIR)
	@echo "[$(GREEN)compiling$(RESET)]: $(LIBMLX)"

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)


bonus: $(OBJ_BONUS) $(LIBFT) $(LIBMLX) | $(OBJ_DIR)
	@cc -g $(FLAGS) $(MLX_FLAGS) -I $(INC) $(addprefix $(OBJ_DIR),$(OBJ_BONUS)) $(OBJ_DIR)$(LIBFT) $(MLX_DIR)$(LIBMLX) -o $(NAME)
	@echo "[$(GREEN)compiling$(RESET)]: $<"

clean:
	@rm -rf $(OBJ_DIR)*.o
	@make clean -C Libft/
	@echo "$(YELLOW)Removing objects files$(RESET)"

fclean: clean
	@rm -rf $(NAME)
	@make fclean -C Libft/
	@echo "$(RED)removing $(NAME) executable$(RESET)"

re: fclean all

.PHONY: all clean fclean re
