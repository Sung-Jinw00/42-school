/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 16:32:01 by locagnio          #+#    #+#             */
/*   Updated: 2025/04/09 21:43:09 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*tab;
	size_t	i;

	i = 0;
	if (size != 0 && nmemb > (-1 / size))
		return (NULL);
	tab = (void *)malloc(nmemb * size);
	if (!tab)
		return (NULL);
	while (i < nmemb * size)
	{
		*(char *)(tab + i) = 0;
		i++;
	}
	return (tab);
}

static int	ft_isnumber(const char *s)
{
	int	i;

	i = 0;
	if (s[i] && (s[i] == '-' || s[i] == '+'))
		i++;
	while (s[i])
	{
		if (!(s[i] >= '0' && s[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

int	ft_atoi_philo(const char *str)
{
	int					i;
	unsigned long long	n;

	i = 0;
	n = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (!ft_isnumber(str))
		return (-1);
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			return (0);
	}
	while (str[i] >= '0' && str[i] <= '9')
		n = n * 10 + (str[i++] - '0');
	if (n > INT_MAX)
		return (0);
	return ((int)n);
}

void	destroy_n_free_mutex(pthread_mutex_t *mutex)
{
	if (mutex)
	{
		pthread_mutex_destroy(mutex);
		free(mutex);
	}
}

void	end_thread(t_rules *rules, t_philo *philo)
{
	int	i;

	i = -1;
	if (philo && rules)
	{
		while (++i < rules->demography)
			pthread_join(philo[i].life_tid, (void *)&philo[i]);
		free(philo);
	}
	if (rules)
	{
		destroy_n_free_mutex(rules->fork);
		pthread_mutex_destroy(&rules->death);
		pthread_mutex_destroy(&rules->status);
		pthread_mutex_destroy(&rules->writing);
	}
}
