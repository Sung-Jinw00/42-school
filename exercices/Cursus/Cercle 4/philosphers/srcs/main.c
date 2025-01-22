/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:58:02 by locagnio          #+#    #+#             */
/*   Updated: 2025/01/22 18:18:37 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	dead(t_orga *commu)
{
	t_philo *philo;

	philo = commu->philo;
	pthread_mutex_lock(&(philo->writing));
	if (philo[philo->name].last_burger != 0 && timestamp() - \
		philo[philo->name].last_burger > commu->life_expectancy)
	{
		pthread_mutex_unlock(&(philo->writing));
		return (events(timestamp() - \
		philo[philo->name].last_burger, philo->name + 1, "died", philo->writing), 1);
	}
	pthread_mutex_unlock(&(philo->writing));
	return (0);
}

void	eat(t_orga	*commu)
{
	t_philo *philo;

	philo = commu->philo;
	pthread_mutex_lock(&(commu->forks[philo->left_fork]));
	events(timestamp() - philo->last_burger, philo->name, "has taken a fork", philo->writing);
	pthread_mutex_lock(&(commu->forks[philo->right_fork]));
	events(timestamp() - philo->last_burger, philo->name, "has taken a fork", philo->writing);
	pthread_mutex_lock(&(philo->order_of_the_burger));
	events(timestamp() - philo->last_burger, philo->name, "is eating", philo->writing);
	usleep(commu->burger_time);
	philo->last_burger = timestamp();
	pthread_mutex_unlock(&(philo->order_of_the_burger));
	pthread_mutex_unlock(&(commu->forks[philo->left_fork]));
	pthread_mutex_unlock(&(commu->forks[philo->right_fork]));
}

void	*survival(void *arg)
{
	t_orga	*commu;
	t_philo *philo;

	commu = (t_orga *)arg;
	philo = commu->philo;
	if (philo->name % 2)
		usleep(15000);
	philo->last_burger = timestamp();
	while (!dead(commu))
	{
		eat(commu);
		events(timestamp() - philo->last_burger, philo->name, "is sleeping", philo->writing);
		usleep(commu->sleep_routine);
		events(timestamp() - philo->last_burger, philo->name, "is thinking", philo->writing);
	}
	return (NULL);
}

int	main(int ac, char **av)
{
	t_orga	commu;
 	int i;

	i = -1;
	if (ac == 5)
	{
		if (init(&commu, av))
			return (1);
		while (++i < commu.demography)
			if (pthread_create(&(commu.philo[i].id), NULL, survival, &commu))
				return (ft_putstr_fd("Error : thread creation failed\n", 2), 1);
		kill_threads(&commu, commu.philo);
		free_all(&commu);
	}
	else
		help_message();
	return (0);
}

	/* struct timeval tv;
    gettimeofday(&tv, NULL);
    
    printf("Secondes : %ld\n", tv.tv_sec);
    printf("Microsecondes : %ld\n", tv.tv_usec); */