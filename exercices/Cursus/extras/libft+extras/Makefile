CC = cc
FLAGS = -Wall -Wextra -Werror

HEAD_DIR = includes/
SRCS_DIR = srcs/

NAME = libft.a

FILES = ft_tolower.c\
		ft_toupper.c\
		ft_isalnum.c\
		ft_isalpha.c\
		ft_isascii.c\
		ft_isdigit.c\
		ft_isprint.c\
		ft_strlen.c\
		ft_atoi.c\
		ft_bzero.c\
		ft_strdup.c\
		ft_strchr.c\
		ft_strrchr.c\
		ft_memset.c\
		ft_calloc.c\
		ft_memchr.c\
		ft_memcpy.c\
		ft_memmove.c\
		ft_memcmp.c\
		ft_strncmp.c\
		ft_strlcat.c\
		ft_strlcpy.c\
		ft_strnstr.c\
		ft_itoa.c\
		ft_putendl_fd.c\
		ft_putnbr_fd.c\
		ft_putstr_fd.c\
		ft_split.c\
		ft_striteri.c\
		ft_strjoin.c\
		ft_strmapi.c\
		ft_strtrim.c\
		ft_substr.c\
		ft_putchar_fd.c 


CHAIN_LISTS =   ft_listdup.c\
				len_list.c\
				create_cell.c\
				print_list.c\
				free_list.c\
				free_at.c\
				set_at.c\
				get_at.c\
				add_at.c


OBJS = $(FILES:.c=.o)
OBJS_BONUS = $(CHAIN_LISTS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	ar -rcs $(NAME) $(OBJS)

%.o : %.c
	$(CC) $(FLAGS) -c $< -o $@

clean :
	rm -f $(OBJS) $(OBJS_BONUS)

fclean : clean
	rm -f $(NAME)

re : fclean all

bonus : $(OBJS_BONUS)
	ar -rcs $(NAME) $(OBJS_BONUS)
