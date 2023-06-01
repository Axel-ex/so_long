NAME	=	so_long

SRC		=	main.c map.c checks.c init.c\
			sprite.c render.c close.c moves.c\
			utils.c

SRC_DIR = srcs/

OBJ_DIR	=	obj/

OBJ		=	$(SRC:.c=.o)

INC		=	../includes/

FLAGS	=	-Wall -Wextra -Werror 

LIBFT	=	libft.a

LIBMLX	=	libmlx.a

MLX		=	-Lmlx -framework OpenGL -framework AppKit



%.o:$(SRC_DIR)%.c $(OBJ_DIR)
	cc $(FLAGS) -c $< -o $(<:.c=.o)
	mv srcs/*.o $(OBJ_DIR)
	
all: $(NAME)

debug: $(OBJ) $(OBJ_DIR) $(LIBFT) $(LIBMLX)
	cc -g $(FLAGS) -I $(INC) $(OBJ_DIR)$(LIBFT) $(MLX) $(OBJ_DIR)$(LIBMLX) $(addprefix $(SRC_DIR), $(SRC)) -o $(NAME)

$(LIBFT): $(OBJ_DIR)
	make -C Libft/
	mv Libft/$(LIBFT) $(OBJ_DIR)

$(LIBMLX): $(OBJ_DIR)
	make -C mlx/
	mv mlx/$(LIBMLX) $(OBJ_DIR)

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(NAME): $(OBJ) $(LIBFT) $(LIBMLX) $(OBJ_DIR)
	cc $(FLAGS) -I $(INC) $(addprefix $(OBJ_DIR),$(OBJ)) $(OBJ_DIR)$(LIBFT) $(MLX) $(OBJ_DIR)$(LIBMLX) -o $(NAME)

clean:
	rm -rf $(OBJ_DIR)
	make clean -C Libft/
	make clean -C mlx/

fclean: clean
	rm -rf $(NAME)
	make fclean -C Libft/

re: fclean all

.PHONY: all clean fclean re
