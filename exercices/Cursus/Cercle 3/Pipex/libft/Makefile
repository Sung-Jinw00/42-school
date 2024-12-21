CC = cc
FLAGS = -Wall -Wextra -Werror

NAME = libft.a

FILES = ft_tolower.c ft_toupper.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c\
		ft_isprint.c ft_strlen.c ft_atoi.c ft_bzero.c ft_strdup.c ft_strchr.c ft_strrchr.c\
		ft_memset.c ft_calloc.c ft_memchr.c ft_memcpy.c ft_memmove.c ft_memcmp.c ft_strncmp.c\
		ft_strlcat.c ft_strlcpy.c ft_strnstr.c ft_itoa.c ft_putendl_fd.c ft_putnbr_fd.c\
		ft_putstr_fd.c ft_split.c ft_striteri.c ft_strjoin.c ft_strmapi.c ft_strtrim.c\
		ft_substr.c ft_putchar_fd.c\
						\
		ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstnew_bonus.c ft_lstadd_back_bonus.c\
		ft_lstiter_bonus.c ft_lstadd_front_bonus.c ft_lstclear_bonus.c ft_lstdelone_bonus.c\
		ft_lstclear_bonus.c ft_lstmap_bonus.c\
						\
		ft_printf.c ft_printf2.c print_char_and_string.c print_hexa.c print_ptr.c\
		print_signed.c print_unsigned.c printf_utils.c printf_utils2.c printf_utils3.c\
						\
		get_next_line_bonus.c get_next_line_utils_bonus.c 


OBJS = $(FILES:.c=.o)

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
