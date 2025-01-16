/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 19:29:24 by locagnio          #+#    #+#             */
/*   Updated: 2024/10/02 17:49:14 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_error(char *base)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	if (ft_strlen(base) <= 1)
		return (0);
	while (i <= ft_strlen(base))
	{
		while (j <= ft_strlen(base))
		{
			if (base[i] == base[j] || base[i] == '-' || base[i] == '+'
				|| base[j] == '-' || base[j] == '+')
				return (0);
			j++;
		}
		i++;
		j = i + 1;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	long	nb;
	int		len_base;

	nb = nbr;
	len_base = ft_strlen(base);
	if (ft_error(base))
	{
		if (nb < 0)
		{
			write(1, "-", 1);
			nb = -nb;
		}
		if (nb >= len_base)
			ft_putnbr_base(nb / len_base, base);
		write(1, &base[nb % len_base], 1);
	}
}

/* int main(void)
{
	int nbr = 800;
	char base[] = "poneyvif";

	ft_putnbr_base(nbr, base);
	return (0);
} */
