CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

SRC			=	so_long.c store_map.c map_validation.c \
				road_check.c get_next_line/get_next_line.c \
				get_next_line/get_next_line_utils.c 

OBJ			= $(SRC:.c=.o)
RM			= rm -f
NAME		= so_long
LIBFT_DIR	= libft
LIBFT		= $(LIBFT_DIR)/libft.a

.c.o:
		$(CC) $(CFLAGS) -c $< -o $@

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
