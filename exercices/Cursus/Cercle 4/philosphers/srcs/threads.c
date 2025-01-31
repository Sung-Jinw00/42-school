/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 16:32:06 by locagnio          #+#    #+#             */
/*   Updated: 2025/01/31 17:15:55 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	someone_died(t_philo *p)
{
	print_routine(p, DIE);
	p->rules->over = 1;
	p->dead = 1;
	pthread_mutex_unlock(p->left_fork);
	pthread_mutex_unlock(p->right_fork);
	return (1);
}

int	check_death(t_philo *p)
{
	long int	now;

	pthread_mutex_lock(p->rules->death);
	now = time_now() - p->meal;
	if (now >= p->rules->t2die)
	{
		pthread_mutex_unlock(p->rules->death);
		return (someone_died(p));
	}
	pthread_mutex_unlock(p->rules->death);
	return (0);
}

void	ft_sleep_and_think(t_philo *p)
{
	ft_usleep(p->rules->t2sleep);
	print_routine(p, SLEEP);
	print_routine(p, THINK);
}

void	ft_eat(t_philo *p)
{
	pthread_mutex_lock(p->left_fork);
	print_routine(p, FORK);
	pthread_mutex_lock(p->right_fork);
	print_routine(p, FORK);
	p->meal = time_now();
	ft_usleep(p->rules->t2eat);
	print_routine(p, EAT);
	p->iter_num++;
	pthread_mutex_unlock(p->left_fork);
	pthread_mutex_unlock(p->right_fork);
}

void	*thread_routine(void *job)
{
	t_philo	*p;

	p = (t_philo *)job;
	while (!p->rules->ready)
		continue ;
	if (p->id & 1)
		ft_usleep(p->rules->t2eat * 0.9 + 1);
	while (!p->rules->over)
	{
		ft_eat(p);
		ft_sleep_and_think(p);
	}
	return (NULL);
}