/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 16:32:04 by locagnio          #+#    #+#             */
/*   Updated: 2025/04/10 19:30:08 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

long int	time_now(void)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	return ((now.tv_sec * 1000) + (now.tv_usec / 1000));
}

int	ft_usleep(long int time, t_philo *philo)
{
	long	start_time;

	start_time = time_now();
	while ((time_now() - start_time) < time)
	{
		if (check_death(philo))
			(end_sem(philo->rules), exit(1));
		usleep(150);
	}
	return (1);
}

int	error_msg(char *s, t_rules *rules)
{
	end_sem(rules);
	return (write(2, s, ft_strlen(s)));
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
}
