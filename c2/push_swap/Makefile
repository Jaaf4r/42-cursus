CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

SRC		= ft_split.c ft_strdup.c ft_atoi.c parse_input.c helper_ll.c \
		  stack_ops.c stack_ops2.c stack_ops3.c \
		  ft_printf.c algo1_lis.c algo2_backInOrder.c

OBJ		= $(SRC:.c=.o)
NAME	= pushswap.a
LIBC	= ar rcs
RM		= rm -f

.c.o:
		$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
		$(LIBC) $(NAME) $(OBJ)

all: $(NAME)

clean:
		$(RM) $(OBJ)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
