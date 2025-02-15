MAKEFLAGS += -s  # Active le mode silencieux globalement

# Définition des variables
C++				= c++
FLAGS			= -Wall -Wextra -Werror -std=c++98 -g
HDRS			= includes

SRCS			=  megaphone.cpp
SRC_O			= $(SRCS:.cpp=.o)
MEGAPHONE		= megaphone
RM				= rm -f
CYAN			= "\033[36m"
RED				= "\033[31m"
GREEN			= "\033[32m"
RESET			= "\033[0m"

# Règle par défaut : création de l'exécutable
all: $(MEGAPHONE)

# Création de l'exécutable
$(MEGAPHONE): $(SRC_O)
	@echo $(CYAN)"Création de l'exécutable $(MEGAPHONE)..."$(RESET)
	@$(C++) $(FLAGS) $(SRC_O) -o $(MEGAPHONE)
	@echo $(GREEN)"Exécutable $(MEGAPHONE) créé !"$(RESET)

# Compilation des fichiers sources en objets
# On compiles les fichiers .c dans srcs/ en .o dans le répertoire racine
%.o: %.c
	@echo $(CYAN)"Compilation de $<..."$(RESET)
	@$(C++) $(FLAGS) -c $< -o $@

# Nettoyage des objets
clean:
	@echo $(CYAN)"Suppression des fichiers objets..."$(RESET)
	@$(RM) *.o

# Nettoyage complet
fclean: clean
	@echo $(CYAN)"Suppression de l'exécutable..."$(RESET)
	@$(RM) $(MEGAPHONE) 

# Récompilation depuis zéro
re: fclean all

# Sécurité des règles
.PHONY: all clean fclean re
