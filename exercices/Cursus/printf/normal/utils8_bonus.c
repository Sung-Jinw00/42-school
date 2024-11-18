/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils7.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 22:07:00 by marvin            #+#    #+#             */
/*   Updated: 2024/11/17 22:07:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

/* int	len_if_x(t_struct v, int i, int len_val)
{
	if ((v.str[i] == 'X' || v.str[i] == 'x') && ft_strchr(v.flag_order, '#')
		&& *(char *)v.arg != '0')
		len_val += 2;
	return (len_val);
}

t_struct	parseur2(int *i, t_struct v)
{
	if (v.str[*i] >= '1' && v.str[*i] <= '9')
	{
		v.nb1 = ft_atoi((const char *)v.str + *i);
		while (v.str[*i] >= '0' && v.str[*i] <= '9')
			*i += 1;
	}
	if (v.str[*i] == '.')
	{
		v = fill_parser(bonus_flag_finder(*i++, v), v);
		v.nb2 = ft_atoi((const char *)v.str + *i);
		while (v.str[*i] >= '0' && v.str[*i] <= '9')
			*i += 1;
	}
	return (v);
} */
