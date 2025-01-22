/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:15:55 by locagnio          #+#    #+#             */
/*   Updated: 2025/01/22 18:14:23 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	kill_threads(t_orga *commu, t_philo *philos)
{
	int i;

	i = -1;
	while (++i < commu->demography)
		pthread_join(philos[i].id, NULL);
	i = -1;
	while (++i < commu->demography)
		pthread_mutex_destroy(&(commu->forks[i]));
	pthread_mutex_destroy(&(philos->writing));
	pthread_mutex_destroy(&(philos->order_of_the_burger));
}

int	init2(t_orga *commu)
{
	if (commu->demography < 2 || commu->life_expectancy <= 0
		|| commu->burger_time <= 0 || commu->sleep_routine <= 0
		|| ((commu->burger_time + commu->sleep_routine)
			 >= commu->life_expectancy))
		return (ft_putstr_fd("Brother, I will die, change params\n", 2), 1);
	commu->forks = malloc(sizeof(pthread_mutex_t) * commu->demography);
	commu->philo = malloc(sizeof(t_philo) * commu->demography);
	if (!commu->forks || !commu->philo)
	{
		if (commu->forks)
			free(commu->forks);
		if (commu->philo)
			free(commu->philo);
		return(ft_putstr_fd("Malloc error\n", 2), 1);
	}
	return (0);
}

int	init(t_orga *commu, char **av)
{
	int	i;

	i = -1;
	commu->demography = (int)ft_atold(av[1]);
	commu->life_expectancy = ft_atold(av[2]);
	commu->burger_time = ft_atold(av[3]);
	commu->sleep_routine = ft_atold(av[4]);
	if (init2(commu))
		return (1);
	while (++i < commu->demography)
	{
		if (pthread_mutex_init(&(commu->forks[i]), NULL))
			return(free_all(commu),
				ft_putstr_fd("My fork isn't forking\n", 2), 1);
		commu->philo[i].name = i;
		commu->philo[i].left_fork = i;
		commu->philo[i].right_fork = (i + 1) % commu->demography;
		commu->philo[i].last_burger = 0;
	}
	if (pthread_mutex_init(&(commu->philo->writing), NULL)
		|| pthread_mutex_init(&(commu->philo->order_of_the_burger), NULL))
			return(free_all(commu),
				ft_putstr_fd("My fork isn't forking\n", 2), 1);
	return (0);
}
