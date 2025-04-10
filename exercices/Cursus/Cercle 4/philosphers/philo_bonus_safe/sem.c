/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sem.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 16:32:06 by locagnio          #+#    #+#             */
/*   Updated: 2025/04/10 19:45:04 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

static int	someone_died(t_philo *philo)
{
	sem_post(philo->rules->fork);
	sem_post(philo->rules->fork);
	sem_wait(philo->rules->death);
	printf(RED "%ld %d %s\n" RESET, time_now() - philo->thread_start, philo->id
		+ 1, DIE);
	return (1);
}

int	check_death(t_philo *philo)
{
	long int	now;

	now = time_now() - philo->last_meal;
	if (now >= philo->rules->t2die)
	{
		philo->dead = 1;
		return (someone_died(philo));
	}
	return (0);
}

void	ft_sleep_and_think(t_philo *philo)
{
	print_routine(philo, SLEEP);
	ft_usleep(philo->rules->t2sleep, philo);
	print_routine(philo, THINK);
}

void	ft_eat(t_philo *philo)
{
	sem_wait(philo->rules->fork);
	print_routine(philo, FORK);
	if (check_death(philo))
		(end_sem(philo->rules), exit(1));
	sem_wait(philo->rules->fork);
	print_routine(philo, FORK);
	if (check_death(philo))
		(end_sem(philo->rules), exit(1));
	philo->last_meal = time_now();
	print_routine(philo, EAT);
	ft_usleep(philo->rules->t2eat, philo);
	philo->iter_num++;
	sem_post(philo->rules->fork);
	sem_post(philo->rules->fork);
	if (philo->iter_num == philo->rules->max_iter)
		(end_sem(philo->rules), exit(0));
}

void	*sem_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id & 1)
		ft_usleep(philo->rules->t2eat, philo);
	while (1)
	{
		if (check_death(philo))
		(end_sem(philo->rules), exit(1));
		ft_eat(philo);
		ft_sleep_and_think(philo);
	}
	return (NULL);
}
