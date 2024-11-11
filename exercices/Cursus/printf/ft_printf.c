/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 16:05:11 by locagnio          #+#    #+#             */
/*   Updated: 2024/11/11 18:55:18 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "printflibft.h"
#include <limits.h>

char	*ft_itoa_base(int n, const char *base);
void	ft_putunbr_fd(unsigned int n, int fd);

void	ft_yellowpill(const char *str, int i, void *arg, va_list args)
{
	int j;

	j = 0;
	if (str[i] == 'u')
	{
		if (*(int *)arg < 0)
			*(unsigned int *)arg = va_arg(args, int) + (long)INT_MAX * 2;
		else
			*(int *)arg = va_arg(args, int);
		ft_putunbr_fd(*(unsigned int *)arg, 1);
	}
	else if (str[i] == 'x')
	{
		*(int *)arg = va_arg(args, int);
		arg = ft_itoa_base(*(int *)arg, "0123456789abcdef");
		while (((char *)arg)[j])
			write (1, &((char *)arg)[j++], 1);
		j = 0;
	}
	else
		return ;
}

void	ft_bluepill(const char *str, int i, void *arg, va_list args)
{
	int j;

	j = 0;
	if (str[i] == 'X')
	{
		*(int *)arg = va_arg(args, int);
		arg = ft_itoa_base(*(int *)arg, "0123456789ABCDEF");
		while (((char *)arg)[j])
			write (1, &((char *)arg)[j++], 1);
		j = 0;
	}
	else if (str[i] == 'i' || str[i] == 'd')
	{
		*(int *)arg = va_arg(args, int);
		ft_putnbr_fd(*(int *)arg, 1);
	}
	else
		ft_yellowpill(str, i, arg, args);

}

void	print_ptr(size_t adr)
{
	char	ptr[16];
	int		i;
	char	*hexa;
	size_t adr_copy;

	hexa = "0123456789ABCDEF";
	i = 2;
	adr_copy = adr;
	while (adr_copy > 0)
	{
		adr_copy /= 16;
		i++;
	}
	ptr[i--] = '\0';
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

void	ft_redpill(const char *str, int i, void *arg, va_list args)
{
	int j;

	j = 0;
	if (str[i] == 'c')
	{
		*(char *)arg = (char)va_arg(args, int);
		write (1, &*(char *)arg, 1);
	}
	else if (str[i] == 's')
	{
		arg = va_arg(args, char *);
		while (((char *)arg)[j])
			write (1, &((char *)arg)[j++], 1);
	}
	else if (str[i] == 'p')
	{
		arg = va_arg(args, void *);
		print_ptr((size_t)arg);
	}
	else if (str[i] == '%')
		write (1, &str[i], 1);
	else
		ft_bluepill(str, i, arg, args);
}

int ft_printf(const char *str, ...)
{
	va_list		args;
	int			i;
	void		*arg;
	int			j;

	i = 0;
	j = 0;
	arg = 0;
	va_start(args, str);
	arg = malloc(8);
	while (str[i])
	{
		if (str[i] == '%')
			ft_redpill(str, ++i, arg, args);
		else
			write(1, &str[i], 1);
		i++;
	}
	free(arg);
	va_end(args);
	return (0);
}

#include <stdio.h>

int main(void)
{
	printf("%s%c%d%c%c%c%d\n", "Premier test : ", 'm', 4, 'r', 'c', 'h', 3);
	ft_printf("%s%c%d%c%c%c%d\n", "Premier test : ", 'm', 4, 'r', 'c', 'h', 3);
	return (0);
}
