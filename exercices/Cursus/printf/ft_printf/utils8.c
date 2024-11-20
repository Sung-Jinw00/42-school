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

#include "ft_printf.h"

int	len_if_x(t_struct v, int i, int len_val)
{
	if ((v.str[i] == 'X' || v.str[i] == 'x') && ft_strchr(v.flag_order, '#')
		&& ft_strcmp((char *)v.arg, "0") == 0)
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
		v = fill_parser(bonus_flag_finder(*i, v), v);
		*i += 1;
		v.nb2 = ft_atoi((const char *)v.str + *i);
		while (v.str[*i] >= '0' && v.str[*i] <= '9')
			*i += 1;
	}
	return (v);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}

int	limit_string(int len_field, int strlen, t_struct v, int i)
{
	int	limit;

	limit = len_field - strlen;
	if ((v.str[i] == 'x' || v.str[i] == 'X')
		&& ft_strchr(v.flag_order, '#') /* && v.zerosnb > strlen */)
		limit -= 2;
	return (limit);
}

int	assign_j(int strlen, t_struct v, int i)
{
	int	j;

	j = strlen + v.zerosnb;
	if ((v.str[i] == 'x' || v.str[i] == 'X')
		&& ft_strchr(v.flag_order, '#'))
		j += 2;
	return (j);
}
