/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:00:12 by locagnio          #+#    #+#             */
/*   Updated: 2024/11/04 14:00:12 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

///////////////////////////////// [Headers] ///////////////////////////////////
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <limits.h>
# include <string.h>
# include <sys/wait.h>
# include "mlx.h"

////////////////////////////////// [libft] ////////////////////////////////////
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

int			ft_isalnum(int c);
int			ft_isalpha(int c);
int			ft_isascii(int c);
int			ft_isdigit(int c);
int			ft_isprint(int c);
int			ft_tolower(int c);
int			ft_toupper(int c);
int			ft_atoi(const char *nptr);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		ft_putnbr_fd(int n, int fd);
void		ft_bzero(void *s, size_t n);
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
char		*ft_itoa(int n);
char		*ft_strdup(const char *src);
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strtrim(char const *s1, char const *set);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strnstr(const char	*big, const char *little, size_t len);
void		*ft_memset(void *s, int c, size_t n);
void		*ft_calloc(size_t nmemb, size_t size);
void		*ft_memchr(const void *s, int c, size_t n);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		*ft_memmove(void *dest, const void *src, size_t n);
char		**ft_split(char const *str, char charset);
size_t		ft_strlen(const char *s);
size_t		ft_strlcat(char *dst, const char *src, size_t dsize);
size_t		ft_strlcpy(char *dst, const char *src, size_t dsize);

int			ft_lstsize(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstadd_front(t_list **lst, t_list *new);
void		ft_lstiter(t_list *lst, void (*f)(void *));
void		ft_lstclear(t_list **lst, void (*del)(void *));
void		ft_lstdelone(t_list *lst, void (*del)(void *));
t_list		*ft_lstlast(t_list *lst);
t_list		*ft_lstnew(void *content);
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

////////////////////////////// [get_next_line] ////////////////////////////////
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char		*get_next_line(int fd);
char		*ft_strjoin_gnl(char *s1, char *s2);
size_t		ft_strclen(const char *s, char c);

//////////////////////////////// [ft_printf] //////////////////////////////////
typedef struct s_struct
{
	const char	*str;
	char		flags[7];
	int			nb1;
	int			nb2;
	int			zeros;
}	t_struct;

int			ft_printf(const char *str, ...);
int			ft_digits(long n);
int			srch_flag(char *s, char c);
int			ft_strcmp(char *s1, char *s2);
int			standard_conds(t_struct v, int i);
int			print_this_bs(va_list args, t_struct v);
char		bonus_flag_finder(int i, t_struct v);
void		ft_putnbr(long n, t_struct v, long base, long print);
void		ptr_print(size_t nb, t_struct v);
void		ft_putunbr(unsigned long n, t_struct v);
void		ft_putstr(char *s, int *count, int limit);
void		hexa_print(unsigned int nb, t_struct v, char x);
void		ft_print_char(char c, t_struct v, int *count);
void		ft_print_int(long nb, t_struct v, int *count);
void		ft_print_hexa(unsigned int nb, t_struct v, int i, int *count);
void		ft_print_str(char *str, t_struct v, int *count);
void		ft_print_ptr(size_t ptr, t_struct v, int *count);
void		ft_print_uns_int(long nb, t_struct v, int *count);
void		ft_print_percent(char percent, int *count);
t_struct	flag_filter(int i, t_struct v);
t_struct	flags(char c, t_struct v);
t_struct	erase_flag(char erased, t_struct v);
t_struct	parse_nd_flags2(int *i, t_struct v, va_list args);
t_struct	keep_prior_flag(char erased, char prior, t_struct v);

////////////////////////////////// [pipex] ////////////////////////////////////
void		pipex(int ac, char **av, char **envp);
int			ft_strnchr(const char *s, const char *to_find, int len);
void		execute(char *argv, char **envp);
void		read_stdin(int *fd, char *limiter);
void		free_dbl_tab(char **str);

///////////////////////////////// [fract-ol] //////////////////////////////////
typedef struct s_colors
{
    unsigned int alpha;
    unsigned int red;
    unsigned int green;
    unsigned int blue;
	double angle;
    double coef;
    double color;
}	t_colors;

typedef struct s_fl_params
{
	char	*name;
	double	x;
	double	y;
	double	real;
	double	imaginary;
}	t_fl_params;

typedef struct s_pixels
{
	int		x;
	int		y;
	int 	color;
	double	w_move;
	double	h_move;
	double	w_scale;
	double	h_scale;
}	t_pixels;

typedef struct	s_data
{
	char	*addr;
	void	*img_ID;
	int		endian;
	int		line_length;
	int		bits_per_pixel;
}	t_data;

typedef struct s_mlx
{
	void		*init;
	void		*window;
	t_data		img;
	t_pixels	pixel;
	t_fl_params	f_params;
}	t_mlx;


//nom des fractales
# define MANDELBROT "Mandelbrot"
# define JULIA "Julia"

//parametres mlx et verif des equations
# define WIDTH 1400
# define HEIGHT 1000
# define MAX_ITER 100

// Définitions de la souris
# define LEFT_CLICK 1
# define SCROLL_CLICK 2
# define RIGHT_CLICK 3
# define SCROLL_UP 4
# define SCROLL_DOWN 5
# define CLOSE_WINDOW 17

// Définitions des touches principales
# define ESC 65307           // Touche Escape
# define LEFT_ARROW 65361    // Flèche gauche
# define UP_ARROW 65362      // Flèche haut
# define RIGHT_ARROW 65363   // Flèche droite
# define DOWN_ARROW 65364    // Flèche bas

// Définitions des touches de contrôle
# define BACKSPACE 65288     // Touche Retour arrière
# define TAB 65289           // Touche Tabulation
# define CAPS_LOCK 65509     // Touche Verrouillage Majuscule
# define LEFT_SHIFT 65505    // Touche Majuscule gauche
# define RIGHT_SHIFT 65506   // Touche Majuscule droite
# define LEFT_CTRL 65507     // Touche Contrôle gauche
# define RIGHT_CTRL 65508    // Touche Contrôle droite
# define LEFT_ALT 65513      // Touche Alt gauche
# define RIGHT_ALT 65514     // Touche Alt droite

// Définition des touches de fonction (F1 à F12)
# define F1 65470            // Fonction F1
# define F2 65471            // Fonction F2
# define F3 65472            // Fonction F3
# define F4 65473            // Fonction F4
# define F5 65474            // Fonction F5
# define F6 65475            // Fonction F6
# define F7 65476            // Fonction F7
# define F8 65477            // Fonction F8
# define F9 65478            // Fonction F9
# define F10 65479           // Fonction F10
# define F11 65480           // Fonction F11
# define F12 65481           // Fonction F12

// Définitions des touches de navigation
# define HOME 65360          // Touche Home
# define PAGE_UP 65365      // Touche Page Up
# define PAGE_DOWN 65366    // Touche Page Down
# define END 65367          // Touche End
# define INSERT 65379       // Touche Insert
# define DELETE 65535      // Touche Supprimer

// Définitions du pavé numérique
# define NUM_LOCK 65407     // Touche Num Lock
# define NUM_DIVIDE 65455   // Touche / (division)
# define NUM_MULTIPLY 65450 // Touche * (multiplication)
# define NUM_SUBTRACT 65453 // Touche - (soustraction)
# define NUM_ADD 65451      // Touche + (addition)
# define NUM_0 65438        // Touche 0 (pavé numérique)
# define NUM_1 65436        // Touche 1 (pavé numérique)
# define NUM_2 65437        // Touche 2 (pavé numérique)
# define NUM_3 65438        // Touche 3 (pavé numérique)
# define NUM_4 65440        // Touche 4 (pavé numérique)
# define NUM_5 65441        // Touche 5 (pavé numérique)
# define NUM_6 65442        // Touche 6 (pavé numérique)
# define NUM_7 65443        // Touche 7 (pavé numérique)
# define NUM_8 65444        // Touche 8 (pavé numérique)
# define NUM_9 65445        // Touche 9 (pavé numérique)

# define PI 3.14159265358979323846

int		main(int ac, char **av);
void	error(char *error_message);
char	*ft_fratal_name(char *fractal_name);

////////////////////////////////// [Colors] ///////////////////////////////////
/* Définition des couleurs de texte */
# define RESET       "\033[0m"  // Réinitialisation
# define BOLD        "\033[1m"  // Texte en gras
# define UNDERLINE   "\033[4m"  // Texte souligné
# define ITALIC      "\033[3m"  // Texte en italique
# define REVERSED    "\033[7m"  // Texte inversé (fond et texte inversés)

