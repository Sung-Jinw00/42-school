/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 16:32:06 by locagnio          #+#    #+#             */
/*   Updated: 2025/04/09 21:57:34 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	lock_forks(pthread_mutex_t *first_fork, pthread_mutex_t *sec_fork,
t_philo *philo)
{
	pthread_mutex_lock(first_fork);
	print_routine(philo, FORK);
	pthread_mutex_lock(sec_fork);
	print_routine(philo, FORK);
}

int	check_death(t_philo *philo)
{
	long int	now;

	pthread_mutex_lock(&philo->rules->death);
	now = time_now() - philo->meal;
	if (now >= philo->rules->t2die)
	{
		pthread_mutex_unlock(&philo->rules->death);
		return (print_routine(philo, DIE), 1);
	}
	pthread_mutex_unlock(&philo->rules->death);
	return (0);
}

void	ft_sleep_and_think(t_philo *philo)
{
	pthread_mutex_lock(&philo->rules->status);
	if (philo->rules->demography == 1)
	{
		philo->rules->over = 1;
		pthread_mutex_unlock(&philo->rules->status);
		return ;
	}
	pthread_mutex_unlock(&philo->rules->status);
	print_routine(philo, SLEEP);
	ft_usleep(philo->rules->t2sleep);
	print_routine(philo, THINK);
}

void	ft_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->rules->status);
	if (philo->rules->demography == 1)
	{
		pthread_mutex_lock(philo->left_fork);
		print_routine(philo, FORK);
		ft_usleep(philo->rules->t2die);
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(&philo->rules->status);
		return ;
	}
	else if (philo->right_fork < philo->left_fork)
		lock_forks(philo->left_fork, philo->right_fork, philo);
	else
		lock_forks(philo->right_fork, philo->left_fork, philo);
	pthread_mutex_unlock(&philo->rules->status);
	philo->meal = time_now();
	print_routine(philo, EAT);
	ft_usleep(philo->rules->t2eat);
	pthread_mutex_lock(&philo->rules->writing);
	philo->iter_num++;
	pthread_mutex_unlock(&philo->rules->writing);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	*thread_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	pthread_mutex_lock(&philo->rules->status);
	while (!philo->rules->ready)
	{
		pthread_mutex_unlock(&philo->rules->status);
		pthread_mutex_lock(&philo->rules->status);
		continue ;
	}
	pthread_mutex_unlock(&philo->rules->status);
	if (philo->id & 1)
		ft_usleep(philo->rules->t2eat);
	pthread_mutex_lock(&philo->rules->status);
	while (!philo->rules->over && !philo->rules->dead)
	{
		pthread_mutex_unlock(&philo->rules->status);
		ft_eat(philo);
		ft_sleep_and_think(philo);
		pthread_mutex_lock(&philo->rules->status);
	}
	pthread_mutex_unlock(&philo->rules->status);
	return (NULL);
}
