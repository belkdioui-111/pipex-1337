SRC = pipex.c pipex_utils.c pipex_utils_child.c pipex_utils_par.c
LIBFT = libft/libft.a
OBJ = $(SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Werror -Wextra
NAME = pipex

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft/
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)
		
clean :
	rm -rf $(OBJ)
	make fclean -C libft/
	
fclean : clean
	rm -rf $(NAME)

re: fclean $(NAME)
