CC = cc
FLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

FILES = ft_itoa_base.c ft_printf.c ft_putnbr_fd.c ft_putstr_fd.c ft_putunbr_fd.c ft_strlen.c\
		ft_printf2.c

LIBFT = ft_printf.h

FILES_BONUS = ft_normal_solving_bonus.c ft_printf_bonus.c ft_printf2_bonus.c\
			  utils_bonus.c utils2_bonus.c utils3_bonus.c utils4_bonus.c\
			  utils5_bonus.c utils6_bonus.c utils7_bonus.c utils8_bonus.c

LIBFT_BONUS = ft_printf_bonus.h

OBJS = $(FILES:.c=.o)
OBJS_BONUS = $(FILES_BONUS:.c=.o)

all: ${NAME}

$(NAME): $(FILES)
	$(CC) $(FLAGS) -c $(FILES)
	ar rcs $(NAME) $(OBJS)

bonus: $(FILES_BONUS)
	$(CC) $(FLAGS) -c $(FILES_BONUS)
	ar rcs $(NAME) $(OBJS_BONUS)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re