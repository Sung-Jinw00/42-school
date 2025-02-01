/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 16:32:01 by locagnio          #+#    #+#             */
/*   Updated: 2025/02/01 13:17:44 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

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

static int	check_sign(char c)
{
	if (c == '-')
		return (-1);
	return (1);
}

static int	check_overflow(int sign)
{
	if (sign == 1)
		return (-1);
	return (0);
}

int	ft_atoi_philo(const char *str)
{
	int						i;
	int						sign;
	unsigned long long int	n;

	i = 0;
	n = 0;
	if (!ft_isnumber(str))
		return (-1);
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
		sign = check_sign(str[i++]);
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (n >= LONG_MAX)
		{
			n = check_overflow(sign);
			break ;
		}
		n = n * 10 + (str[i++] - '0');
	}
	if (sign < 0)
		return (0);
	return (sign * (int)n);
}

void	end_thread(t_rules *rules, t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < rules->demography)
		pthread_join(philo[i].life_tid, (void *)&philo[i]);
	pthread_mutex_destroy(rules->death);
	pthread_mutex_destroy(rules->fork);
	free(rules->death);
	free(rules->fork);
	free(philo);
}
