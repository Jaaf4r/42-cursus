CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

SRC			= main.c 

OBJ			= $(SRC:.c=.o)
RM			= rm -rf
NAME		= pipex
LIBFT_DIR	= libft
LIBFT		= $(LIBFT_DIR)/libft.a

.o: .c
		$(CC) $(CFLAGS) $< -o $@

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
		$(CC) $(CFLAGS) $^ -o $@

$(LIBFT):
		@make -C $(LIBFT_DIR)

clean:
		$(RM) $(OBJ)
		@make -C $(LIBFT_DIR) clean

fclean: clean
		$(RM) $(NAME)
		@make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
