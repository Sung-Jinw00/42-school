# Désactivation de l'affichage des commandes par défaut
MAKEFLAGS += -s  # Active le mode silencieux globalement

# Définition des variables
CC          = cc
FLAGS       = -Wall -Wextra -Werror -g
HDRS        = includes
FT_PRINTF_HDRS = ft_printf

SRCS        =  srcs/algorythm.c srcs/error_managment.c srcs/list_creation.c srcs/main.c \
              srcs/moves.c srcs/moves2.c srcs/utils.c srcs/utils2.c srcs/utils3.c

# Remplacement de srcs/algorythm.c par algorythm.o pour chaque fichier source
SRC_O       = $(SRCS:srcs/.c=.o)
NAME        = push_swap
RM          = rm -f
CYAN        = "\033[36m"
RED         = "\033[31m"
GREEN       = "\033[32m"
RESET       = "\033[0m"

# Règle par défaut : création de l'exécutable
all: $(NAME)

# Création de l'exécutable
$(NAME): $(SRC_O)
	@echo $(CYAN)"Création de l'exécutable $(NAME)..."$(RESET)
	@$(CC) $(FLAGS) $(SRC_O) -L lib -lftprintf -I $(HDRS) -o $(NAME)
	@echo $(GREEN)"Exécutable $(NAME) créé !"$(RESET)

# Compilation des fichiers sources en objets
# On compiles les fichiers .c dans srcs/ en .o dans le répertoire racine
%.o: srcs/%.c $(HDRS)/*.h
	@echo $(CYAN)"Compilation de $<..."$(RESET)
	@$(CC) $(FLAGS) -I $(HDRS) -c $< -o $@

# Nettoyage des objets
clean:
	@echo $(CYAN)"Suppression des fichiers objets..."$(RESET)
	@$(RM) *.o  # Nettoie les fichiers objets dans le répertoire racine

# Nettoyage complet
fclean: clean
	@echo $(CYAN)"Suppression de l'exécutable $(NAME)..."$(RESET)
	@$(RM) $(NAME)

# Récompilation depuis zéro
re: fclean all

# Sécurité des règles
.PHONY: all clean fclean re
