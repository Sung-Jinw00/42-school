/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 16:32:04 by locagnio          #+#    #+#             */
/*   Updated: 2025/04/09 20:41:28 by locagnio         ###   ########.fr       */
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
		usleep(1000);
	return (1);
}

int	error_msg(char *s, t_rules *rules, t_philo *p)
{
	end_thread(rules, p);
	return (ft_fprintf(2, "%s", s));
}

void	print_routine(t_philo *p, char *action)
{
	pthread_mutex_lock(&p->rules->writing);
	if (p->rules->over || p->rules->dead)
	{
		pthread_mutex_unlock(&p->rules->writing);
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
	else
		printf(RED "%ld %d %s\n" RESET, time_now() - p->thread_start, p->id + 1,
			action);
	pthread_mutex_unlock(&p->rules->writing);
}

void	final_print(int alive, int max_iter, pthread_mutex_t *writing)
{
	pthread_mutex_lock(writing);
	if (alive)
	{
		if (max_iter)
			printf(BOLD GREEN "\n  All philosophers have eaten %d times !\n"
			RESET, max_iter);
		printf("\n       No one died today, noice.\n");
	}
	else
		printf("\n	¯\\_(ツ)_/¯\n\n");
	pthread_mutex_unlock(writing);
}
