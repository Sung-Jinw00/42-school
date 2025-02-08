SHELL		=	/bin/bash

NAMEBC		= client_bonus
NAMEBS		= server_bonus
INC			= inc
HEADER		= -I inc
SRC_DIR		= src/
OBJ_DIR		= obj/
CC			= gcc
FLAGS		= -Wall -Werror -Wextra
RM			= rm -f
ECHO		= echo -e

DEF_COLOR	=	\033[0;39m
ORANGE		=	\033[0;33m
GRAY		=	\033[0;90m
RED			=	\033[0;91m
GREEN		=	\033[1;92m
YELLOW		=	\033[1;93m
BLUE		=	\033[0;94m
MAGENTA		=	\033[0;95m
CYAN		=	\033[0;96m
WHITE		=	\033[0;97m

SRCBC_FILES	=	client_bonus
SRCBS_FILES	=	server_bonus

SRCBC 		= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRCBC_FILES)))
OBJBC 		= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRCBC_FILES)))

SRCBS 		= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRCBS_FILES)))
OBJBS 		= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRCBS_FILES)))


OBJF		=	.cache_exists

# Règle par défaut : création de l'exécutable
all: $(NAME)

# Création de l'exécutable
$(NAME): $(SRC_O)
	@echo $(CYAN)"Création de l'exécutable $(NAME)..."$(RESET)
	@$(CC) $(FLAGS) $(SRC_O) -L lib -lfprintf -I $(HDRS) -o $(NAME)
	@echo $(GREEN)"Exécutable $(NAME) créé !"$(RESET)

# Compilation des fichiers sources en objets
# On compiles les fichiers .c dans srcs/ en .o dans le répertoire racine
%.o: philo\ /%.c $(HDRS)/*.h
	@echo $(CYAN)"Compilation de $<..."$(RESET)
	@$(CC) $(FLAGS) -I $(HDRS) -c $< -o $@

# Nettoyage des objets
clean:
	@echo $(CYAN)"Suppression des fichiers objets..."$(RESET)
	@$(RM) *.o */*.o */*/*.o

# Nettoyage complet
fclean: clean
	@echo $(CYAN)"Suppression de l'exécutable..."$(RESET)
	@$(RM) $(NAME)

# Récompilation depuis zéro
re: fclean all

# Sécurité des règles
.PHONY: all clean fclean re