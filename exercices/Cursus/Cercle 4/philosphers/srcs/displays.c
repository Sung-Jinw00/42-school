/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   displays.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 17:03:41 by locagnio          #+#    #+#             */
/*   Updated: 2025/01/24 16:47:11 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	help_message(void)
{
	printf(" Hello there !\n\n "UNDERLINE"You should use the program like so");
	printf(" :"RESET BOLD"\n\t./philosophers \"number_of_philosophers\" \"");
	printf("time_to_die\" \"time_to_eat\" \"time_to_sleep\""RESET"\n\n ");
	printf("Please, try again !\n");
}

int	events(long long timelaps, t_philo *philo, char *action)
{
	pthread_mutex_lock(&philo->writing);
	if (!ft_strcmp(action, "has taken a fork") && philo->rules->deaths == 0)
		printf(GREEN"%lld %d has taken a fork\n"RESET, timelaps, philo->name + 1);
	else if (!ft_strcmp(action, "is eating") && philo->rules->deaths == 0)
		printf(YELLOW"%lld %d is eating\n"RESET, timelaps, philo->name + 1);
	else if (!ft_strcmp(action, "is sleeping") && philo->rules->deaths == 0)
		printf(BLUE"%lld %d is sleeping\n"RESET, timelaps, philo->name + 1);
	else if (!ft_strcmp(action, "is thinking") && philo->rules->deaths == 0)
		printf(CYAN"%lld %d is thinking\n"RESET, timelaps, philo->name + 1);
	else if (!ft_strcmp(action, "died") && philo->rules->deaths == 1)
	{
		printf(RED"%lld %d died\n"RESET, timelaps, philo->name + 1);
		pthread_mutex_unlock(&philo->writing);
		return (1);
	}
	pthread_mutex_unlock(&philo->writing);
	return (0);
}
