/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 15:52:21 by locavnio          #+#    #+#             */
/*   Updated: 2025/04/10 17:05:01 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

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

static int	init_rules_semaphore(t_rules *rules)
{
	sem_unlink("/death");
	sem_unlink("/fork");
	rules->death = sem_open("/death", O_CREAT, 0660, 1);
	if (rules->death == SEM_FAILED)
		return (error_msg("Error\nDeath semaphore init failed\n", rules, 0, 1));
	rules->fork = sem_open("/fork", O_CREAT, 0660, rules->demography);
	if (rules->fork == SEM_FAILED)
		return (error_msg("Error\nFork semaphore init failed\n", rules, 0, 1));
	return (0);
}

static int	init_rules(t_rules *rules, char **ag)
{
	int	sem;

	rules->demography = ft_atoi(ag[1]);
	rules->t2die = ft_atoi(ag[2]);
	rules->t2eat = ft_atoi(ag[3]);
	rules->t2sleep = ft_atoi(ag[4]);
	rules->max_iter = -1;
	if (ag[5])
	{
		rules->nb_of_meals = 1;
		rules->max_iter = ft_atoi(ag[5]);
	}
	sem = -1;
	if (rules->demography > 0)
		sem = init_rules_semaphore(rules);
	return (sem || rules->demography <= 0 || rules->t2die <= 0
		|| rules->t2eat <= 0 || rules->t2sleep <= 0 || rules->max_iter == 0);
}

int	main(int ac, char **ag)
{
	t_rules	rules;

	rules = (t_rules){0};
	if ((ac != 5 && ac != 6) || init_rules(&rules, ag))
		return (error_msg("Error: invalid arguments\n", &rules, 0, 1));
	if (philosophers(&rules))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
