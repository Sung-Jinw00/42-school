/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 16:18:33 by locagnio          #+#    #+#             */
/*   Updated: 2024/11/20 15:11:36 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_struct	keep_prior_flag(char erased, char prior, t_struct v)
{
	int	j;
	int	save;

	j = 0;
	save = 0;
	while (v.flag_order[j])
	{
		if (v.flag_order[j] == erased || v.flag_order[j] == prior)
			save = j++;
		if (v.flag_order[j] == erased || v.flag_order[j] == prior)
		{
			if (v.flag_order[save] == erased)
				j = save;
			while (v.flag_order[j] != '\0')
			{
				v.flag_order[j] = v.flag_order[j + 1];
				j++;
			}
			break ;
		}
		j++;
	}
	return (v);
}

int	ft_strchr(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

t_struct	erase_flag(char erased, t_struct v)
{
	int	j;

	j = 0;
	while (v.flag_order[j])
	{
		if (v.flag_order[j] == erased)
		{
			while (v.flag_order[j] != '\0')
			{
				v.flag_order[j] = v.flag_order[j + 1];
				j++;
			}
			break ;
		}
		j++;
	}
	return (v);
}

t_struct	assign_val2(int i, t_struct v, va_list args, long long nb)
{
	if (v.str[i] == 'p')
	{
		v.arg = va_arg(args, void *);
		if (!v.arg)
			v.arg = "(nil)";
		else
			v.arg = print_ptr((size_t)v.arg, (int *)&nb, \
			"0123456789abcdef");
	}
	else if (v.str[i] == 'u')
	{
		*(long long *)v.arg = va_arg(args, int);
		if (*(long long *)v.arg < 0)
			*(long long *)v.arg = (*(long long *)v.arg + (long)INT_MAX * 2 + 2);
	}
	else if (v.str[i] == 'i' || v.str[i] == 'd')
	{
		nb = va_arg(args, int);
		*(long long *)v.arg = nb;
	}
	else
		v = assign_val3(i, v, args, nb);
	return (v);
}

t_struct	assign_val(int i, t_struct v, va_list args, long long nb)
{
	if (v.str[i] == 's')
	{
		v.arg = va_arg(args, char *);
		if (!(char *)v.arg)
		{
			if (ft_strchr(v.flag_order, '.') && !special_cases(v, i)
				&& v.nb2 < 6)
			{
				erase_flag('.', v);
				v.arg = "";
			}
			else
				v.arg = "(null)";
		}
		else if (ft_strchr(v.flag_order, '.') && v.nb2 == 0)
			v.arg = "";
	}
	else
		v = assign_val2(i, v, args, nb);
	return (v);
}
