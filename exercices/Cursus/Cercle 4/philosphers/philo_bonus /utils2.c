/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 16:32:01 by locagnio          #+#    #+#             */
/*   Updated: 2025/04/10 19:31:37 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

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

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
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
			return (error_msg("atoi : error : negative value not allowed\n",
					0), 0);
	}
	while (str[i] >= '0' && str[i] <= '9')
		n = n * 10 + (str[i++] - '0');
	if (n > INT_MAX)
		return (error_msg("atoi : error : number bigger than int\n", 0), 0);
	return ((int)n);
}

void	end_sem(t_rules *rules)
{
	sem_close(rules->death);
	sem_unlink("/death");
	sem_close(rules->fork);
	sem_unlink("/fork");
}
