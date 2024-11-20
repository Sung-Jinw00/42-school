/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_normal_solving.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 22:22:27 by locagnio          #+#    #+#             */
/*   Updated: 2024/11/20 16:01:20 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_blackpill(int i, int *count, t_struct v, va_list args)
{
	if (v.str[i] == 'p')
	{
		v.arg = (char *)va_arg(args, void *);
		if (!(char *)v.arg)
		{
			write(1, "(nil)", 5);
			*count += 5;
			return ;
		}
		v.arg = print_ptr((size_t)v.arg, count, "0123456789abcdef");
		ft_bputstr_fd((char *)v.arg, 1);
	}
	else if (v.str[i] == 'i' || v.str[i] == 'd')
	{
		v.zerosnb = -1;
		*(long long *)v.arg = va_arg(args, int);
		ft_bputnbr_fd(count, *(long long *)v.arg, 1, v);
	}
	else
		return ;
}

static void	ft_yellowpill(int i, int *count, t_struct v, va_list args)
{
	if (v.str[i] == 'u')
	{
		*(long long *)v.arg = va_arg(args, int);
		if (*(long long *)v.arg < 0)
			*(long long *)v.arg = (*(long long *)v.arg + (long)INT_MAX * 2 + 2);
		ft_bputunbr_fd(count, *(long long *)v.arg, 1);
	}
	else if (v.str[i] == 'c')
	{
		*(char *)v.arg = (char)va_arg(args, int);
		write (1, &*(char *)v.arg, 1);
		*count = *count + 1;
	}
	else
		ft_blackpill(i, count, v, args);
}

static void	ft_bluepill(int i, int *count, t_struct v, va_list args)
{
	int	j;

	j = 0;
	if (v.str[i] == 'X' || v.str[i] == 'x')
	{
		*(long long *)v.arg = va_arg(args, int);
		if (v.str[i] == 'X')
			v.arg = ft_itoa_base(*(long long *)v.arg, "0123456789ABCDEF");
		else
			v.arg = ft_itoa_base(*(long long *)v.arg, "0123456789abcdef");
		while (((char *)v.arg)[j])
		{
			write (1, &((char *)v.arg)[j++], 1);
			*count += 1;
		}
	}
	else if (v.str[i] == '%')
	{
		write (1, &v.str[i], 1);
		*count = *count + 1;
	}
	else
		ft_yellowpill(i, count, v, args);
}

void	ft_bredpill(int i, int *count, t_struct v, va_list args)
{
	int	j;

	j = 0;
	if (v.str[i] == 's')
	{
		v.arg = va_arg(args, void *);
		if (!v.arg)
		{
			write(1, "(null)", 6);
			*count += 6;
			return ;
		}
		else
		{
			while (((char *)v.arg)[j])
			{
				write (1, &((char *)v.arg)[j++], 1);
				*count += 1;
			}
		}
	}
	else
		ft_bluepill(i, count, v, args);
}
