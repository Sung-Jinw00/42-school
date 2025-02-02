/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 16:32:04 by locagnio          #+#    #+#             */
/*   Updated: 2025/02/02 19:05:52 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

long int	time_now(void)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	return ((now.tv_sec * 1000) + (now.tv_usec / 1000));
}

int	ft_usleep(long int time)
{
	long int	start_time;

	start_time = time_now();
	while ((time_now() - start_time) < time)
		usleep(150);
	return (1);
}

int	error_msg(char *s, t_rules *rules, t_philo *philo, int malloc)
{
	sem_close(rules->death);
	sem_unlink("/death");
	sem_close(rules->fork);
	sem_unlink("/fork");
	if (malloc)
	{
		if (philo)
			free(philo);
	}
	return (ft_fprintf(2, "%s", s));
}

void	print_routine(t_philo *p, char *action)
{
	sem_wait(p->rules->death);
	if (p->rules->over)
	{
		sem_post(p->rules->death);
		return ;
	}
	if (!ft_strcmp_philo(action, FORK))
		printf(GREEN "%ld %d %s\n" RESET, time_now() - p->thread_start, p->id
			+ 1, action);
	else if (!ft_strcmp_philo(action, SLEEP))
		printf(BLUE "%ld %d %s\n" RESET, time_now() - p->thread_start, p->id
			+ 1, action);
	else if (!ft_strcmp_philo(action, THINK))
		printf(CYAN "%ld %d %s\n" RESET, time_now() - p->thread_start, p->id
			+ 1, action);
	else if (!ft_strcmp_philo(action, EAT))
		printf(YELLOW "%ld %d %s\n" RESET, time_now() - p->thread_start, p->id
			+ 1, action);
	sem_post(p->rules->death);
}

void	final_print(int alive)
{
	printf("						\n");
	if (alive)
		printf("       No one died today, noice.\n");
	else
		printf("	¯\\_(ツ)_/¯			\n");
	printf("						\n");
}
