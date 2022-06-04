NAME = push_swap.a
NAME_BONUS = checker.a

CC = cc
CFLAGS = -Wall -Wextra -Werror 
AR = ar rc

SRCS = 	push_swap.c \
		utils/checker.c \
		utils/strings.c \
		utils/exit.c \
		utils/actions/stack_a.c \
		utils/actions/stack_b.c \
		utils/actions/stack_ab.c \
		utils/comp.c \
		utils/actions/utils.c \
		
BSRCS = checker.c
		
BOBJS = $(BSRCS:.c=.o)
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@rm -rf $(NAME_BONUS)
	@$(AR) $(NAME) $(OBJS)
	@$(CC) $(CFLAGS) $(NAME) -o push_swap

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(BOBJS)
	@rm -rf $(NAME)
	@$(AR) $(NAME_BONUS) $(BOBJS)
	@$(CC) $(CFLAGS) $(NAME_BONUS) -o checker 

clean:
	@rm -rf $(OBJS) $(BOBJS)

fclean: clean
	@rm -rf $(NAME) $(NAME_BONUS)
	@rm -rf push_swap

re : fclean all

.PHONY: re fclean all clean bonus