/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 16:32:06 by locagnio          #+#    #+#             */
/*   Updated: 2025/02/02 19:33:43 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

static int	someone_died(t_philo *philo)
{
	sem_post(philo->rules->fork);
	sem_post(philo->rules->fork);
	sem_wait(philo->rules->death);
	printf(RED"%ld %d %s\n"RESET, time_now() - philo->thread_start,
		philo->id + 1, DIE);
	sem_post(philo->rules->death);
	return (1);
}

int	check_death(t_philo *philo)
{
	long int	now;

	sem_wait(philo->rules->death);
	now = time_now() - philo->last_meal;
	if (now >= philo->rules->t2die)
	{
		philo->rules->over = 1;
		philo->dead = 1;
		sem_post(philo->rules->death);
		return (someone_died(philo));
	}
	sem_post(philo->rules->death);
	return (0);
}

void	ft_sleep_and_think(t_philo *philo)
{
	ft_usleep(philo->rules->t2sleep);
	print_routine(philo, SLEEP);
	print_routine(philo, THINK);
}

void	ft_eat(t_philo *philo)
{
	sem_wait(philo->rules->fork);
	print_routine(philo, FORK);
	sem_wait(philo->rules->fork);
	print_routine(philo, FORK);
	philo->last_meal = time_now();
	print_routine(philo, EAT);
	ft_usleep(philo->rules->t2eat);
	philo->iter_num++;
	sem_post(philo->rules->fork);
	sem_post(philo->rules->fork);
}

void	*thread_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (!philo->rules->ready)
		continue ;
	if (philo->id & 1)
		ft_usleep(philo->rules->t2eat * 0.9 + 1);
	while (!philo->rules->over)
	{
		ft_eat(philo);
		ft_sleep_and_think(philo);
	}
	return (NULL);
}
