/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 09:58:38 by locagnio          #+#    #+#             */
/*   Updated: 2025/03/29 17:07:41 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_extras.h"

/* return true if nb is an prime number
*/
int	ft_is_prime(int num)
{
	int i;

	i = 5;
	if (num < 2)
		return (false);
	if (num == 2 || num == 3)
        return (true);
    if (num % 2 == 0 || num % 3 == 0)
        return (false);
	while (i <= ft_sqrt(num))
	{
		if (num % i == 0 || num % (i + 2) == 0)
			return (false);
		i += 6;
	}
    return (true);
}

/*int main(void)
{
	printf("%d\n", ft_is_prime(0));
	return (0);
}*/