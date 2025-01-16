# Définition des variables
GCC        = gcc
FLAGS      = -Wall -Wextra -Werror -g
HDRS       = includes
MLX_HDRS = minilibx/minilibx-linux
FT_PRINTF_HDRS = ft_printf

SRCS_C		= srcs/colors.c\
			  srcs/controls.c\
			  srcs/display_fractals.c\
			  srcs/errors.c\
			  srcs/ft_atod.c\
			  srcs/ft_bzero.c\
			  srcs/ft_calloc.c\
			  srcs/ft_putstr_fd.c\
			  srcs/ft_strcmp_frctl.c\
			  srcs/hooks.c\
			  srcs/main.c\
			  srcs/set_fractals.c\
			  srcs/set_fractals2.c\
			  srcs/set_mlx.c

SRC_O      = $(SRCS_C:.c=.o)
NAME       = fract-ol
RM         = rm -f
MLX_FLAGS  = -L minilibx/minilibx-linux -lmlx -lXext -lX11 -lm
LIB_PATH   = minilibx/minilibx-linux
LIB_MLX    = $(LIB_PATH)/libmlx.a
CYAN	   = "\033[36m"
RED		   = "\033[31m"
GREEN	   = "\033[32m"
RESET	   = "\033[0m"


# Règle par défaut : création de l'exécutable
all: $(NAME)

# Création de l'exécutable
$(NAME): $(SRC_O) $(LIB_MLX)
	@echo $(CYAN)"Création de l'exécutable $(NAME)..."$(RESET)
	@$(GCC) $(FLAGS) $(SRC_O) $(LIB_MLX) $(MLX_FLAGS) -L lib -lftprintf -I $(HDRS) -I $(MLX_HDRS) -o $(NAME)
	@echo $(GREEN)"Exécutable $(NAME) créé !"$(RESET)

# Compilation des fichiers sources en objets
$(SRC_O): srcs/%.o: srcs/%.c $(HDRS)
	@echo $(CYAN)"Compilation de $<..."$(RESET)
	@$(GCC) $(FLAGS) -I $(HDRS) -I $(MLX_HDRS) -c $< -o $@ -s

# Règle pour la compilation de MiniLibX
$(LIB_MLX):
	@echo $(CYAN)"Compilation de MiniLibX..."$(RESET)
	@make -s -C $(LIB_PATH)
	@echo $(GREEN)"MiniLibX compilée !"$(RESET)

# Nettoyage des objets
clean:
	@echo $(CYAN)"Suppression des fichiers objets..."$(RESET)
	@$(RM) srcs/*.o

# Nettoyage complet
fclean: clean
	@echo $(CYAN)"Suppression de l'exécutable $(NAME)..."$(RESET)
	@$(RM) $(NAME)
	@make -s -C $(LIB_PATH) clean

# Récompilation depuis zéro
re: fclean all

# Sécurité des règles
.PHONY: all clean fclean re