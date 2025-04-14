MAKEFLAGS += -s

CC = cc
FLAGS = -Wall -Wextra -Werror -g

SRCS_DIR = srcs/
INCLUDES = includes/

NAME = libft.a

SRCS = $(shell find srcs -type f -name '*.c')

OBJS = $(SRCS:.c=.o)

CYAN	= "\033[36m"
GREEN	= "\033[32m"
RESET	= "\033[0m"

all : message $(NAME)


message:
	@echo $(CYAN)"Compilation de la libft..."$(RESET)

$(NAME) : $(OBJS)
	ar -rcs $(NAME) $(OBJS)
	@echo $(GREEN)"libft crée !"$(RESET)

%.o : %.c
	$(CC) $(FLAGS) -I $(INCLUDES) -c $< -o $@

clean :
	rm -f $(OBJS) $(OBJS_BONUS)

fclean : clean
	rm -f $(NAME)

re : fclean all