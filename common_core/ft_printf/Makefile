# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afaris <afaris@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/29 17:04:31 by afaris            #+#    #+#              #
#    Updated: 2021/12/04 18:45:36 by afaris           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc

FLAGS = -Wall -Wextra -Werror

SRC = ft_putchar.c ft_put_hex_count.c ft_put_int_count.c ft_put_percent_count.c \
		ft_put_str_count.c ft_put_uns_int_count.c \
		ft_printf.c ft_put_var_addr_count.c

OBJ = ${SRC:.c=.o}

all: $(NAME)

.c.o:
	$(CC) $(FLAGS) -c $< -o $@
	ar crs $(NAME) $@
		
$(NAME): $(OBJ)

clean :
	rm -f ${OBJ}

fclean : clean
	rm -f $(NAME) 

re : fclean all

.PHONY: re fclean all clean