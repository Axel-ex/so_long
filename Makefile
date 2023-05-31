NAME	=	so_long

SRC		=	srcs/main.c srcs/map.c srcs/checks.c srcs/init.c\
			srcs/sprite.c srcs/render.c srcs/close.c srcs/events.c

OBJ		=	$(SRC:.c=.o)

INC		=	includes/

FLAGS	=	-Wall -Wextra -Werror 

LIBFT	=	libft.a

LIBMLX	=	libmlx.a

MLX		=	-Lmlx -framework OpenGL -framework AppKit

OBJ_DIR	=	obj/


%.o:%.c $(OBJ_DIR)
	cc $(FLAGS) -c $< -o $(<:.c=.o)
	mv srcs/*.o $(OBJ_DIR)
	
all: $(NAME)

debug: $(OBJ) $(OBJ_DIR) $(LIBFT) $(LIBMLX)
	cd $(OBJ_DIR)
	cc -g $(FLAGS) -I $(INC) $(OBJ_DIR)/$(LIBFT) $(MLX) $(OBJ_DIR)/$(LIBMLX) $(SRC) -o $(NAME)

$(LIBFT): $(OBJ_DIR)
	make -C Libft/
	mv Libft/$(LIBFT) $(OBJ_DIR)

$(LIBMLX): $(OBJ_DIR)
	make -C mlx/
	mv mlx/$(LIBMLX) $(OBJ_DIR)

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(NAME): $(OBJ) $(LIBFT) $(LIBMLX)
	cc $(FLAGS) -I $(INC) $(OBJ) Libft/$(LIBFT) $(MLX) mlx/$(LIBMLX) -o $(NAME)

clean:
	rm -rf $(OBJ_DIR)
	make clean -C Libft/
	make clean -C mlx/

fclean: clean
	rm -rf $(NAME)
	make fclean -C Libft/

re: fclean all

.PHONY: all clean fclean re
