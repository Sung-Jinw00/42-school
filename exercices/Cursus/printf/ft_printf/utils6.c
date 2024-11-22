/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils6.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 20:16:31 by locagnio          #+#    #+#             */
/*   Updated: 2024/11/22 17:11:39 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*if_hashtag(t_struct v, int i)
{
	if (ft_strchr(v.flag_order, '#') && v.str[i] == 'X')
	{
		if (v.nb2 <= (int)ft_strlen((const char *)v.arg))
			v.arg = ft_strjoin("0X", (const char *)v.arg);
	}
	else if (ft_strchr(v.flag_order, '#') && v.str[i] == 'x')
	{
		if (v.nb2 <= (int)ft_strlen((const char *)v.arg))
			v.arg = ft_strjoin("0x", (const char *)v.arg);
	}
	return ((char *)v.arg);
}

void	if_plus_or_space(t_struct v)
{
	if (ft_strchr(v.flag_order, '+') && *(long long *)v.arg >= 0)
		write (1, "+", 1);
	else if (ft_strchr(v.flag_order, ' ') && *(long long *)v.arg >= 0)
		write(1, " ", 1);
}

void	ft_write_answer2(int i, int len_field, t_struct v)
{
	int	trigger;

	trigger = 0;
	if (v.str[i] == '%' || v.str[i] == 'c')
		print_char(v, len_field);
	else if (v.str[i] == 's' || v.str[i] == 'p' || v.str[i] == 'x'
		|| v.str[i] == 'X')
	{
		if ((v.nb2 < (int)ft_strlen((const char *)v.arg)
				&& ft_strchr(v.flag_order, '.') && v.str[i] == 's'))
		{
			v.arg = ft_strndup((char *)v.arg, (size_t)v.nb2);
			trigger = 1;
		}
		print_string(v, len_field, i, trigger);
	}
	else
	{
		if (*(long long *)v.arg < 0 && ft_strchr(v.flag_order, '+'))
			v = erase_flag('+', v);
		else if (*(long long *)v.arg < 0 && ft_strchr(v.flag_order, ' '))
			v = erase_flag(' ', v);
		print_nb(v, len_field, i);
	}
}

void	print_string2(int j, int limit, t_struct v, int i)
{
	while (j < limit)
	{
		if ((v.str[i] == 'x' || v.str[i] == 'X')
			&& ft_strchr(v.flag_order, '0'))
			write(1, "0", 1);
		else if ((j + 2 == limit) && v.str[i] == 'x'
			&& ft_strchr(v.flag_order, '#'
				&& ft_strcmp((char *)v.arg, "") == 0))
		{
			write(1, "0x", 2);
			break ;
		}
		else if ((j + 2 == limit) && v.str[i] == 'X'
			&& ft_strchr(v.flag_order, '#'
				&& ft_strcmp((char *)v.arg, "") == 0))
		{
			write(1, "0X", 2);
			break ;
		}
		else
			write(1, " ", 1);
		j++;
	}
}

int	assign_if_non_nb(t_struct v, int i)
{
	int	len_val;
	int	strlen;

	strlen = 0;
	len_val = 0;
	if (v.str[i] == '%' || v.str[i] == 'c')
		len_val = 1;
	else if (v.str[i] == 's' || v.str[i] == 'p' || v.str[i] == 'X'
		|| v.str[i] == 'x')
	{
		strlen = (int)ft_strlen((const char *)v.arg);
		if (ft_strchr(v.flag_order, '.') && v.str[i] == 's'
			&& v.nb2 < strlen)
			len_val = v.nb2;
		else
			len_val = strlen;
		if ((v.str[i] == 'X' || v.str[i] == 'x') && v.nb2 > strlen
			&& ft_strchr(v.flag_order, '.'))
		{
			v.nb2 -= strlen;
			len_val += v.nb2;
		}
	}
	return (len_val);
}
