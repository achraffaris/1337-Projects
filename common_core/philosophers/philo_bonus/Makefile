NAME = philo.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -pthread
AR = ar rc

SRCS = 	philo_bonus.c \
		utils/ft_atoi.c \
		utils/actions.c \
		utils/ft_strjoin.c \
		utils/ft_itoa.c 

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@rm -rf $(NAME)
	@$(AR) $(NAME) $(OBJS)
	@$(CC) $(CFLAGS) $(NAME) -o philo_bonus

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)
	@rm -rf philo_bonus

re : fclean all

.PHONY: re fclean all clean