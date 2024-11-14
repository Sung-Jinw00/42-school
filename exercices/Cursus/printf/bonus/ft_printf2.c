/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 22:22:27 by locagnio          #+#    #+#             */
/*   Updated: 2024/11/14 19:12:25 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_bonus_solving(int i, int *count, t_struct v, va_list args);

void	ft_bonus_space(int i, int *count, t_struct v, va_list args)
{
	write (1, " ", 1);
	*count += 1;
	while (v.str[i] == ' ')
		i++;
	if (standard_conds(v, i + 1))
		ft_redpill(++i, &count, v, args);
	else if (bonus_conds(v, i + 1))
		ft_bonus_solving(i, count, v, args);
}

t_struct fill_parser(char c, t_struct v)
{
	int i;

	i = 0;
	if (c == '-')
		v.flags_found[0]++;
	else if (c == '0')
		v.flags_found[1]++;
	else if (c == '.')
		v.flags_found[2]++;
	else if (c == '#')
		v.flags_found[3]++;
	else if (c == ' ')
		v.flags_found[4]++;
	else if (c == '+')
		v.flags_found[5]++;
	while (i < 7)
	{
		if (c == v.flags_found[i])
			break;
		else if (v.flags_found[i] == 0)
			v.flags_found[i] = c;
		i++;
	}
	return (v);
}

void	ft_write_answer(int i, int *count, t_struct v, va_list args)
{
	
}

void	parseur(int i, int *count, t_struct v, va_list args)
{
	while(!((v.str[i] >= '1' || v.str[i] <= '9') || standard_conds(v, i)))
	{
		v = fill_parser(flag_finder(i, v), v);
		i++;
	}
	if (v.str[i] >= '1' || v.str[i] <= '9')
		v.nb = ft_atoi((const char *)v.str + i);
	while (v.str[i] >= '1' || v.str[i] <= '9')
		i++;
	ft_write_answer(i, count, v, args);
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
			ft_bonus_solving(++i, &count, v, args);
		else
		{
			write(1, &v.str[i], 1);
			count++;
		}
		i++;
	}
	return (count);
}
