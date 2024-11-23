/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 22:22:27 by locagnio          #+#    #+#             */
/*   Updated: 2024/11/23 16:54:46 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_struct	flags(char c, t_struct v)
{
	int	i;

	i = 0;
	if (!c)
		return (v);
	while (i < 6)
	{
		if (c == v.flags[i])
			break ;
		else if (v.flags[i] == 0)
		{
			v.flags[i] = c;
			break ;
		}
		i++;
	}
	return (v);
}

t_struct	flag_filter(int i, t_struct v)
{
	int j;

	j = 0;
	if (v.str[i] == '%')
		while (v.flags[j] != 0)
			v.flags[j++] = 0;
	v = keep_prior_flag('0', '-', v);
	v = keep_prior_flag(' ', '+', v);
	if (srch_flag(v.flags, '0') && (v.str[i] == 'c' || v.str[i] == 's'))
		v = erase_flag('0', v);
	if (srch_flag(v.flags, '+') && !(v.str[i] == 'i' || v.str[i] == 'd'
		|| v.str[i] == 'p'))
		v = erase_flag('+', v);
	if (srch_flag(v.flags, ' ') && !(v.str[i] == 'i' || v.str[i] == 'd'
		|| v.str[i] == 'p'))
		v = erase_flag(' ', v);
	if (srch_flag(v.flags, '.') && v.str[i] == 'c')
		v = erase_flag('.', v);
	if (srch_flag(v.flags, '#') && !(v.str[i] == 'x' || v.str[i] == 'X'))
		v = erase_flag('#', v);
	return (v);
}

t_struct	parse_nd_flags2(int *i, t_struct v)
{
	if (v.str[*i] >= '1' && v.str[*i] <= '9')
	{
		v.nb1 = ft_atoi((const char *)v.str + *i);
		while (v.str[*i] >= '0' && v.str[*i] <= '9')
			*i += 1;
	}
	if (v.str[*i] == '.')
	{
		v = flags(bonus_flag_finder(*i, v), v);
		*i += 1;
		v.nb2 = ft_atoi((const char *)v.str + *i);
		while (v.str[*i] >= '0' && v.str[*i] <= '9')
			*i += 1;
	}
	return (v);
}

int	standard_conds(t_struct v, int i)
{
	if (v.str[i] == 'c' || v.str[i] == 's' || v.str[i] == 'p'
		|| v.str[i] == 'd' || v.str[i] == 'i' || v.str[i] == 'u'
		|| v.str[i] == 'x' || v.str[i] == 'X' || v.str[i] == '%')
		return (1);
	return (0);
}
