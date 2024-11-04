GCC		= gcc

FLAGS	= -Wall -Wextra -Werror

LIB_NAME	= libft.a

HDRS	= includes

SRCS_C	= srcs/ft_putchar.c srcs/ft_putstr.c srcs/ft_strcmp.c srcs/ft_strlen.c srcs/ft_swap.c

O	= ft_putchar.o ft_putstr.o ft_strcmp.o ft_strlen.o ft_swap.o

SRCS_O	= srcs/ft_putchar.o srcs/ft_putstr.o srcs/ft_strcmp.o srcs/ft_strlen.o srcs/ft_swap.o

RM		= rm -f

CREATE	= ar rcs


all :	${SRCS_C}
		${GCC} ${FLAGS} -I ${HDRS} -c ${SRCS_C}
		mv ${O} srcs
		${CREATE} ${LIB_NAME} ${SRC_O}

${LIB_NAME} : all

clean :
		${RM} ${SRCS_O}

fclean :	clean
		${RM} ${LIB_NAME}

re : 	fclean all

.PHONY: all clean fclean re
