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
int			main(int ac, char **av, char **envp);
void		error(void);
void		execute(char *argv, char **envp);
int			ft_strnchr(const char *s, const char *to_find, int len);

////////////////////////////////// [pipex] ////////////////////////////////////
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

#endif