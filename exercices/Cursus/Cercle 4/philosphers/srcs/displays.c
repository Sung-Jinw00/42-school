/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   displays.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 17:03:41 by locagnio          #+#    #+#             */
/*   Updated: 2025/01/22 18:17:19 by locagnio         ###   ########.fr       */
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

void	events(long long timelaps, int philosopher, char *action,\
pthread_mutex_t writing)
{
	pthread_mutex_lock(&writing);
	if (ft_strcmp(action, "has taken a fork"))
		printf(GREEN"%lld %d has taken a fork\n"RESET, timelaps, philosopher + 1);
	else if (ft_strcmp(action, "is eating"))
		printf(YELLOW"%lld %d is eating\n"RESET, timelaps, philosopher + 1);
	else if (ft_strcmp(action, "is sleeping"))
		printf(BLUE"%lld %d is sleeping\n"RESET, timelaps, philosopher + 1);
	else if (ft_strcmp(action, "is thinking"))
		printf(CYAN"%lld %d is thinking\n"RESET, timelaps, philosopher + 1);
	else if (ft_strcmp(action, "died"))
		printf(RED"%lld %d died\n"RESET, timelaps, philosopher + 1);
	pthread_mutex_unlock(&writing);
}
