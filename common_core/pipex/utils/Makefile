NAME = pipex.a

CC = gcc

FLAGS = -Wall -Wextra -Werror -D BUFFER_SIZE=42

SRC = 	free/free_utils.c \
		gnl/get_next_line_utils.c gnl/get_next_line.c \
		pipex/pipex_utils.c \
		string/string_utils_1.c string/string_utils_2.c string/ft_split.c 

OBJ = ${SRC:.c=.o}

all: $(NAME)

.c.o:
	$(CC) $(FLAGS) -c $< -o $@
		
$(NAME): $(OBJ)

clean :
	rm -f ${OBJ}

fclean : clean
	rm -f $(NAME) 

re : fclean all

.PHONY: re fclean all clean