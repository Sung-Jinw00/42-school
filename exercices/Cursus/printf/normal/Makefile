CC = cc
FLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

FILES = ft_itoa_base.c ft_printf.c utils.c ft_printf2.c

FILES_BONUS = ft_normal_solving_bonus.c ft_printf_bonus.c ft_printf2_bonus.c\
			  utils_bonus.c utils2_bonus.c utils3_bonus.c utils4_bonus.c\
			  utils5_bonus.c utils6_bonus.c

OBJS = $(FILES:.c=.o)
OBJS_BONUS = $(FILES_BONUS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS) ft_printf.h
	ar -rcs $(NAME) $(OBJS) ft_printf.h

%.o : %.c
	$(CC) $(FLAGS) -c $< -o $@

clean :
	rm -f $(OBJS) $(OBJS_BONUS)

fclean : clean
	rm -f $(NAME)

re : fclean all

bonus : $(OBJS_BONUS) ft_printf_bonus.h
	ar -rcs $(NAME) $(OBJS_BONUS) ft_printf_bonus.h

.PHONY : all clean fclean re bonus