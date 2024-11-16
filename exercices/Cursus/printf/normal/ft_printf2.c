/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 22:22:27 by locagnio          #+#    #+#             */
/*   Updated: 2024/11/17 00:44:07 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_ptr(size_t adr, int *count)
{
	char	ptr[18];
	int		i;
	char	*hexa;
	size_t	adr_copy;

	hexa = "0123456789abcdef";
	i = 2;
	adr_copy = adr;
	while (adr_copy > 0)
	{
		adr_copy /= 16;
		i++;
	}
	ptr[i--] = '\0';
	*count += i + 1;
	while (adr > 0)
	{
		ptr[i] = hexa[adr % 16];
		adr /= 16;
		i--;
	}
	ptr[i] = 'x';
	i--;
	ptr[i] = '0';
	ft_putstr_fd(ptr, 1);
}

static void	ft_blackpill(int i, int *count, t_struct v, va_list args)
{
	int	j;

	j = 0;
	if (v.str[i] == 'p')
	{
		v.arg = va_arg(args, void *);
		if (!v.arg)
		{
			write(1, "(nil)", 5);
			*count += 5;
			return ;
		}
		print_ptr((size_t)v.arg, count);
	}
	else if (v.str[i] == 'i' || v.str[i] == 'd')
	{
		*(int *)v.arg = va_arg(args, int);
		ft_putnbr_fd(count, *(int *)v.arg, 1);
	}
	else
		return ;
}

static void	ft_yellowpill(int i, int *count, t_struct v, va_list args)
{
	long	value;

	value = 0;
	if (v.str[i] == 'u')
	{
		value = va_arg(args, int);
		if (value < 0)
			*(unsigned long *)v.arg = (unsigned long)(value + \
			(long)INT_MAX * 2 + 2);
		else
			*(unsigned long *)v.arg = (unsigned long)value;
		ft_putunbr_fd(count, *(unsigned long *)v.arg, 1);
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
	int			j;
	long long	value;

	value = 0;
	j = 0;
	if (v.str[i] == 'X' || v.str[i] == 'x')
	{
		value = va_arg(args, int);
		if (v.str[i] == 'X')
			v.arg = ft_itoa_base(value, "0123456789ABCDEF");
		else
			v.arg = ft_itoa_base(value, "0123456789abcdef");
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

void	ft_redpill(int i, int *count, t_struct v, va_list args)
{
	int	j;

	j = 0;
	if (v.str[i] == 's')
	{
		v.arg = va_arg(args, char *);
		if (!v.arg)
		{
			write(1, "(null)", 6);
			*count += 6;
			return ;
		}
		while (((char *)v.arg)[j])
		{
			write (1, &((char *)v.arg)[j++], 1);
			*count += 1;
		}
	}
	else
		ft_bluepill(i, count, v, args);
}
