MAKEFLAGS += -s  # Active le mode silencieux globalement

# Définition des variables
CC				= cc
FLAGS			= -Wall -Wextra -Werror -g3
HDRS			= includes

SRCS			=  srcs/main.c srcs/utils.c srcs/utils2.c srcs/philo.c srcs/threads.c
SRC_O			= $(SRCS:srcs/.c=.o)
PHILO_NAME		= philo
RM				= rm -f
CYAN			= "\033[36m"
RED				= "\033[31m"
GREEN			= "\033[32m"
RESET			= "\033[0m"

# Règle par défaut : création de l'exécutable
all: $(PHILO_NAME)

# Création de l'exécutable
$(PHILO_NAME): $(SRC_O)
	@echo $(CYAN)"Création de l'exécutable $(PHILO_NAME)..."$(RESET)
	@$(CC) $(FLAGS) $(SRC_O) -I $(HDRS) -o $(PHILO_NAME)
	@echo $(GREEN)"Exécutable $(PHILO_NAME) créé !"$(RESET)

# Compilation des fichiers sources en objets
# On compiles les fichiers .c dans srcs/ en .o dans le répertoire racine
%.o: srcs/%.c $(HDRS)/*.h
	@echo $(CYAN)"Compilation de $<..."$(RESET)
	@$(CC) $(FLAGS) -I $(HDRS) -c $< -o $@

# Nettoyage des objets
clean:
	@echo $(CYAN)"Suppression des fichiers objets..."$(RESET)
	@$(RM) *.o */*.o */*/*.o

# Nettoyage complet
fclean: clean
	@echo $(CYAN)"Suppression de l'exécutable $(PHILO_NAME)..."$(RESET)
	@$(RM) $(PHILO_NAME)

# Récompilation depuis zéro
re: fclean all

checker/%.o: checker/%.c $(HDRS)/*.h
	@echo $(CYAN)"Compilation du fichier bonus $<..."$(RESET)
	@$(CC) $(FLAGS) -I $(HDRS) -c $< -o $@

# Sécurité des règles
.PHONY: all clean fclean re
