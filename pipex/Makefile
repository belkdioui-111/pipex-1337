SRC = pipex.c ft_split.c ft_strchr.c ft_strlen.c ft_strncmp.c ft_strtrim.c ft_substr.c ft_calloc.c ft_memcpy.c ft_bzero.c ft_memset.c ft_strjoin.c 

OBJ = $(SRC:.c=.o)

CC = gcc
CFLAGS = -Wall -Werror -Wextra
NAME = pipex
LIB = pipex.a
AR = ar rc

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(LIB) $(OBJ)
	$(CC) $(CFLAGS) $(LIB) -o $(NAME)
		
clean :
	rm -rf $(OBJ) $(OBJ_B)

fclean :
	rm -rf $(NAME) $(OBJ) $(OBJ_B)

bonus: fclean all

re: fclean $(NAME)
