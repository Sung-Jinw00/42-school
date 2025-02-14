/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 16:32:10 by locagnio          #+#    #+#             */
/*   Updated: 2025/02/14 20:24:50 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	check_meals(t_philo philo, int last)
{
	if (philo.rules->nb_of_meals && last == philo.rules->demography - 1
		&& philo.iter_num == philo.rules->max_iter)
		return (ft_usleep(300));
	return (0);
}

static void	check_thread(t_rules *rules, t_philo *philo)
{
	int	i;

	while (!rules->ready)
		continue ;
	while (!rules->over)
	{
		i = -1;
		while (++i < rules->demography)
			if (check_death(&philo[i]) || check_meals(philo[i], i))
				rules->over = 1;
	}
	if (rules->nb_of_meals && philo[rules->demography
			- 1].iter_num >= rules->max_iter)
	{
		ft_usleep(5 * rules->demography);
		printf("						\n");
		printf(BOLD GREEN "  All philosophers have eaten %d times !\n" RESET,
			rules->max_iter);
		return (final_print(1));
	}
	else
		return (final_print(0));
}

static int	init_thread(t_rules *rules, t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < rules->demography)
	{
		philo[i].right_fork = philo[(i + 1) % rules->demography].left_fork;
		if (pthread_create(&philo[i].life_tid, NULL, &thread_routine,
				&philo[i]) == -1)
			return (error_msg("Error : philo failed in being born\n", rules,
					philo, 1));
	}
	i = -1;
	rules->start = time_now();
	while (++i < rules->demography)
	{
		philo[i].thread_start = rules->start;
		philo[i].meal = rules->start;
	}
	rules->ready = 1;
	return (0);
}

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
		philo[i].meal = 0;
		philo[i].rules = rules;
		philo[i].left_fork = &rules->fork[i];
		philo[i].right_fork = 0;
	}
	return (0);
}

int	philosophers(t_rules *rules)
{
	t_philo	*philo;

	philo = malloc(sizeof(t_philo) * rules->demography);
	if (!philo || init_philo(rules, philo))
		return (1);
	if (init_thread(rules, philo))
		return (1);
	check_thread(rules, philo);
	end_thread(rules, philo);
	return (0);
}
