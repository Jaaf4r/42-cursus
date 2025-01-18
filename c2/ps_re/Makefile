CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

SRC		=	parse_input.c ft_split.c func_str.c \
			error_checks.c func_ll.c funcs_for_testing.c \
			stack_ops.c stack_ops2.c stack_ops3.c

OBJ		= $(SRC:.c=.o)
RM		= rm -f
LIBC	= ar rcs
NAME	= pushswap.a

.c.o:
		$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJ)
		$(LIBC) $(NAME) $(OBJ)

all: $(NAME)

clean:
		$(RM) $(OBJ)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: all fclean fclean re
