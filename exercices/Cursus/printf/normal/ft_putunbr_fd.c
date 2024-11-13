/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:30:58 by locagnio          #+#    #+#             */
/*   Updated: 2024/11/04 13:30:58 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putunbr_fd(int *count, unsigned long n, int fd)
{
	if (n < 0)
	{
		write(fd, "-", 1);
		*count += 1;
		n = -n;
	}
	if (n > 9)
		ft_putunbr_fd(count, n / 10, fd);
	n = n % 10 + '0';
	*count += 1;
	write(fd, &n, 1);
}

/* int main(void)
{
	ft_putnbr_fd(-5, 2);
	return (0);
} */
