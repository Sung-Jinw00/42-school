/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 16:18:33 by locagnio          #+#    #+#             */
/*   Updated: 2025/01/31 17:54:26 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fprintf.h"

t_struct	keep_prior_flag(char erased, char prior, t_struct v)
{
	int	j;
	int	save;

	j = 0;
	save = 0;
	while (v.flags[j])
	{
		if (v.flags[j] == erased || v.flags[j] == prior)
			save = j++;
		if (v.flags[j] == erased || v.flags[j] == prior)
		{
			if (v.flags[save] == erased)
				j = save;
			while (v.flags[j] != '\0')
			{
				v.flags[j] = v.flags[j + 1];
				j++;
			}
			break ;
		}
		j++;
	}
	return (v);
}

int	srch_flag(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

t_struct	erase_flag(char erased, t_struct v)
{
	int	j;

	j = 0;
	while (v.flags[j])
	{
		if (v.flags[j] == erased)
		{
			while (v.flags[j] != '\0')
			{
				v.flags[j] = v.flags[j + 1];
				j++;
			}
			break ;
		}
		j++;
	}
	return (v);
}

char	bonus_flag_finder(int i, t_struct v)
{
	if (v.str[i] == '-')
		return ('-');
	else if (v.str[i] == '0')
		return ('0');
	else if (v.str[i] == '.')
		return ('.');
	else if (v.str[i] == '#')
		return ('#');
	else if (v.str[i] == ' ')
		return (' ');
	else if (v.str[i] == '+')
		return ('+');
	else
		return (0);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -sign;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + nptr[i] - '0';
		i++;
	}
	return (result * sign);
}
