CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

SRCS	=	ft_printf.c

OBJS	= $(SRCS:.c=.o)
NAME	= libftprintf.a
LIBC	= ar rcs
RM		= rm -f

.c.o:
		$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
		$(LIBC) $(NAME) $(OBJS)

all: $(NAME)

clean:
		$(RM) $(OBJS) $(OBJSB)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
