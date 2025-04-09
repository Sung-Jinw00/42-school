/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 16:32:10 by locagnio          #+#    #+#             */
/*   Updated: 2025/04/09 21:42:51 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	check_meals(t_philo philo, int last)
{
	pthread_mutex_lock(&philo.rules->death);
	if (philo.rules->nb_of_meals && last == philo.rules->demography - 1
		&& philo.iter_num == philo.rules->max_iter)
		return (pthread_mutex_unlock(&philo.rules->death), ft_usleep(300));
	pthread_mutex_unlock(&philo.rules->death);
	return (0);
}

static void	check_thread(t_rules *rules, t_philo *philo)
{
	int	i;

	pthread_mutex_lock(&rules->status);
	while (!rules->ready)
		continue ;
	pthread_mutex_unlock(&rules->status);
	i = -1;
	while (++i < rules->demography)
	{
		pthread_mutex_lock(&rules->status);
		if (rules->dead != 1 && check_death(&philo[i]))
			rules->dead = 1;
		if ((rules->dead != 1 && check_death(&philo[i]))
			|| rules->dead == 1 || check_meals(philo[i], i))
		{
			rules->over = 1;
			pthread_mutex_unlock(&rules->status);
			break ;
		}
		pthread_mutex_unlock(&rules->status);
		if (i + 1 >= rules->demography)
			i = -1;
	}
	pthread_mutex_lock(&rules->status);
	if (rules->nb_of_meals && philo[rules->demography
			- 1].iter_num >= rules->max_iter)
	{
		//ft_usleep(5 * rules->demography);
		pthread_mutex_unlock(&rules->status);
		return (final_print(1, rules->max_iter, &rules->writing));
	}
	pthread_mutex_unlock(&rules->status);
	return (final_print(0, 0, &rules->writing));
}

static int	init_thread(t_rules *rules, t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < rules->demography)
	{
		philo[i].right_fork = philo[(i + 1) % rules->demography].left_fork;
		if (pthread_create(&philo[i].life_tid, NULL, &thread_routine,
				&philo[i]) == -1)
			return (error_msg("Error : philo failed in being born\n", rules,
					philo));
	}
	i = -1;
	rules->start = time_now();
	while (++i < rules->demography)
	{
		philo[i].thread_start = rules->start;
		philo[i].meal = rules->start;
	}
	pthread_mutex_lock(&rules->status);
	rules->ready = 1;
	pthread_mutex_unlock(&rules->status);
	return (0);
}

static int	init_philo(t_rules *rules, t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < rules->demography)
	{
		philo[i] = (t_philo){0};
		philo[i].id = i;
		philo[i].rules = rules;
		philo[i].left_fork = &rules->fork[i];
	}
	return (0);
}

int	philosophers(t_rules *rules)
{
	t_philo	*philo;

	philo = ft_calloc(sizeof(t_philo), rules->demography);
	if (!philo || init_philo(rules, philo))
		return (1);
	if (init_thread(rules, philo))
		return (1);
	check_thread(rules, philo);
	end_thread(rules, philo);
	return (0);
}
