NAME = philo.a
NAME_BONUS = philo_bonus.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -pthread
AR = ar rc

SRCS = 	philo.c \
		utils/ft_atoi.c \
		
BSRCS = 
		
BOBJS = $(BSRCS:.c=.o)
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@rm -rf $(NAME_BONUS)
	@$(AR) $(NAME) $(OBJS)
	@$(CC) $(CFLAGS) $(NAME) -o philo

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(BOBJS)
	@rm -rf $(NAME)
	@$(AR) $(NAME_BONUS) $(BOBJS)
	@$(CC) $(CFLAGS) $(NAME_BONUS) -o philo_bonus 

clean:
	@rm -rf $(OBJS) $(BOBJS)

fclean: clean
	@rm -rf $(NAME) $(NAME_BONUS)
	@rm -rf philo

re : fclean all

.PHONY: re fclean all clean bonus