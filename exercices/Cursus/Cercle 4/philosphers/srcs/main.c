/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 15:52:21 by locavnio          #+#    #+#             */
/*   Updated: 2025/01/31 17:26:08 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	init_philo(t_rules *rules, t_philo *philo)
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

static int	init_params_mutex(t_rules *rules)
{
	int	i;

	i = -1;
	rules->death = 0;
	rules->fork = 0;
	rules->death = malloc(sizeof(pthread_mutex_t));
	if (!rules->death)
		return (error_msg("Error\nMutex death: malloc failed\n", rules, 0, 1));
	rules->fork = malloc(sizeof(pthread_mutex_t) * rules->demography);
	if (!rules->fork)
		return (error_msg("Error\nMutex fork: malloc failed\n", rules, 0, 1));
	if (pthread_mutex_init(rules->death, NULL) == -1)
		return (error_msg("Error\nMutex init failed\n", rules, 0, 1));
	while (++i < rules->demography)
		if (pthread_mutex_init(&rules->fork[i], NULL) == -1)
			return (error_msg("Error\nMutex init failed\n", rules, 0, 1));
	return (0);
}

static int	init_params(t_rules *rules, char **av)
{
	int	mutex;

	mutex = -1;
	rules->demography = ft_atoi(av[1]);
	rules->t2die = ft_atoi(av[2]);
	rules->t2eat = ft_atoi(av[3]);
	rules->t2sleep = ft_atoi(av[4]);
	rules->max_iter = -1;
	rules->nb_of_meals = 0;
	rules->start = 0;
	rules->ready = 0;
	if (av[5])
	{
		rules->nb_of_meals = 1;
		rules->max_iter = ft_atoi(av[5]);
	}
	rules->over = 0;
	if (rules->demography > 0)
		mutex = init_params_mutex(rules);
	return (mutex || rules->demography <= 0 || rules->t2die <= 0 || rules->t2eat <= 0
		|| rules->t2sleep <= 0 || rules->max_iter == 0);
}

int	main(int ac, char **av)
{
	t_rules	p;

	if ((ac != 5 && ac != 6) || init_params(&p, av))
		return (error_msg("Error: invalid arguments\n", &p, 0, 1));
	if (philosophers(&p))
		return (1);
	return (0);
}