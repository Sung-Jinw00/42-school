#CC		= cc
#
#FLAGS	= -Wall -Wextra -Werror
#
#NAME	= libft.a
#
#HDRS	= includes
#
#OBLIGATOIRE_C	= ft_tolower.c ft_toupper.c ft_isalnum.c ft_isalpha.c ft_isascii.c\
#				  ft_isdigit.c ft_isprint.c ft_strlen.c ft_atoi.c ft_bzero.c ft_strdup.c\
#				  ft_strchr.c ft_strrchr.c ft_memset.c ft_calloc.c ft_memchr.c ft_memcpy.c\
#				  ft_memmove.c ft_memcmp.c ft_strncmp.c ft_strlcat.c ft_strlcpy.c ft_putchar_fd.c\
#				  ft_strnstr.c ft_itoa.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c\
#				  ft_split.c ft_striteri.c ft_strjoin.c ft_strmapi.c ft_strtrim.c ft_substr.c
#paco
#OBLIGATOIRE_O	= ${OBLIGATOIRE_C:.c=.o}
#
#BONUS_C	= ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstnew_bonus.c ft_lstadd_back_bonus.c ft_lstiter_bonus.c\
#		  ft_lstadd_front_bonus.c ft_lstclear_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstmap_bonus.c
#
#BONUS_O	= ${BONUS_C:.c=.o}
#
#RM		= rm -f
#
#CREATE	= ar rcs
#
#
#all :	${OBLIGATOIRE_C}
#		${CC} ${FLAGS} -I ${HDRS} -c ${OBLIGATOIRE_C}
#		${CREATE} ${NAME} ${OBLIGATOIRE_O}
#
#${NAME} : all
#
#clean :
#		${RM} ${OBLIGATOIRE_O}
#		${RM} ${BONUS_O}
#
#fclean :	clean
#		${RM} ${NAME}
#
#re : 	fclean all
#
#bonus : ${BONUS_C}
#		${CC} ${FLAGS} -I ${HDRS} -c ${BONUS_C} ${OBLIGATOIRE_C}
#		${CREATE} ${NAME} ${BONUS_O} ${OBLIGATOIRE_O}
#
#.PHONY: all clean fclean re bonus
CC = cc
FLAGS = -Wall -Wextra -Werror

HEAD_DIR = includes/
SRCS_DIR = srcs/

NAME = libft.a

FILES = ft_atoi.c                ft_lstclear_bonus.c   ft_memset.c      ft_strlcpy.c \
		ft_bzero.c               ft_lstdelone_bonus.c  ft_putchar_fd.c  ft_strlen.c \
		ft_calloc.c              ft_lstiter_bonus.c    ft_putendl_fd.c  ft_strmapi.c \
		ft_isalnum.c             ft_lstlast_bonus.c    ft_putnbr_fd.c   ft_strncmp.c \
		ft_isalpha.c             ft_lstmap_bonus.c     ft_putstr_fd.c   ft_strnstr.c \
		ft_isascii.c             ft_lstnew_bonus.c     ft_split.c       ft_strrchr.c \
		ft_isdigit.c             ft_lstsize_bonus.c    ft_strchr.c      ft_strtrim.c \
		ft_isprint.c             ft_memchr.c           ft_strdup.c      ft_substr.c \
		ft_itoa.c                ft_memcmp.c           ft_striteri.c    ft_tolower.c \
		ft_lstadd_back_bonus.c   ft_memcpy.c           ft_strjoin.c     ft_toupper.c \
		ft_lstadd_front_bonus.c  ft_memmove.c          ft_strlcat.c

FILES_BONUS = ft_lstclear_bonus.c \
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

bonus : $(OBJS) $(OBJS_BONUS)
	ar -rcs $(NAME) $(OBJS) $(OBJS_BONUS)