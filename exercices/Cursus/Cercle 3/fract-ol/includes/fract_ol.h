/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 15:07:52 by locagnio          #+#    #+#             */
/*   Updated: 2025/01/09 19:06:11 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <limits.h>
# include <string.h>
# include <sys/wait.h>
# include "mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include "ft_printf.h"

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
	double	im;
	double	shift_x;
	double	shift_y;
	double	ratio;
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
	int			ac;
	char		**av;
}	t_mlx;

int				main(int ac, char **av);
int				quit(t_mlx *mlx);
int				deal_key(int key, t_mlx *mlx);
int				mandelbrot_equation(double x, double y);
int				deal_mouse(int button, int x, int y, t_mlx *mlx);
int				julia_equation(double x, double y, double c_re, double c_im);
unsigned int	rotate_hue(double iter);
void			help_message(void);
void			mlx_hooks(t_mlx *mlx);
void			draw_fractals(t_mlx *mlx);
void			set_mlx_datas(t_mlx *mlx);
void			arrow_controls(int key, t_mlx *mlx);
void			mouse_controls(int key, t_mlx *mlx);
void			error(char *error_message, t_mlx *mlx);
void			julia_presets(t_mlx *mlx, char preset_choice);
void			set_fractal_datas(t_mlx *mlx, int ac, char **av);
char			*set_args(char *arg, int arg_nb, t_mlx *mlx);

//libft
int			ft_strcmp_frctl(char *s1, char *s2);
void		*ft_calloc(size_t nmemb, size_t size);
void		ft_putstr_fd(char *s, int fd);
void		ft_bzero(void *s, size_t n);
double		ft_atod(char *nptr);
size_t		ft_strlen(const char *s);

//nom des fractales
# define MANDELBROT "Mandelbrot"
# define JULIA "Julia"
//presets Julia
# define PRESET "Preset"
# define J_PRESET_1
# define J_PRESET_2

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

# define PI 3.14159265358979323846

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
# define BRIGHT_RED    "\033[91m"  // Couleur rouge clairUM_LOCK 65407     // Touche Num Lock
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
# define OX_WHITE       0x00000000  // Couleur blanche
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