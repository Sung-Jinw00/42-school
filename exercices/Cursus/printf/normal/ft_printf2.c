/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 22:22:27 by locagnio          #+#    #+#             */
/*   Updated: 2024/11/12 23:34:55 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_ptr(size_t adr, int *count)
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

void	ft_blackpill(int i, int *count, t_struct v, va_list args)
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

void	ft_yellowpill(int i, int *count, t_struct v, va_list args)
{
	if (v.str[i] == 'u')
	{
		if (*(int *)v.arg < 0)
			*(unsigned int *)v.arg = va_arg(args, int) + (long)INT_MAX * 2;
		else
			*(int *)v.arg = va_arg(args, int);
		ft_putunbr_fd(count, *(unsigned int *)v.arg, 1);
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

void	ft_bluepill(int i, int *count, t_struct v, va_list args)
{
	int	j;

	j = 0;
	if (v.str[i] == 'X' || v.str[i] == 'x')
	{
		*(int *)v.arg = va_arg(args, int);
		if (v.str[i] == 'X')
			v.arg = ft_itoa_base(*(int *)v.arg, "0123456789ABCDEF");
		else
			v.arg = ft_itoa_base(*(int *)v.arg, "0123456789abcdef");
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
