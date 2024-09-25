CC		= cc

FLAGS	= -Wall -Wextra -Werror -g -fsanitize=address

HDRS	= includes

DIR_C	= srcs/bsq.c srcs/first_square.c srcs/read_params.c srcs/search_square.c srcs/utils.c srcs/split.c

SRCS_O	= bsq.o first_square.o read_params.o search_square.o utils.o split.o

DIR_O	= ${DIR_C:.c=.o}

RM		= rm -f

EXE		= bsq


all :	${DIR_C}
		${CC} ${FLAGS} -I ${HDRS} -c ${DIR_C}
		mv ${SRCS_O} srcs
		${CC} ${FLAGS} ${DIR_O} -o ${EXE}

clean :
		${RM} ${DIR_O}

fclean : clean
		${RM} ./${EXE}

re : 	clean fclean all

.PHONY: all clean fclean re
