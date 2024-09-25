CC		= cc

FLAGS	= -Wall -Wextra -Werror

HDRS	= includes

SRCS_C	= srcs/main.c srcs/conversions_et_mess.c srcs/operators.c

SRCS_O	= main.o conversions_et_mess.o operators.o

DIR_O	= ${SRCS_C:.c=.o}

RM		= rm -f

EXE		= do-op


all :	${SRCS_C}
		${CC} ${FLAGS} -I ${HDRS} -c ${SRCS_C}
		mv ${SRCS_O} srcs
		${CC} ${FLAGS} ${DIR_O} -o ${EXE}

clean :
		${RM} ${DIR_O}

fclean : clean
		${RM} ./${EXE}

re : 	clean fclean all

.PHONY: all clean fclean re
