/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:58:02 by locagnio          #+#    #+#             */
/*   Updated: 2025/01/23 20:32:56 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"
/*
int	dead(t_philo *philo)
{
	t_philo *philo;

	philo = philo;
	pthread_mutex_lock(&(philo->writing));
	if (philo[philo[philo->name].name].last_burger != 0 && timestamp() - \
		philo[philo[philo->name].name].last_burger > philo->rules.life_expectancy)
	{
		pthread_mutex_unlock(&(philo->writing));
		return (events(timestamp() - \
		philo[philo[philo->name].name].last_burger, philo[philo->name].name + 1, "died", philo->writing), 1);
	}
	pthread_mutex_unlock(&(philo->writing));
	return (0);
}

void	eat(t_philo	*philo)
{
	t_philo *philo;

	philo = philo;
	pthread_mutex_lock(&(philo->forks[philo->left_fork]));
	events(timestamp() - philo->birth_time, philo[philo[philo->name].name].name, "has taken a fork", philo->writing);
	pthread_mutex_lock(&(philo->forks[philo->right_fork]));
	events(timestamp() - philo->birth_time, philo[philo->name].name, "has taken a fork", philo->writing);
	pthread_mutex_lock(&(philo->order_of_the_burger));
	events(timestamp() - philo->birth_time, philo[philo->name].name, "is eating", philo->writing);
	usleep(philo->rules.burger_time);
	philo->last_burger = timestamp();
	pthread_mutex_unlock(&(philo->order_of_the_burger));
	pthread_mutex_unlock(&(philo->forks[philo->left_fork]));
	pthread_mutex_unlock(&(philo->forks[philo->right_fork]));
}
*/

void	*survival(void *arg)
{
	t_philo *philo;

	philo = (t_philo *)arg;
	if (philo.name % 2)
		usleep(15000);
	philo->birth_time = timestamp();
	printf("Bigup de philo %i\n", philo->name);
	//exit(1);
/*	while (!dead(philo))
	{
		eat(philo);
		events(timestamp() - philo->birth_time, philo[philo->name].name, "is sleeping", philo->writing);
		usleep(philo->rules.sleep_routine);
		events(timestamp() - philo->birth_time, philo[philo->name].name, "is thinking", philo->writing);
	}
	*/
	return (NULL);
}

int	main(int ac, char **av)
{
	t_philo	*philo;
 	int i;

	i = -1;
	if (ac == 5)
	{
		if (init(philo, av))
			return (1);
		while (++i < philo->rules.demography)
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