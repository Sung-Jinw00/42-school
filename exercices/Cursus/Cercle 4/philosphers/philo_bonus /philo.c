/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 16:32:10 by locagnio          #+#    #+#             */
/*   Updated: 2025/02/14 20:24:01 by locagnio         ###   ########.fr       */
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
	int		i;
	pid_t	pid;

	i = -1;
	rules->start = time_now();
	while (++i < rules->demography)
	{
		philo[i].thread_start = rules->start;
		philo[i].last_meal = rules->start;
		pid = fork();
		if (pid == 0)
		{
			if (rules->demography > 1)
				sem_routine(&philo[i]);
			else
			{
				print_routine(philo, FORK);
				ft_usleep(philo->rules->t2die + 100, philo);
			}
		}
		else if (pid == -1)
			return (perror("Failed to create philosopher process"), -1);
	}
	return (0);
}

int	monitor_philosophers(t_rules *rules, int i)
{
	int	status;
	int	all_eat;

	all_eat = 0;
	while (i < rules->demography)
	{
		waitpid(-1, &status, 0);
		if (WIFEXITED(status))
		{
			if (WEXITSTATUS(status) == 0)
				all_eat++;
			else if (WEXITSTATUS(status) == 1)
				return (final_print(0), 1);
		}
		if (all_eat == rules->demography)
		{
			printf("						\n");
			printf(BOLD GREEN "  All philosophers have eaten %d times !\n"
				RESET, rules->max_iter);
			return (final_print(1), kill(0, SIGINT), 0);
		}
		i++;
	}
	return (0);
}

int	philosophers(t_rules *rules)
{
	rules->philo = malloc(sizeof(t_philo) * rules->demography);
	if (!rules->philo || init_philo(rules, rules->philo))
		return (1);
	if (init_pipe(rules, rules->philo))
		return (1);
	if (monitor_philosophers(rules, 0))
		kill(0, SIGINT);
	end_sem(rules, rules->philo);
	return (0);
}
