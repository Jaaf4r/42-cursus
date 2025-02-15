CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

SRC			= main.c process.c path_utils.c 

SRCBNS		=	bonus/main_bonus.c bonus/path_utils_bonus.c \
				bonus/multiple_pipes_bonus.c \
				bonus/get_next_line/get_next_line_utils.c \
				bonus/get_next_line/get_next_line.c 

OBJ			= $(SRC:.c=.o)
OBJBNS		= $(SRCBNS:.c=.o)
RM			= rm -rf
NAME		= pipex
LIBFT_DIR	= libft
LIBFT		= $(LIBFT_DIR)/libft.a
BONUS		= pipex_bonus

.c.o:
		$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
		$(CC) $(CFLAGS) $^ -o $@

bonus: $(BONUS)

$(BONUS): $(OBJBNS) $(LIBFT)
		$(CC) $(CFLAGS) $^ -o $@

$(LIBFT):
		@make -C $(LIBFT_DIR)

clean:
		$(RM) $(OBJ) $(OBJBNS)
		@make -C $(LIBFT_DIR) clean

fclean: clean
		$(RM) $(NAME) $(BONUS)
		@make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all bonus clean fclean re
