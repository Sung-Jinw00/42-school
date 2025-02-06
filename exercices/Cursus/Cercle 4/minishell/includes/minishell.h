/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 18:03:29 by locagnio          #+#    #+#             */
/*   Updated: 2025/02/06 21:00:26 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "ft_fprintf.h"
# include <sys/stat.h>
# include <wait.h>

# define RESET		"\033[0m"   //Réinitialisation
# define RED		"\033[31m"   //Couleur rouge
# define GREEN       "\033[32m"  // Couleur verte
# define YELLOW      "\033[33m"  // Couleur jaune
# define BLUE        "\033[34m"  // Couleur bleue
# define MAGENTA     "\033[35m"  // Couleur magenta
# define CYAN        "\033[36m"  // Couleur cyan
# define BOLD		"\033[1m"  // Texte en gras
# define UNDERLINE	"\033[4m"  // Texte souligné
# define ITALIC      "\033[3m"  // Texte en italique

typedef struct s_env
{
	char	*data;
	struct s_env	*next;	
} t_env;

void	error(void);
void	welcome(void);
char	*ft_itoa(int n);
void	ft_env(t_env *env);
void	print_list(t_env *L);
void	free_dbl_tab(char **str);
char	*ft_strdup(const char *src);
void	ft_print_dlb_tabs(char **tab);
void	exec_cmd(char *line, t_env *env);
void	ft_putcstr_fd(char *s, int fd, char c);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

//buildins
void	pwd(t_env *env);

# endif