# define BLACK       "\033[30m"  // Couleur noire
# define RED         "\033[31m"  // Couleur rouge
# define GREEN       "\033[32m"  // Couleur verte
# define YELLOW      "\033[33m"  // Couleur jaune
# define BLUE        "\033[34m"  // Couleur bleue
# define MAGENTA     "\033[35m"  // Couleur magenta
# define CYAN        "\033[36m"  // Couleur cyan
# define WHITE       "\033[37m"  // Couleur blanche

# define BRIGHT_BLACK  "\033[90m"  // Couleur noire claire
# define BRIGHT_RED    "\033[91m"  // Couleur rouge clair
# define BRIGHT_GREEN  "\033[92m"  // Couleur verte claire
# define BRIGHT_YELLOW "\033[93m"  // Couleur jaune clair
# define BRIGHT_BLUE   "\033[94m"  // Couleur bleue claire
# define BRIGHT_MAGENTA "\033[95m" // Couleur magenta claire
# define BRIGHT_CYAN   "\033[96m"  // Couleur cyan clair
# define BRIGHT_WHITE  "\033[97m"  // Couleur blanche claire

/* Définition des couleurs de fond */
# define BG_BLACK     "\033[40m"  // Fond noir
# define BG_RED       "\033[41m"  // Fond rouge
# define BG_GREEN     "\033[42m"  // Fond vert
# define BG_YELLOW    "\033[43m"  // Fond jaune
# define BG_BLUE      "\033[44m"  // Fond bleu
# define BG_MAGENTA   "\033[45m"  // Fond magenta
# define BG_CYAN      "\033[46m"  // Fond cyan
# define BG_WHITE     "\033[47m"  // Fond blanc

