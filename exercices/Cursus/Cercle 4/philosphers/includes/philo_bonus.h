/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:58:52 by locagnio          #+#    #+#             */
/*   Updated: 2025/04/10 19:30:45 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <sys/time.h>
# include <sys/stat.h>
# include <pthread.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <limits.h>
# include <signal.h>
# include <semaphore.h>

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

typedef struct s_rules t_rules;

typedef struct s_philo
{
	int				id;
	int				dead;
	int				iter_num;
	long int		thread_start;
	long int		last_meal;
	pthread_t		life_tid;
	t_rules			*rules;
}	t_philo;

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
	sem_t			*death;
	sem_t			*fork;
	t_philo			philo[200];
}	t_rules;

long int	time_now(void);
int			ft_strlen(char *s);
void		final_print(int alive);
int			main(int ac, char **ag);
int			check_death(t_philo *p);
void		*sem_routine(void *job);
void		end_sem(t_rules *rules);
int			philosophers(t_rules *rules);
int			ft_atoi_philo(const char *str);
int			error_msg(char *s, t_rules *rules);
int			ft_strcmp_philo(char *s1, char *s2);
void		print_routine(t_philo *p, char *action);
int			ft_usleep(long int time, t_philo *philo);

#endif