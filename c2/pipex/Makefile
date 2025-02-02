CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -I $(LIBFT_DIR)

SRC		= main.c helper.c 

OBJ			= $(SRC:.c=.o)
RM			= rm -f
NAME		= pipex
LIBFT_DIR	= libft
LIBFT		= $(LIBFT_DIR)/libft.a

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME)	: $(OBJ) $(LIBFT)
		$(CC) $(CFLAGS) $^ -o $@

$(LIBFT):
		@make -C $(LIBFT_DIR)

all: $(NAME)

clean:
		$(RM) $(OBJ)
		@make -C $(LIBFT_DIR) clean

fclean: clean
		$(RM) $(NAME)
		@make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
