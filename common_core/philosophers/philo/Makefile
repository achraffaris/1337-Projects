NAME = philo.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -pthread
AR = ar rc

SRCS = 	philo.c \
		utils/ft_atoi.c \
		utils/simulation.c \
		utils/actions.c
		
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(AR) $(NAME) $(OBJS)
	@$(CC) $(CFLAGS) $(NAME) -o philo

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)
	@rm -rf philo

re : fclean all

.PHONY: re fclean all clean