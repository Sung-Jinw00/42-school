MAKEFLAGS += -s  # Active le mode silencieux globalement

# Définition des variables
CC				= cc
FLAGS			= -Wall -Wextra -Werror -g
HDRS			= includes

SRCS			=  philo_/main.c philo_/utils.c philo_/utils2.c philo_/philo.c\
				   philo_/threads.c
SRC_O			= $(SRCS:philo_/.c=.o)
B_SRCS			=  philo_bonus_/main.c philo_bonus_/utils.c philo_bonus_/utils2.c\
				   philo_bonus_/sem.c philo_bonus_/philo.c
B_SRCS_O		= $(B_SRCS:philo_bonus_/.c=.o)
PHILO_NAME		= philo
B_PHILO_NAME	= philo_bonus
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
%.o: philo_/%.c $(HDRS)/*.h
	@echo $(CYAN)"Compilation de $<..."$(RESET)
	@$(CC) $(FLAGS) -I $(HDRS) -c $< -o $@

# Nettoyage des objets
clean:
	@echo $(CYAN)"Suppression des fichiers objets..."$(RESET)
	@$(RM) *.o */*.o */*/*.o

# Nettoyage complet
fclean: clean
	@echo $(CYAN)"Suppression de l'exécutable..."$(RESET)
	@$(RM) $(PHILO_NAME) $(B_PHILO_NAME)

# Récompilation depuis zéro
re: fclean all

bonus: $(B_SRCS_O)
	@echo $(CYAN)"Création du bonus..."$(RESET)
	@$(CC) $(FLAGS) $(B_SRCS_O) -I $(HDRS) -o $(B_PHILO_NAME)
	@echo $(GREEN)"Exécutable $(B_PHILO_NAME) créé !"$(RESET)

# Compilation des fichiers sources en objets (version bonus)
# On compile les fichiers .c dans philo_bonus/ en .o dans le répertoire racine
%.o: philo_bonus_/%.c $(HDRS)/*.h
	@echo $(CYAN)"Compilation de $<..."$(RESET)
	@$(CC) $(FLAGS) -I $(HDRS) -c $< -o $@

# Sécurité des règles
.PHONY: all clean fclean re
