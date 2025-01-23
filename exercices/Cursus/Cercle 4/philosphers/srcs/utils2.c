/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:15:55 by locagnio          #+#    #+#             */
/*   Updated: 2025/01/23 20:32:16 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	kill_threads(t_philo *philos)
{
	int i;

	i = -1;
	while (++i < philos->rules.demography)
		pthread_join(philos[i].id, NULL);
	i = -1;
	while (++i < philos->rules.demography)
		pthread_mutex_destroy(&(philos->rules.forks[i]));
	pthread_mutex_destroy(&(philos->writing));
	pthread_mutex_destroy(&(philos->order_of_the_burger));
}

int	init2(t_philo *philo)
{
	if (philo->rules.demography < 2 || philo->rules.life_expectancy <= 0
		|| philo->rules.burger_time <= 0 || philo->rules.sleep_routine <= 0
		|| ((philo->rules.burger_time + philo->rules.sleep_routine)
			 >= philo->rules.life_expectancy))
		return (ft_putstr_fd("Brother, I will die, change params\n", 2), 1);
	philo = malloc(sizeof(t_philo) * philo->rules.demography);
	philo->rules.forks = malloc(sizeof(pthread_mutex_t) * philo->rules.demography);
	if (!philo || !philo->rules.forks)
	{
		if (philo->rules.forks)
			free(philo->rules.forks);
		if (philo)
			free(philo);
		return(ft_putstr_fd("Malloc error\n", 2), 1);
	}
	return (0);
}

int	init(t_philo *philo, char **av)
{
	int	i;

	i = -1;
	philo->rules.demography = (int)ft_atold(av[1]);
	philo->rules.life_expectancy = ft_atold(av[2]);
	philo->rules.burger_time = ft_atold(av[3]);
	philo->rules.sleep_routine = ft_atold(av[4]);
	if (init2(philo))
		return (1);
	while (++i < philo->rules.demography)
	{
		if (pthread_mutex_init(&(philo->rules.forks[i]), NULL))
			return(free_all(philo),
				ft_putstr_fd("My fork isn't forking\n", 2), 1);
		philo[i].name = i;
		philo[i].left_fork = i;
		philo[i].right_fork = (i + 1) % philo->rules.demography;
		philo[i].last_burger = 0;
		philo[i].rules = philo->rules;
	}
	if (pthread_mutex_init(&(philo->writing), NULL)
		|| pthread_mutex_init(&(philo->order_of_the_burger), NULL))
			return(free_all(philo),
				ft_putstr_fd("My fork isn't forking\n", 2), 1);
	return (0);
}
