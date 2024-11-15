/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 16:56:47 by locagnio          #+#    #+#             */
/*   Updated: 2024/11/15 00:43:56 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	standard_conds(t_struct v, int i)
{
	if (v.str[i] == 'c' || v.str[i] == 's' || v.str[i] == 'p'
		|| v.str[i] == 'd' || v.str[i] == 'i' || v.str[i] == 'u'
		|| v.str[i] == 'x' || v.str[i] == 'X' || v.str[i] == '%')
		return (1);
	return (0);
}

int	bonus_conds(t_struct v, int i)
{
	if (v.str[i] == '-' || v.str[i] == '0' || v.str[i] == '.'
		|| v.str[i] == '#' || v.str[i] == ' ' || v.str[i] == '+')
		return (1);
	return (0);
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

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*tab;
	size_t	i;

	if (size != 0 && nmemb > (-1 / size))
		return (NULL);
	tab = (void *)malloc(nmemb * size);
	if (!tab)
		return (NULL);
	i = 0;
	while (i < nmemb * size)
	{
		*(char *)(tab + i) = 0;
		i++;
	}
	return (tab);
}
