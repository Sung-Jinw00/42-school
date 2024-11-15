CC = cc
FLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

FILES = ft_printf.c ft_printf2.c ft_utils.c ft_utils2.c ft_bonusline.c ft_bonusnbs.c

FILES_BONUS = ft_bonusline.c ft_bonusnbs.c

OBJS = $(FILES:.c=.o)
OBJS_BONUS = $(FILES_BONUS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	ar -rcs $(NAME) $(OBJS)

%.o : %.c
	$(CC) $(FLAGS) -c $< -o $@

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

bonus : $(OBJS) $(OBJS_BONUS)
	ar -rcs $(NAME) $(OBJS) $(OBJS_BONUS)