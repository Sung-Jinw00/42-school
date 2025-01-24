/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:15:55 by locagnio          #+#    #+#             */
/*   Updated: 2025/01/24 18:10:22 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	smart_sleep(double time_to_sleep, t_philo *philo)
{
	int	i;

	i = 0;
	while (++i <= time_to_sleep)
	{
		if (timestamp() - philo->last_burger >= philo->rules->life_expectancy)
		{
			pthread_mutex_lock(&(philo->funerals));
			philo->rules->deaths++;
			events(timestamp() - philo->last_burger, philo, "died");
			pthread_mutex_unlock(&(philo->funerals));
			break ;
		}
		usleep(1000);
	}
}

void	kill_threads(t_philo *philos)
{
	int i;

	i = -1;
	while (++i < philos->rule.demography)
		pthread_join(philos[i].id, NULL);
	i = -1;
	while (++i < philos->rule.demography)
		pthread_mutex_destroy(&(philos->rule.forks[i]));
	pthread_mutex_destroy(&(philos->writing));
	pthread_mutex_destroy(&(philos->order_of_the_burger));
}

t_philo	*init2(t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < philo->rule.demography)
	{
		if (pthread_mutex_init(&(philo->rule.forks[i]), NULL))
			return(free_all(philo),
				ft_putstr_fd("My fork isn't forking\n", 2), NULL);
		philo[i].name = i;
		philo[i].left_fork = i;
		philo[i].right_fork = (i + 1) % philo->rule.demography;
		philo[i].last_burger = 0;
		philo[i].rules = &philo->rule;
	}
	return (philo);
}

t_philo	*init(t_philo *philo, char **av)
{
	philo = malloc(sizeof(t_philo) * ft_atold(av[1]));
	philo->rule.forks = malloc(sizeof(pthread_mutex_t) * ft_atold(av[1]));
	if (!philo || !philo->rule.forks)
	{
		if (philo->rule.forks)
			free(philo->rule.forks);
		if (philo)
			free(philo);
		return(ft_putstr_fd("Malloc error\n", 2), NULL);
	}
	philo->rule.demography = (int)ft_atold(av[1]);
	philo->rule.life_expectancy = ft_atold(av[2]);
	philo->rule.burger_time = ft_atold(av[3]);
	philo->rule.sleep_routine = ft_atold(av[4]);
	philo->rule.deaths = 0;
	philo = init2(philo);
	if (philo == NULL)
		return (NULL);
	if (pthread_mutex_init(&(philo->writing), NULL)
		|| pthread_mutex_init(&(philo->funerals), NULL))
			return(kill_threads(philo), free_all(philo),
				ft_putstr_fd("My fork isn't forking\n", 2), NULL);
	return (philo);
}
