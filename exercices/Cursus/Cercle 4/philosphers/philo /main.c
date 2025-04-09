/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 15:52:21 by locavnio          #+#    #+#             */
/*   Updated: 2025/04/09 21:10:41 by locagnio         ###   ########.fr       */
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

	if (pthread_mutex_init(&rules->death, NULL) == -1)
		return (error_msg("Error : mutex : Death is a concept\n", rules, 0));
	if (pthread_mutex_init(&rules->writing, NULL) == -1)
		return (error_msg("Error : mutex : Writing doesn't exist\n", rules, 0));
	if (pthread_mutex_init(&rules->status, NULL) == -1)
		return (error_msg("Error : mutex : Status doesn't exist\n", rules, 0));
	rules->fork = malloc(sizeof(pthread_mutex_t) * rules->demography);
	if (!rules->fork || pthread_mutex_init(rules->fork, NULL) == -1)
		return (error_msg("Error : mutex : Fork isn't forking\n", rules, 0));
	i = -1;
	while (++i < rules->demography)
		if (pthread_mutex_init(&rules->fork[i], NULL) == -1)
			return (error_msg("Error : mutex : We lost a fork\n", rules, 0));
	return (0);
}

static int	init_params(t_rules *rules, char **av)
{
	int	mutex;

	rules->demography = ft_atoi_philo(av[1]);
	rules->t2die = ft_atoi_philo(av[2]);
	rules->t2eat = ft_atoi_philo(av[3]);
	rules->t2sleep = ft_atoi_philo(av[4]);
	rules->max_iter = -1;
	if (av[5])
	{
		rules->nb_of_meals = 1;
		rules->max_iter = ft_atoi_philo(av[5]);
	}
	mutex = -1;
	if (rules->demography > 0)
		mutex = init_params_mutex(rules);
	return (mutex || rules->demography <= 0 || rules->t2die <= 0
		|| rules->t2eat <= 0 || rules->t2sleep <= 0 || rules->max_iter == 0);
}

int	main(int ac, char **av)
{
	t_rules	rules;

	rules = (t_rules){0};
	if ((ac != 5 && ac != 6) || init_params(&rules, av))
		return (ft_fprintf(2, "Error : invalid arguments\n"));
	if (philosophers(&rules))
		return (1);
	return (0);
}
