CC = cc
FLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

LIBFT = ft_printf.h

FILES = ft_normal_solving.c ft_printf.c ft_printf2.c\
			  utils.c utils2.c utils3.c utils4.c\
			  utils5.c utils6.c utils7.c utils8.c

LIBFT_BONUS = ft_printf_bonus.h

OBJS = $(FILES:.c=.o)
OBJS_BONUS = $(FILES_BONUS:.c=.o)

all: ${NAME}

$(NAME): $(FILES)
	$(CC) $(FLAGS) -c $(FILES)
	ar rcs $(NAME) $(OBJS)

bonus: $(NAME)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re