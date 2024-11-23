NAME		= libftprintf.a

SRCS		= ft_printf.c ft_printf_func.c ft_printf_hex.c ft_itoa.c ft_putchar_fd.c ft_putstr_fd.c ft_strchr.c ft_strlen.c

OBJS		= $(SRCS:.c=.o)

CC			= cc

CFLAGS		= -Wall -Wextra -Werror

$(NAME): $(OBJS)
	ar rcs ${NAME} ${OBJS}

test:
	cc *.c $(CFLAGS)
	./a.out

all:		$(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re