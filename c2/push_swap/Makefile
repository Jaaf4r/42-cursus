CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
SRC		= *.c
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
