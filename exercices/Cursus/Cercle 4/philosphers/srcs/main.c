/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:58:02 by locagnio          #+#    #+#             */
/*   Updated: 2025/01/24 18:05:31 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	dead(t_philo *philo)
{
	pthread_mutex_lock(&(philo->writing));
	if (timestamp() - philo->last_burger >= philo->rules->life_expectancy)
	{
		pthread_mutex_unlock(&(philo->writing));
		return (1);
	}
	pthread_mutex_unlock(&(philo->writing));
	return (0);
}

int	eat(t_philo	*philo)
{
	if (philo->left_fork == philo->right_fork)
		return (events(timestamp() - philo->last_burger, philo, "died"), 1);
	pthread_mutex_lock(&(philo->rules->forks[philo->left_fork]));
	if (events(timestamp() - philo->birth_time, philo, "has taken a fork"))
		return (1);
	pthread_mutex_lock(&(philo->rules->forks[philo->right_fork]));
	if (events(timestamp() - philo->birth_time, philo, "has taken a fork")
		|| events(timestamp() - philo->birth_time, philo, "is eating"))
		return (1);
	philo->last_burger = timestamp();
	smart_sleep(philo->rules->burger_time, philo);
	pthread_mutex_unlock(&(philo->rules->forks[philo->left_fork]));
	pthread_mutex_unlock(&(philo->rules->forks[philo->right_fork]));
	return (0);
}


void	*survival(void *arg)
{
	t_philo philo;

	philo = *(t_philo *)arg;
	philo.birth_time = timestamp();
	philo.last_burger = philo.birth_time;
	if (philo.name % 2)
		smart_sleep(philo.rules->burger_time, &philo);
	while (!dead(&philo))
	{
		if (eat(&philo)
			|| events(timestamp() - philo.birth_time, &philo, "is sleeping"))
			break ;
		smart_sleep(philo.rules->sleep_routine, &philo);
		if (events(timestamp() - philo.birth_time, &philo, "is thinking"))
			break ;
	}
	return (NULL);
}

int	main(int ac, char **av)
{
	t_philo	*philo;
 	int i;

	i = -1;
	philo = NULL;
	if (ac == 5)
	{
		philo = init(philo, av);
		if (philo == NULL)
			return (1);
		while (++i < philo->rules->demography)
			if (pthread_create(&(philo[i].id), NULL, survival, &philo[i]))
				return (ft_putstr_fd("Error : thread creation failed\n", 2), 1);
		kill_threads(philo);
		free_all(philo);
	}
	else
		help_message();
	return (0);
}

	/* struct timeval tv;
    gettimeofday(&tv, NULL);
    
    printf("Secondes : %ld\n", tv.tv_sec);
    printf("Microsecondes : %ld\n", tv.tv_usec); */