# Désactivation de l'affichage des commandes par défaut
MAKEFLAGS += -s  # Active le mode silencieux globalement

# Définition des variables
CC          = cc
HDRS        = includes/*.h
FLAGS       = -Wall -Wextra -Werror
NAME        = pipex
LIBFT_DIR   = ./libft
LIBFT       = $(LIBFT_DIR)/libft.a
SRCS        = pipex.c utils.c
#SRCS_BONUS  = pipex_bonus.c utils_bonus.c
OBJS        = $(SRCS:.c=.o)
#OBJS_BONUS  = $(SRCS_BONUS:.c=.o)
RM          = rm -f
CREATE      = ar rcs

# Couleurs
RESET       = \033[0m
BLUE_LIGHT  = \033[1;34m  # Bleu clair
GREEN_LIGHT = \033[1;32m  # Vert clair

# Règle par défaut
all: $(NAME)

# Création de l'exécutable
$(NAME): $(LIBFT) $(OBJS)
	@$(CC) $(FLAGS) $(OBJS) $(LIBFT) -o $(NAME)
	@echo "$(GREEN_LIGHT)Compilation terminée !$(RESET)"

# Compilation des fichiers sources en objets
%.o: %.c $(HDRS)
	@echo "$(BLUE_LIGHT)Compilation de $< en cours...$(RESET)"
	@$(CC) $(FLAGS) -c $< -o $@

# Règle pour la libft
$(LIBFT):
	@echo "$(BLUE_LIGHT)Compilation de l'executable en cours...$(RESET)"
	@make -s -C $(LIBFT_DIR) all

# Nettoyage des objets
clean:
	@echo "$(GREEN_LIGHT)Suppression des objets ✔️$(RESET)"
	@$(RM) $(OBJS)
	@make -s -C $(LIBFT_DIR) clean

# Monsieur propre
fclean: clean
	@echo "$(GREEN_LIGHT)Suppression de l'executable ✔️$(RESET)"
	@$(RM) $(NAME)
	@make -s -C $(LIBFT_DIR) fclean

# Reset
re: fclean all

# Règle bonus
#bonus: $(OBJS_BONUS)
#	@echo "$(BLUE_LIGHT)Compilation des fichiers bonus en cours...$(RESET)"
#	@$(CC) $(FLAGS) $(OBJS_BONUS) $(LIBFT) -o $(NAME)

# Sécurité
.PHONY: all clean fclean re bonus
