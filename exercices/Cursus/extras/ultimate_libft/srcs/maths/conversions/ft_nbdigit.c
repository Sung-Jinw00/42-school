/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 18:45:10 by marvin            #+#    #+#             */
/*   Updated: 2025/04/13 18:45:10 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ultimate_libft.h"

int	ft_nbdigit(long double nb, int base)
{
	int	digit;

	digit = 1;
	while (nb >= base)
	{
		nb /= base;
		digit++;
	}
	return (digit);
}
