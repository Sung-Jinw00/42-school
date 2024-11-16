/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf2_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 22:22:27 by locagnio          #+#    #+#             */
/*   Updated: 2024/11/16 23:22:40 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

t_struct	fill_parser(char c, t_struct v)
{
	int	i;

	i = 0;
	if (!c)
		return (v);
	while (i < 6)
	{
		if (c == v.flag_order[i])
			break ;
		else if (v.flag_order[i] == 0)
		{
			v.flag_order[i] = c;
			break ;
		}
		i++;
	}
	return (v);
}

/* ecris la reponse en conftion des flags */
void	ft_write_answer(int i, int *count, t_struct v, va_list args)
{
	int			j;
	int			len_field;
	long long	nb;

	j = 0;
	nb = 0;
	v = assign_val(i, v, args, nb);
	len_field = ft_len_field(i, v);
	if (v.str[i] == '%' || (v.str[i] == 'c' && ft_strchr(v.flag_order, '.')))
	{
		write(1, &*(char *)v.arg, 1);
		*count += 1;
		return ;
	}
	else
	{
		*count += len_field;
		ft_write_answer2(i, len_field, v);
	}
}

t_struct	flag_filter(int i, t_struct v)
{
	if (ft_strchr(v.flag_order, '0') && (v.str[i] == 's'))
		v = erase_flag('0', v);
	v = keep_prior_flag('0', '-', v);
	if (ft_strchr(v.flag_order, '+') && (v.str[i] == 's' || v.str[i] == 'u'
			|| v.str[i] == 'p' || v.str[i] == 'x' || v.str[i] == 'X'))
		v = erase_flag('+', v);
	if (ft_strchr(v.flag_order, ' ') && (v.str[i] == 's' || v.str[i] == 'u'
			|| v.str[i] == 'x' || v.str[i] == 'X'))
		v = erase_flag(' ', v);
	v = keep_prior_flag(' ', '+', v);
	if (ft_strchr(v.flag_order, '.') && (v.nb2 == 0 || v.str[i] == 'p'
			|| v.str[i] == 'x' || v.str[i] == 'X'))
		v = erase_flag('.', v);
	if (ft_strchr(v.flag_order, '#')
		&& !(v.str[i] == 'x' || v.str[i] == 'X'))
		v = erase_flag('#', v);
	return (v);
}

int	parseur(int i, int *count, t_struct v, va_list args)
{
	while (!((v.str[i] >= '1' && v.str[i] <= '9') || standard_conds(v, i)))
	{
		v = fill_parser(bonus_flag_finder(i, v), v);
		i += 1;
	}
	if (v.str[i] >= '1' && v.str[i] <= '9')
		v.nb1 = ft_atoi((const char *)v.str + i);
	while (v.str[i] >= '0' && v.str[i] <= '9')
		i += 1;
	if (v.str[i] == '.')
	{
		v = fill_parser(bonus_flag_finder(i++, v), v);
		v.nb2 = ft_atoi((const char *)v.str + i);
		while (v.str[i] >= '0' && v.str[i] <= '9')
			i += 1;
	}
	v = flag_filter(i, v);
	ft_write_answer(i, count, v, args);
	return (i);
}

int	print_this_bs(va_list args, t_struct v)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (v.str[i])
	{
		if (v.str[i] == '%' && standard_conds(v, i + 1))
			ft_redpill(++i, &count, v, args);
		else if (v.str[i] == '%' && bonus_conds(v, i + 1))
			i = parseur(i + 1, &count, v, args);
		else
		{
			write(1, &v.str[i], 1);
			count++;
		}
		i++;
	}
	return (count);
}
