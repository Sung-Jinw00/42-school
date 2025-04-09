/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 16:32:10 by locagnio          #+#    #+#             */
/*   Updated: 2025/04/10 00:51:26 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	check_meals(t_philo philo, int last)
{
	if (philo.rules->nb_of_meals && last == philo.rules->demography - 1
		&& philo.iter_num == philo.rules->max_iter)
			return (1);
	return (0);
}

static void	check_thread(t_rules *rules, t_philo *philo)
{
	int	i;

	while (1)
	{
		i = -1;
		while (++i < rules->demography)
		{
			pthread_mutex_lock(&philo->rules->iter);
			pthread_mutex_lock(&philo->rules->meal);
			if (check_death(&philo[i]) || check_meals(philo[i], i))
			{
				pthread_mutex_lock(&philo->rules->rules);
				rules->over = 1;
				pthread_mutex_unlock(&philo->rules->rules);
			}
			pthread_mutex_unlock(&philo->rules->iter);
			pthread_mutex_unlock(&philo->rules->meal);
		}
		pthread_mutex_lock(&philo->rules->rules);
		if (rules->over)
			break ;
		pthread_mutex_unlock(&philo->rules->rules);
	}
	final_print(philo, rules);
}

static int	init_thread(t_rules *rules, t_philo *philo)
{
	int	i;

	i = -1;
	rules->start = time_now();
	while (++i < rules->demography)
	{
		philo[i].thread_start = rules->start;
		philo[i].meal = rules->start;
	}
	i = -1;
	while (++i < rules->demography)
	{
		philo[i].right_fork = philo[(i + 1) % rules->demography].left_fork;
		if (pthread_create(&philo[i].life_tid, NULL, &thread_routine,
				&philo[i]) == -1)
			return (error_msg("Error : philo failed in being born\n", rules,
					philo, 1));
	}
	rules->ready = 1;
	return (0);
}

static int	init_philo(t_rules *rules, t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < rules->demography)
	{
		philo[i].id = i;
		//philo[i].dead = 0;
		philo[i].iter_num = 0;
		philo[i].thread_start = 0;
		philo[i].meal = 0;
		philo[i].rules = rules;
		philo[i].left_fork = &rules->fork[i];
		philo[i].right_fork = 0;
	}
	return (0);
}

int	philosophers(t_rules *rules)
{
	t_philo	*philo;

	philo = malloc(sizeof(t_philo) * rules->demography);
	if (!philo || init_philo(rules, philo))
		return (1);
	if (init_thread(rules, philo))
		return (1);
	check_thread(rules, philo);
	end_thread(rules, philo);
	return (0);
}

