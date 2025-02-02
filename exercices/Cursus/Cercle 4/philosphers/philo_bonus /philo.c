/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 16:32:10 by locagnio          #+#    #+#             */
/*   Updated: 2025/02/02 19:52:22 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

static int	init_philo(t_rules *rules, t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < rules->demography)
	{
		philo[i].id = i;
		philo[i].dead = 0;
		philo[i].iter_num = 0;
		philo[i].thread_start = 0;
		philo[i].last_meal = 0;
		philo[i].rules = rules;
	}
	return (0);
}

static int	init_pipe(t_rules *rules, t_philo *philo)
{
	int i;
	pid_t pid;

	i = -1;
	rules->start = time_now();
	while (++i < rules->demography)
	{
		philo[i].thread_start = rules->start;
		philo[i].last_meal = rules->start;
		pid = fork();
		if (pid == 0)
		{
			thread_routine(&philo[i]);
			exit(0);
		}
		else if (pid == -1)
			return (perror("Failed to create philosopher process"), -1);
	}
	rules->ready = 1;
	for (i = 0; i < rules->demography; i++)
		wait(NULL);
	return (0);
}

int	philosophers(t_rules *rules)
{
	rules->philo = malloc(sizeof(t_philo) * rules->demography);
	if (!rules->philo || init_philo(rules, rules->philo))
		return (1);
	if (init_pipe(rules, rules->philo))
		return (1);
	end_thread(rules, rules->philo);
	return (0);
}
