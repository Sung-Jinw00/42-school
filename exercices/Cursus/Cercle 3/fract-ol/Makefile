# Désactivation de l'affichage des commandes par défaut
MAKEFLAGS += -s  # Active le mode silencieux globalement

# Définition des variables
GCC          = gcc
HDRS         = includes/*.h
FLAGS        = -Wall -Wextra -Werror -O3
NAME         = fractol
LIBFT_DIR    = ./libft
LIBFT        = $(LIBFT_DIR)/libft.a
MLX_DIR      = minilibx/minilibx-linux
MLX_FLAGS    = -L $(MLX_DIR) -lmlx -lXext -lX11 -lm
SRCS         = fract-ol.c other_file.c
OBJS         = $(SRCS:.c=.o)
RM           = rm -f
CREATE       = ar rcs

# Couleurs
RESET        = \033[0m
BLUE_LIGHT   = \033[1;34m  # Bleu clair
GREEN_LIGHT  = \033[1;32m  # Vert clair

# Règle par défaut
all: $(NAME)

# Création de l'exécutable
$(NAME): $(LIBFT) $(MLX_DIR)/libmlx.a $(OBJS)
	@$(GCC) $(FLAGS) $(OBJS) $(LIBFT) $(MLX_FLAGS) -I $(MLX_DIR) -I . -I ./libft -o $(NAME)

# Compilation des fichiers sources en objets
%.o: %.c $(HDRS)
	@echo "$(BLUE_LIGHT)Compilation de $< en cours...$(RESET)"
	@$(GCC) $(FLAGS) -I $(MLX_DIR) -I . -I ./libft -c $< -o $@

# Règle pour la libft
$(LIBFT):
	@echo "$(BLUE_LIGHT)Compilation de libft...$(RESET)"
	@make -s -C $(LIBFT_DIR) all
	@echo "$(GREEN_LIGHT)Compilation libft terminée !$(RESET)"

# Règle pour MiniLibX
$(MLX_DIR)/libmlx.a:
	@echo "$(BLUE_LIGHT)Compilation de MiniLibX...$(RESET)"
	@make -s -C $(MLX_DIR)
	@echo "$(GREEN_LIGHT)MiniLibX compilée !$(RESET)"

# Nettoyage des objets
clean:
	@echo "$(GREEN_LIGHT)Suppression des objets ✔️$(RESET)"
	@$(RM) $(OBJS)
	@make -s -C $(LIBFT_DIR) clean
	@make -s -C $(MLX_DIR) clean

# Nettoyage complet
fclean: clean
	@echo "$(GREEN_LIGHT)Suppression de l'exécutable ✔️$(RESET)"
	@$(RM) $(NAME)
	@make -s -C $(LIBFT_DIR) fclean
	@make -s -C $(MLX_DIR) clean

# Reset
re: fclean all

# Règle bonus (si applicable)
bonus: $(LIBFT) $(OBJS_BONUS)
	@echo "$(GREEN_LIGHT)Compilation des bonus ✔️$(RESET)"
	@$(GCC) $(FLAGS) $(OBJS_BONUS) $(LIBFT) $(MLX_FLAGS) -o $(NAME)

# Sécurité
.PHONY: all clean fclean re bonus
