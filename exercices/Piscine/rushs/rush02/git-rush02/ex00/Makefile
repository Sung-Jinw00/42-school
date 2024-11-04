SRC = src/assignments.c \
	  src/ft_split.c \
	  src/main.c \
	  src/parser.c \
	  src/sort_numbers.c \
	  src/utils.c

CFLAGS = -Wall -Wextra -Werror

OBJ = ${SRC:.c=.o}

NAME = rush-02

.PHONY: all clean fclean re

.c.o:
	cc ${CFLAGS} -c $< -o ${<:.c=.o} -I includes

all: ${NAME}

${NAME}: ${OBJ}
	cc ${CFLAGS} ${OBJ} -o ${NAME} -I includes

clean:
	rm -f ${OBJ}

fclean: clean
	rm -f ${NAME}

re: fclean all

