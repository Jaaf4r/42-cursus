CC		= gcc
CFlAGS	= -Wall -Wextra -Werror

SRC		= so_long.c 

OBJ		= $(SRC:.c=.o)
RM		= rm -f
NAME	= so_long

.o: .c
		$(CC) $(CFlAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ) 
		$(CC) $(CFlAGS) $^ -o $@

clean:
		$(RM) $(OBJ)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
