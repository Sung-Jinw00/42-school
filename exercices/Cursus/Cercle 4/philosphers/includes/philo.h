/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:58:52 by locagnio          #+#    #+#             */
/*   Updated: 2025/01/31 17:17:33 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>
# include <limits.h>

# define RESET		"\033[0m"   //Réinitialisation
# define RED		"\033[31m"   //Couleur rouge
# define GREEN       "\033[32m"  // Couleur verte
# define YELLOW      "\033[33m"  // Couleur jaune
# define BLUE        "\033[34m"  // Couleur bleue
# define MAGENTA     "\033[35m"  // Couleur magenta
# define CYAN        "\033[36m"  // Couleur cyan
# define BOLD		"\033[1m"  // Texte en gras
# define UNDERLINE	"\033[4m"  // Texte souligné

# define FORK "has taken a fork"
# define EAT "is eating"
# define SLEEP "is sleeping"
# define THINK "is thinking"
# define DIE "died"
# define LEFT 0
# define RIGHT 1

typedef struct s_rules
{
	int				demography;
	int				ready;
	int				t2die;
	int				t2eat;
	int				t2sleep;
	int				max_iter;
	int				nb_of_meals;
	int				over;
	long int		start;
	pthread_mutex_t	*death;
	pthread_mutex_t	*fork;
}	t_rules;

typedef struct s_philo
{
	int				id;
	int				dead;
	int				iter_num;
	long int		thread_start;
	long int		meal;
	pthread_t		life_tid;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	t_rules		*rules;
}	t_philo;

long int	time_now(void);
void		final_print(int alive);
int			main(int ac, char **ag);
int			check_death(t_philo *p);
int			ft_atoi(const char *str);
int			ft_usleep(long int time);
void		*thread_routine(void *job);
int			philosophers(t_rules *params);
int			init_philo(t_rules *p, t_philo *philo);
void		print_routine(t_philo *p, char *action);
int			ft_strcmp(const char *s1, const char *s2);
int			error_msg(char *s, t_rules *par, t_philo *p, int malloc);

#endif