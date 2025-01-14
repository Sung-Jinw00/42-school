MAKEFLAGS += -s  # Active le mode silencieux globalement

# Définition des variables
CC          = cc
FLAGS       = -Wall -Wextra -Werror -g
HDRS        = includes

SRCS        =  srcs/algorythm.c srcs/error_managment.c srcs/list_creation.c srcs/main.c \
               srcs/moves.c srcs/moves2.c srcs/utils.c srcs/utils2.c srcs/utils3.c\
			   srcs/utils4.c srcs/to_print.c

SRCS_BONUS  =  srcs/algorythm.c srcs/error_managment.c srcs/list_creation.c\
               srcs/moves.c srcs/moves2.c srcs/utils.c srcs/utils2.c srcs/utils3.c\
			   srcs/utils4.c srcs/to_print.c\
			   checkerr/gnl_checker/get_next_line_bonus.c\
			   checkerr/gnl_checker/get_next_line_utils_bonus.c\
			   checkerr/srcs/checker_moves.c\
			   checkerr/srcs/checker_moves2.c \
               checkerr/srcs/checker.c\
			   checkerr/srcs/sort_list.c

SRC_O_BONUS = $(SRCS_BONUS:checker/%.c=%.o)

# Remplacement de srcs/algorythm.c par algorythm.o pour chaque fichier source
SRC_O			= $(SRCS:srcs/.c=.o)
PUSH_SWAP_NAME	= push_swap
CHECKER_NAME	= checker
RM				= rm -f
CYAN			= "\033[36m"
RED				= "\033[31m"
GREEN			= "\033[32m"
RESET			= "\033[0m"

# Règle par défaut : création de l'exécutable
all: $(PUSH_SWAP_NAME)

# Création de l'exécutable
$(PUSH_SWAP_NAME): $(SRC_O)
	@echo $(CYAN)"Création de l'exécutable $(PUSH_SWAP_NAME)..."$(RESET)
	@$(CC) $(FLAGS) $(SRC_O) -L lib -lftprintf -I $(HDRS) -o $(PUSH_SWAP_NAME)
	@echo $(GREEN)"Exécutable $(PUSH_SWAP_NAME) créé !"$(RESET)

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
	@echo $(CYAN)"Suppression de l'exécutable $(PUSH_SWAP_NAME)..."$(RESET)
	@echo $(CYAN)"Suppression de l'exécutable $(CHECKER_NAME)..."$(RESET)
	@$(RM) $(PUSH_SWAP_NAME) $(CHECKER_NAME)

# Récompilation depuis zéro
re: fclean all

checker/%.o: checker/%.c $(HDRS)/*.h
	@echo $(CYAN)"Compilation du fichier bonus $<..."$(RESET)
	@$(CC) $(FLAGS) -I $(HDRS) -c $< -o $@

bonus: $(SRC_O_BONUS)
	@echo $(CYAN)"Compilation des fichiers bonus..."$(RESET)
	@$(CC) $(FLAGS) $(SRC_O_BONUS) -L lib -lftprintf -I $(HDRS) -o $(CHECKER_NAME)
	@echo $(GREEN)"Exécutable bonus créé !"$(RESET)

# Sécurité des règles
.PHONY: all clean fclean re
