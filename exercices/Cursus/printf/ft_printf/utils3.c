/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 16:56:47 by locagnio          #+#    #+#             */
/*   Updated: 2024/11/20 19:36:57 by locagnio         ###   ########.fr       */
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
		|| v.str[i] == '#' || v.str[i] == ' ' || v.str[i] == '+'
		|| (v.str[i] >= '0' && v.str[i] <= '9'))
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

int	ft_len_field(int i, t_struct v)
{
	int	len_val;

	len_val = 0;
	if (v.str[i] == 'd' || v.str[i] == 'i' || v.str[i] == 'u')
	{
		if (!(ft_strchr(v.flag_order, '.') && v.nb2 == 0
				&& *(long long *)v.arg == 0))
			len_val = ft_digits(*(long long *)v.arg);
		len_val = len_field_nb2(v, len_val, i);
	}
	else
		len_val = assign_if_non_nb(v, i);
	len_val = len_if_x(v, i, len_val);
	if (v.nb1 > len_val)
	{
		len_val = v.nb1;
		return (len_val);
	}
	else if (v.nb1 <= len_val && ft_strchr(v.flag_order, ' '))
		v = erase_flag(' ', v);
	return (len_val);
}
