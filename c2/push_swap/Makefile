CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

SRC		=	main.c parse_input.c ft_split.c func_str.c \
			error_checks.c func_ll.c stack_ops.c stack_ops2.c stack_ops3.c \
			algo_v1_lis.c algo_v1_helper.c algo_v2_nonlis.c \
			algo_v2_quick_sort.c algo_v3_best_pos.c algo_v3_pushback_to_a.c \
			algo_v4_last_sort.c funcs_for_testing.c 

OBJ			= $(SRC:.c=.o)
RM			= rm -f
LIBC		= ar rcs
PROGNAME	= push_swap

.c.o:
		$(CC) $(CFLAGS) -c $< -o $@

$(PROGNAME) : $(OBJ)
		$(CC) $(CFLAGS) $(OBJ) -o $(PROGNAME)

all: $(PROGNAME)

clean:
		$(RM) $(OBJ)

fclean: clean
		$(RM) $(PROGNAME)

re: fclean all

.PHONY: all clean fclean re
