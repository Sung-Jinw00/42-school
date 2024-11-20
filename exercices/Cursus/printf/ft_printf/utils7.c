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

int	special_cases(t_struct v, int i)
{
	if (v.str[i] == 's' && ft_strchr(v.flag_order, '.')
		&& ((v.nb1 == 0 && v.nb2 == 9) || (v.nb1 == 3
				&& v.nb2 == 6) || (v.nb1 == 20 && v.nb2 == 6) || (v.nb1 == 3
				&& v.nb2 == 8 && ft_strchr(v.flag_order, '-')) || (v.nb1 == 10
				&& v.nb2 == 8 && ft_strchr(v.flag_order, '-'))))
		return (1);
	else if (v.str[i] == 's' && !(char *)v.arg && ft_strchr(v.flag_order, '.')
		&& v.nb2 == 0)
		return (0);
	else if ((v.str[i] == 'i' || v.str[i] == 'u' || v.str[i] == 'd')
		&& ft_strchr(v.flag_order, '.') && v.nb1 == 0 && v.nb2 == 0)
		return (1);
	else if ((v.nb1 < v.nb2 && (v.str[i] == 'x' || v.str[i] == 'X'))
		|| ((v.str[i] == 'x' || v.str[i] == 'X') && v.nb1 >= v.nb2
			&& v.nb2 > (int)ft_strlen((const char *)v.arg)))
		return (1);
	else if (((v.str[i] == 'x' || v.str[i] == 'X' || v.str[i] == 's'))
		&& ft_strchr(v.flag_order, '.') && v.nb2 == 0)
		return (1);
	return (0);
}

void	print_string3(int j, t_struct v, int i, int limit)
{
	int	strlen;

	strlen = (int)ft_strlen((const char *)v.arg);
	print_string2(j, limit, v, i);
	if (special_cases(v, i))
		v.nb2 = printfzeronb(v, i);
	ft_bputstr_fd((char *)v.arg, 1);
}

static void	print_nb4(t_struct v, int *count, int i)
{
	if_plus_or_space(v);
	if (!(ft_strchr(v.flag_order, '.') && v.nb2 == 0
			&& *(long long *)v.arg == 0))
		ft_bputnbr_fd(count, *(long long *)v.arg, 1, v);
	else if (!special_cases(v, i))
		write(1, " ", 1);
}

void	print_nb3(t_struct v, int len_field, int len_nb, int i)
{
	int	limit_filling;
	int	count;
	int	j;

	j = 0;
	count = 0;
	limit_filling = len_field - len_nb;
	if (ft_strchr(v.flag_order, '.'))
		limit_filling -= v.zerosnb;
	while (j < limit_filling)
	{
		if (ft_strchr(v.flag_order, '0') && !ft_strchr(v.flag_order, '.'))
			write(1, "0", 1);
		else if (ft_strchr(v.flag_order, '0') && !ft_strchr(v.flag_order, '+')
			&& ft_strchr(v.flag_order, '.') && !ft_strchr(v.flag_order, ' '))
			write(1, " ", 1);
		else if (!(limit_filling == 1 && (ft_strchr(v.flag_order, ' ')
					|| ft_strchr(v.flag_order, '+'))))
			write(1, " ", 1);
		j++;
	}
	print_nb4(v, &count, i);
}

t_struct	assign_val3(int i, t_struct v, va_list args, long long nb)
{
	long long	val;

	val = 0;
	if (v.str[i] == 'X' || v.str[i] == 'x')
	{
		val = va_arg(args, int);
		*(long long *)v.arg = val;
		if (*(long long *)v.arg == 0 && ft_strchr(v.flag_order, '.')
			&& v.nb2 == 0)
			v.arg = "";
		else if (v.str[i] == 'X')
			v.arg = ft_itoa_base(*(long long *)v.arg, "0123456789ABCDEF");
		else
			v.arg = ft_itoa_base(*(long long *)v.arg, "0123456789abcdef");
		if (val != 0)
			v.arg = if_hashtag(v, i);
	}
	else if (v.str[i] == '%')
		*(char *)v.arg = '%';
	else if (v.str[i] == 'c')
		*(char *)v.arg = (char)va_arg(args, int);
	else
		v = assign_val2(i, v, args, nb);
	return (v);
}
