NAME		=	so_long

SRC			=	main.c map.c checks.c init.c\
			sprite.c render.c close.c moves.c\
			utils.c

SRC_BONUS	=	main_bonus.c map_bonus.c checks_bonus.c init_bonus.c\
			load_sprite_bonus.c render_bonus.c close_bonus.c moves_bonus.c\
			utils_bonus.c load_zombies_bonus.c move_zombies_bonus.c\
			animations.c load_anim.c

SRC_DIR 	= srcs/

SRC_BONUS_DIR = srcs_bonus/

OBJ_DIR		=	obj/

OBJ			=	$(SRC:.c=.o)

OBJ_BONUS 	=	$(SRC_BONUS:.c=.o)

INC			=	../includes/

FLAGS		=	-Wall -Wextra -Werror 

LIBFT		=	libft.a

LIBMLX		=	libmlx.a

MLX			=	-Lmlx -framework OpenGL -framework AppKit



%.o:$(SRC_DIR)%.c $(OBJ_DIR)
	cc $(FLAGS) -c $< -o $(<:.c=.o)
	mv $(SRC_DIR)*.o $(OBJ_DIR)

%.o:$(SRC_BONUS_DIR)%.c $(OBJ_DIR)
	cc $(FLAGS) -c $< -o $(<:.c=.o)
	mv $(SRC_BONUS_DIR)*.o $(OBJ_DIR)

all: $(NAME)

$(LIBFT): $(OBJ_DIR)
	make -C Libft/
	mv Libft/$(LIBFT) $(OBJ_DIR)

$(LIBMLX): $(OBJ_DIR)
	make -C mlx/
	mv mlx/$(LIBMLX) $(OBJ_DIR)

$(OBJ_DIR):
	mkdir $(OBJ_DIR)


debug: $(OBJ) $(OBJ_DIR) $(LIBFT) $(LIBMLX)
	cc -g $(FLAGS) -I $(INC) $(OBJ_DIR)$(LIBFT) $(MLX) $(OBJ_DIR)$(LIBMLX) $(addprefix $(SRC_DIR), $(SRC)) -o $(NAME)

debugbonus: $(OBJ_BONUS) $(OBJ_DIR) $(LIBFT) $(LIBMLX)
	cc -g $(FLAGS) -I $(INC) $(OBJ_DIR)$(LIBFT) $(MLX) $(OBJ_DIR)$(LIBMLX) $(addprefix $(SRC_BONUS_DIR), $(SRC_BONUS)) -o $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(LIBMLX) $(OBJ_DIR)
	cc $(FLAGS) -I $(INC) $(addprefix $(OBJ_DIR),$(OBJ)) $(OBJ_DIR)$(LIBFT) $(MLX) $(OBJ_DIR)$(LIBMLX) -o $(NAME)

bonus: $(OBJ_BONUS) $(LIBFT) $(LIBMLX) $(OBJ_DIR)
	cc $(FLAGS) -I $(INC) $(addprefix $(OBJ_DIR),$(OBJ_BONUS)) $(OBJ_DIR)$(LIBFT) $(MLX) $(OBJ_DIR)$(LIBMLX) -o $(NAME)

clean:
	rm -rf $(OBJ_DIR)
	make clean -C Libft/
	make clean -C mlx/

fclean: clean
	rm -rf $(NAME)
	make fclean -C Libft/

re: fclean all

.PHONY: all clean fclean re
