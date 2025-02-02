/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 16:32:10 by locagnio          #+#    #+#             */
/*   Updated: 2025/02/02 19:31:01 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

static int	init_philo(t_rules *rules, t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < rules->demography)
	{
		philo[i].id = i;
		philo[i].dead = 0;
		philo[i].iter_num = 0;
		philo[i].thread_start = 0;
		philo[i].last_meal = 0;
		philo[i].rules = rules;
	}
	return (0);
}

static int	check_meals(t_philo philo, int last)
{
	if (philo.rules->nb_of_meals
		&& last == philo.rules->demography - 1
		&& philo.iter_num == philo.rules->max_iter)
		return (ft_usleep(300));
	return (0);
}

static void	*check_thread(void *arg)
{
	int			i;
	t_rules		*rules;
	t_philo		*philo;

	rules = (t_rules *)arg;
	philo = (t_philo *)rules->philo;
	while (!rules->ready)
		continue ;
	while (!rules->over)
	{
		i = -1;
		while (++i < rules->demography)
			if (check_death(&philo[i]) || check_meals(philo[i], i))
				rules->over = 1;
	}
	if (rules->nb_of_meals && philo[rules->demography - 1].iter_num >= rules->max_iter)
	{
		ft_usleep(5 * rules->demography);
		printf("						\n");
		printf(GREEN"  All philosophers have eaten %d times\n"RESET, rules->max_iter);
		final_print(1);
		return (NULL);
	}
	final_print(0);
	return (NULL);
}

static int	init_thread(t_rules *rules, t_philo *philo)
{
	pthread_t	death_tid;
	int			i;

	i = -1;
	rules->start = time_now();
	if (pthread_create(&death_tid, NULL, &check_thread, rules) == -1)
		return (error_msg("Error\nFailed to create death thread\n", rules, philo, 2));
	while (++i < rules->demography)
	{
		philo[i].thread_start = rules->start;
		philo[i].last_meal = rules->start;
		if (pthread_create(&philo[i].life_tid, NULL,
				&thread_routine, &philo[i]) == -1)
			return (error_msg("Error\nFailed to create thread\n", rules, philo, 2));
	}
	rules->ready = 1;
	pthread_join(death_tid, NULL);
	return (0);
}

int	philosophers(t_rules *rules)
{
	rules->philo = malloc(sizeof(t_philo) * rules->demography);
	if (!rules->philo || init_philo(rules, rules->philo))
		return (EXIT_FAILURE);
	if (init_thread(rules, rules->philo))
		return (EXIT_FAILURE);
	end_thread(rules, rules->philo);
	return (0);
}
