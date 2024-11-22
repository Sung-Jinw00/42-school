/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 19:53:23 by locagnio          #+#    #+#             */
/*   Updated: 2024/11/22 16:40:15 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*print_ptr(size_t adr, int *count, char *hexa)
{
	char	*ptr;
	int		i;
	size_t	adr_copy;

	ptr = ft_calloc(18 + 1, 1);
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
	return (ptr);
}

void	ft_putunbr(int *count, unsigned long n)
{
	if (n > 9)
		ft_putunbr(count, n / 10);
	n = n % 10 + '0';
	*count += 1;
	write(1, &n, 1);
}

void	ft_putnbr(int *count, long long n, t_struct v)
{
	if (n < 0)
	{
		write(1, "-", 1);
		*count += 1;
		n = -n;
	}
	v.zerosnb = printfzeronb(v, 0);
	v.zerosnb = -1;
	if (n > 9)
		ft_putnbr(count, n / 10, v);
	n = n % 10 + '0';
	*count += 1;
	write(1, &n, 1);
}

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
}
