CC = cc
FLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

FILES = ft_itoa_base.c ft_printf.c ft_putnbr_fd.c ft_putstr_fd.c ft_putunbr_fd.c ft_strlen.c\
		ft_printf2.c

#FILES_BONUS = ft_lstclear_bonus.c \
			ft_lstdelone_bonus.c  \
			ft_lstiter_bonus.c    \
			ft_lstlast_bonus.c    \
			ft_lstmap_bonus.c     \
			ft_lstnew_bonus.c     \
			ft_lstsize_bonus.c    \

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

#bonus : $(OBJS) $(OBJS_BONUS)
#	ar -rcs $(NAME) $(OBJS) $(OBJS_BONUS)