# define BG_BRIGHT_BLACK "\033[100m"  // Fond noir clair
# define BG_BRIGHT_RED   "\033[101m"  // Fond rouge clair
# define BG_BRIGHT_GREEN "\033[102m"  // Fond vert clair
# define BG_BRIGHT_YELLOW "\033[103m" // Fond jaune clair
# define BG_BRIGHT_BLUE  "\033[104m"  // Fond bleu clair
# define BG_BRIGHT_MAGENTA "\033[105m"// Fond magenta clair
# define BG_BRIGHT_CYAN  "\033[106m"  // Fond cyan clair
# define BG_BRIGHT_WHITE "\033[107m"  // Fond blanc clair

/* Textes animés (fonctionnent dans certains terminaux, pas universel) */
# define BLINK        "\033[5m"   // Texte clignotant
# define INVISIBLE    "\033[8m"   // Texte invisible

/* Définition des couleurs version RGBA */
# define OX_BLACK       0x00000000  // Couleur noire
# define OX_RED         0x00FF0000  // Couleur rouge
# define OX_GREEN       0x0000FF00  // Couleur verte
# define OX_YELLOW      0x00FFFF00  // Couleur jaune
# define OX_BLUE        0x000000FF  // Couleur bleue
# define OX_MAGENTA     0x00FF00FF  // Couleur magenta
# define OX_CYAN        0x0000FFFF  // Couleur cyan
# define OX_WHITE       0x00FFFFFF  // Couleur blanche
# define OX_GRAY        0x00808080  // Couleur grise
# define OX_ORANGE      0x00FFA500  // Couleur orange
# define OX_PINK        0x00FFC0CB  // Couleur rose
# define OX_VIOLET      0x00800080  // Couleur violette
# define OX_TURQUOISE   0x00E0D0D0  // Couleur turquoise
# define OX_BEIGE       0x00F5DCBE  // Couleur beige
# define OX_BROWN       0x002A2A2A  // Couleur marron
# define OX_OLIVE       0x00808000  // Couleur olive
# define OX_LIME        0x0000FF00  // Couleur lime
# define OX_INDIGO      0x00820082  // Couleur indigo
# define OX_PEACH       0x00DAB9D2  // Couleur pêche
# define OX_LIGHT_BLUE  0x00D8E6FF  // Couleur bleu clair
# define OX_NAVY_BLUE   0x00008080  // Couleur bleu marine
# define OX_FOREST_GREEN 0x0028B22F // Couleur vert forêt
# define OX_GOLD        0x00D70000  // Couleur dorée
# define OX_CHARTREUSE  0x0000FF00  // Couleur chartreuse
# define OX_CORAL       0x007F5042  // Couleur corail
# define OX_PEARL       0x00E68C8C  // Couleur perle


#endif