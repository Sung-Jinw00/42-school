/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 16:32:06 by locagnio          #+#    #+#             */
/*   Updated: 2025/04/06 22:01:55 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	someone_died(t_philo *philo)
{
	print_routine(philo, DIE);
	philo->rules->over = 1;
	philo->dead = 1;
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->rules->death);
	return (1);
}

int	check_death(t_philo *philo)
{
	long int	now;

	pthread_mutex_lock(philo->rules->death);
	now = time_now() - philo->meal;
	if (now >= philo->rules->t2die)
	{
		return (someone_died(philo));
	}
	pthread_mutex_unlock(philo->rules->death);
	return (0);
}

void	ft_sleep_and_think(t_philo *philo)
{
	print_routine(philo, SLEEP);
	ft_usleep(philo->rules->t2sleep);
	print_routine(philo, THINK);
}

void	ft_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	print_routine(philo, FORK);
	pthread_mutex_lock(philo->right_fork);
	print_routine(philo, FORK);
	philo->meal = time_now();
	print_routine(philo, EAT);
	ft_usleep(philo->rules->t2eat);
	philo->iter_num++;
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	*thread_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (!philo->rules->ready)
		continue ;
	if (philo->id & 1)
		ft_usleep(philo->rules->t2eat);
	while (!philo->rules->over)
	{
		ft_eat(philo);
		ft_sleep_and_think(philo);
	}
	return (NULL);
}
