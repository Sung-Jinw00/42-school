/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils6_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 20:16:31 by locagnio          #+#    #+#             */
/*   Updated: 2024/11/17 00:16:03 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

char	*if_hashtag(t_struct v, int i)
{
	if (ft_strchr(v.flag_order, '#') && v.str[i] == 'X')
		ft_strjoin("0X", (char const *)v.arg);
	else if (ft_strchr(v.flag_order, '#') && v.str[i] == 'x')
		ft_strjoin("0x", (char const *)v.arg);
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
	if (v.str[i] == '%' || v.str[i] == 'c')
		print_char(v, len_field);
	else if (v.str[i] == 's' || v.str[i] == 'p' || v.str[i] == 'x'
		|| v.str[i] == 'X')
		print_string(v, len_field, i);
	else
	{
		if (*(long long *)v.arg < 0 && ft_strchr(v.flag_order, '+'))
			v = erase_flag('+', v);
		else if (*(long long *)v.arg < 0 && ft_strchr(v.flag_order, ' '))
			v = erase_flag(' ', v);
		print_nb(v, len_field);
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
			&& ft_strchr(v.flag_order, '#'))
		{
			write(1, "0x", 2);
			break ;
		}
		else if ((j + 2 == limit) && v.str[i] == 'X'
			&& ft_strchr(v.flag_order, '#'))
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

	len_val = 0;
	if (v.str[i] == '%' || v.str[i] == 'c')
		len_val = 1;
	else if (v.str[i] == 's' || v.str[i] == 'p' || v.str[i] == 'X'
		|| v.str[i] == 'x')
		len_val = ft_bstrlen((const char *)v.arg);
	return (len_val);
}