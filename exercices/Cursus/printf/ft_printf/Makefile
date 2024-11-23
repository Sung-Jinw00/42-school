CC = cc

FLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

LIBFT = ft_printf.h

FILES = ft_printf.c ft_printf2.c utils.c utils2.c utils3.c\
		utils4.c utils5.c utils6.c utils7.c utils8.c

OBJS = $(FILES:.c=.o)

all: ${NAME}

${NAME}: ${OBJS}
	ar rcs $@ $^

%.o: %.c
	${CC} ${FLAGS} -c $< -o $@

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

bonus: $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
