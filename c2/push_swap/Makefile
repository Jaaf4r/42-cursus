CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -g 

SRC		=	main.c parse_input.c ft_split.c func_str.c \
			error_checks.c func_ll.c stack_ops.c stack_ops2.c stack_ops3.c \
			algo_v1_lis.c algo_v1_helper.c algo_v2_nonlis.c \
			algo_v2_quick_sort.c algo_v3_best_pos.c algo_v3_pushback_to_a.c \
			algo_v4_last_sort.c algo_sort_three.c algo_sort_five.c \

SRCBONUS =	parse_input.c ft_split.c func_str.c error_checks.c \
			func_ll.c stack_ops.c stack_ops2.c stack_ops3.c \
			my_checker/main.c my_checker/get_next_line/get_next_line.c \
			my_checker/get_next_line/get_next_line_utils.c \
			my_checker/printf/ft_printf.c algo_v1_helper.c 


OBJBONUS	= $(SRCBONUS:.c=.o)
OBJ			= $(SRC:.c=.o)
RM			= rm -f
NAME		= push_swap
CHECKERNAME	= checker

.c.o:
		$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME) : $(OBJ)
		$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

bonus: $(CHECKERNAME)

$(CHECKERNAME) : $(OBJBONUS)
		$(CC) $(CFLAGS) $(OBJBONUS) -o $(CHECKERNAME)

clean:
		$(RM) $(OBJ) $(OBJBONUS)

fclean: clean
		$(RM) $(NAME) $(CHECKERNAME)

re: fclean all

.PHONY: all clean fclean re bonus
