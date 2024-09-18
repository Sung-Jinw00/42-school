# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/17 18:52:57 by locagnio          #+#    #+#              #
#    Updated: 2024/09/17 20:00:41 by locagnio         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= srcs/ft_putchar.c ft_swap.c ft_putstr.c ft_strlen.c ft_strcmp.c

HDRS	= ft.h

TEMP	= *.temp

RM		= rm -f

NAME	= all

all :	${NAME} ${SRCS}
		cc -Wall -Werror -Wextra libft.a
		mv ${SRCS} ..
		gcc -Wall -Wextra -Werror *.c

clean :
		${RM} ${TEMP}

fclean :	clean
		${RM} ${NAME}

re : 	fclean all

.PHONY: all clean fclean re
