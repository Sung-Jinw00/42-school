/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 16:32:06 by locagnio          #+#    #+#             */
/*   Updated: 2025/04/15 15:47:42 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	someone_died(t_philo *philo)
{
	print_routine(philo, DIE);
	pthread_mutex_lock(&philo->rules->rules);
	philo->rules->over = 1;
	pthread_mutex_unlock(&philo->rules->rules);
	return (1);
}

int	check_death(t_philo *philo)
{
	long int	now;

	now = time_now() - philo->meal;
	if (now >= philo->rules->t2die + 5)
		return (someone_died(philo));
	return (0);
}

void	ft_sleep_and_think(t_philo *philo)
{
	print_routine(philo, SLEEP);
	ft_usleep(philo->rules->t2sleep + philo->id);
	print_routine(philo, THINK);
}

void	ft_eat(t_philo *philo)
{
	if (philo->left_fork < philo->right_fork)
	{
		pthread_mutex_lock(philo->left_fork);
		pthread_mutex_lock(philo->right_fork);
	}
	else
	{
		pthread_mutex_lock(philo->right_fork);
		pthread_mutex_lock(philo->left_fork);
	}
	print_routine(philo, FORK);
	print_routine(philo, FORK);
	print_routine(philo, EAT);
	pthread_mutex_lock(&philo->rules->meal);
	philo->meal = time_now();
	pthread_mutex_unlock(&philo->rules->meal);
	ft_usleep(philo->rules->t2eat);
	pthread_mutex_lock(&philo->rules->iter);
	philo->iter_num++;
	pthread_mutex_unlock(&philo->rules->iter);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	*thread_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->rules->demography == 1)
	{
		print_routine(philo, FORK);
		return (ft_usleep(philo->rules->t2die), NULL);
	}
	print_routine(philo, THINK);
	if (philo->id & 1)
		ft_usleep(philo->rules->t2eat);
	pthread_mutex_lock(&philo->rules->rules);
	while (!philo->rules->over)
	{
		pthread_mutex_unlock(&philo->rules->rules);
		ft_eat(philo);
		ft_sleep_and_think(philo);
		pthread_mutex_lock(&philo->rules->rules);
	}
	pthread_mutex_unlock(&philo->rules->rules);
	return (NULL);
}
