/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 16:32:04 by locagnio          #+#    #+#             */
/*   Updated: 2025/01/31 17:08:37 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

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

int	error_msg(char *s, t_rules *rules, t_philo *p, int malloc)
{
	if (malloc)
	{
		if (rules->death)
			free(rules->death);
		if (rules->fork)
			free(rules->fork);
		if (p)
			free(p);
	}		
	return (printf("%s", s));
}

void	print_routine(t_philo *p, char *action)
{
	pthread_mutex_lock(p->rules->death);
	if (p->rules->over)
	{
		pthread_mutex_unlock(p->rules->death);
		return ;
	}
	if (!ft_strcmp(action, FORK))
		printf(GREEN"%ld %d %s\n"RESET, time_now() - p->thread_start, p->id + 1, action);
	else if (!ft_strcmp(action, SLEEP))
		printf(BLUE"%ld %d %s\n"RESET, time_now() - p->thread_start, p->id + 1, action);
	else if (!ft_strcmp(action, THINK))
		printf(CYAN"%ld %d %s\n"RESET, time_now() - p->thread_start, p->id + 1, action);
	else if (!ft_strcmp(action, EAT))
		printf(YELLOW"%ld %d %s\n"RESET, time_now() - p->thread_start, p->id + 1, action);
	else
		printf(RED"%ld %d %s\n"RESET, time_now() - p->thread_start, p->id + 1, action);
	pthread_mutex_unlock(p->rules->death);
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
