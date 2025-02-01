CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

SRC		= main.c 

OBJ		= $(SRC:.c=.o)
RM		= rm -f
NAME	= pipex

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME)	: $(OBJ)
		$(CC) $(CFLAGS) $^ -o $@

all: $(NAME)

clean:
		$(RM) $(OBJ)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
