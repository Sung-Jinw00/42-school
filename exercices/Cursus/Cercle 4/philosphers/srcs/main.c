/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 15:52:21 by locavnio          #+#    #+#             */
/*   Updated: 2025/02/01 13:36:15 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_strcmp_philo(char *s1, char *s2)
{
	size_t	i;

	if (!s1 || !s2)
		return (0);
	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
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
		return (error_msg("Error : mutex failed his birth\n", rules, 0));
	rules->writing = malloc(sizeof(pthread_mutex_t));
	if (!rules->writing)
		return (error_msg("Error : writing never exist\n", rules, 0));
	rules->fork = malloc(sizeof(pthread_mutex_t) * rules->demography);
	if (!rules->fork)
		return (error_msg("Error : The fork isn't forking\n", rules, 0));
	if (pthread_mutex_init(rules->death, NULL) == -1)
		return (error_msg("Error : Death is a concept\n", rules, 0));
	while (++i < rules->demography)
		if (pthread_mutex_init(&rules->fork[i], NULL) == -1)
			return (error_msg("Error : We lost a fork\n", rules, 0));
	return (0);
}

static int	init_params(t_rules *rules, char **av)
{
	int	mutex;

	mutex = -1;
	rules->demography = ft_atoi_philo(av[1]);
	rules->t2die = ft_atoi_philo(av[2]);
	rules->t2eat = ft_atoi_philo(av[3]);
	rules->t2sleep = ft_atoi_philo(av[4]);
	rules->max_iter = -1;
	rules->nb_of_meals = 0;
	rules->start = 0;
	rules->ready = 0;
	if (av[5])
	{
		rules->nb_of_meals = 1;
		rules->max_iter = ft_atoi_philo(av[5]);
	}
	rules->over = 0;
	if (rules->demography > 0)
		mutex = init_params_mutex(rules);
	return (mutex || rules->demography <= 0 || rules->t2die <= 0
		|| rules->t2eat <= 0 || rules->t2sleep <= 0 || rules->max_iter == 0);
}

int	main(int ac, char **av)
{
	t_rules	rules;

	if ((ac != 5 && ac != 6) || init_params(&rules, av))
		return (error_msg("Error : invalid arguments\n", &rules, 0));
	if (philosophers(&rules))
		return (1);
	return (0);
}
