/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 10:04:52 by locagnio          #+#    #+#             */
/*   Updated: 2024/09/11 20:30:51 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_is_prime(int nb)
{
	int	i;

	i = nb / 2;
	if (nb <= 1)
		return (0);
	while (i > 1)
	{
		if (nb % i == 0)
			return (0);
		i--;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	int	i;

	i = nb / 2;
	if (nb <= 1)
		return (0);
	while (!ft_is_prime(nb))
		nb++;
	if (ft_is_prime(nb))
		return (nb);
	return (0);
}

/*int main(void)
{
	printf("%d\n", ft_find_next_prime(59));
	return (0);
}*/