CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

SRC		=	former_main_xd.c parse_input.c ft_split.c func_str.c error_checks.c \
			func_ll.c stack_ops.c stack_ops2.c stack_ops3.c \
			algo_v1_lis.c algo_v1_helper.c algo_v2_nonlis.c \
			algo_v2_quick_sort.c algo2_moves.c algo3_lastSort.c funcs_for_testing.c \

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
