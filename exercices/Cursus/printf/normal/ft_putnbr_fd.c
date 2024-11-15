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

void	ft_putnbr_fd(int *count, int n, int fd)
{
	long	nb;

	nb = n;
	if (nb < 0)
	{
		write(fd, "-", 1);
		*count += 1;
		nb = -nb;
	}
	if (nb > 9)
		ft_putnbr_fd(count, nb / 10, fd);
	nb = nb % 10 + '0';
	*count += 1;
	write(fd, &nb, 1);
}

/* int main(void)
{
	ft_putnbr_fd(-5, 2);
	return (0);
} */
