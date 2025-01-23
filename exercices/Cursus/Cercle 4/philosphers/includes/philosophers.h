/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:58:52 by locagnio          #+#    #+#             */
/*   Updated: 2025/01/23 20:32:30 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>

# define RESET		"\033[0m"   //Réinitialisation
# define RED		"\033[31m"   //Couleur rouge
# define GREEN       "\033[32m"  // Couleur verte
# define YELLOW      "\033[33m"  // Couleur jaune
# define BLUE        "\033[34m"  // Couleur bleue
# define MAGENTA     "\033[35m"  // Couleur magenta
# define CYAN        "\033[36m"  // Couleur cyan
# define BOLD		"\033[1m"  // Texte en gras
# define UNDERLINE	"\033[4m"  // Texte souligné

typedef struct s_rules
{
	int				demography;
	long long		burger_time;
	long long		sleep_routine;
	long long		life_expectancy;
	pthread_mutex_t	*forks;
} t_rules;

typedef struct s_philo
{
	int				name;
	int				left_fork;
	int				right_fork;
	int				dead;
	pthread_t		id;
	t_rules			rules;
	pthread_mutex_t	writing;
	pthread_mutex_t	order_of_the_burger;
	long long		last_burger;
	long long		birth_time;
} t_philo;

long long	timestamp(void);
void		help_message(void);
long long	ft_atold(char *nptr);
int			init2(t_philo *commu);
int			main(int ac, char **av);
void		free_all(t_philo	*commu);
void		ft_putstr_fd(char *s, int fd);
int			init(t_philo *commu, char **av);
int			ft_strcmp(const char *s1, const char *s2);
void		kill_threads(t_philo *philos);
void		events(long long timelaps, int philosopher, char *action,\
pthread_mutex_t writing);

#endif