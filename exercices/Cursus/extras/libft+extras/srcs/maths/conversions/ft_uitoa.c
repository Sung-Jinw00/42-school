/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:31:07 by locagnio          #+#    #+#             */
/*   Updated: 2025/04/13 20:11:58 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_extras.h"

/**
 * @brief
 * Transform an unsigned number into a string.
 * 
 * @returns
 * - The string version of an unsigned number.
*/
char	*ft_uitoa(uint64_t n)
{
	uint64_t	nb;
	char		*cpy;
	int			digits;

	digits = 1;
	nb = n;
	while (nb >= 10)
	{
		nb /= 10;
		digits++;
	}
	cpy = malloc(sizeof(char) * digits + 1);
	if (!cpy)
		return (NULL);
	cpy[digits--] = '\0';
	while (digits >= 0)
	{
		cpy[digits] = n % 10 + '0';
		n /= 10;
		digits--;
	}
	return (cpy);
}

/* #include <stdio.h>
#include <string.h>

int	main(void)
{
	char *i1 = ft_itoa(0);
	char *i2 = ft_itoa(9);
	char *i3 = ft_itoa(-9);
	char *i4 = ft_itoa(10);
	char *i5 = ft_itoa(-10);
	char *i6 = ft_itoa(8124);

	if (strcmp(i1, "0"))
	{
		printf("la reponse attendue : 0\nma reponse : %s\n", i1);
		printf("fail test 1");
		return (0);
	}
	if (strcmp(i2, "9"))
	{
		printf("la reponse attendue : 9\nma reponse : %s\n", i2);
		printf("fail test 2");
		return (0);
	}
	if (strcmp("-9", i3))
	{
		printf("la reponse attendue : -9\nma reponse : %s\n", i3);
		printf("fail test 3");
		return (0);
	}
	if (strcmp(i4, "10"))
	{
		printf("la reponse attendue : 10\nma reponse : %s\n", i4);
		printf("fail test 1");
		return (0);
	}
	if (strcmp(i5, "-10"))
	{
		printf("la reponse attendue : -10\nma reponse : %s\n", i5);
		printf("fail test 2");
		return (0);
	}
	if (strcmp("8124", i6))
	{
		printf("la reponse attendue : 8124\nma reponse : %s\n", i6);
		printf("fail test 3");
		return (0);
	}
	printf("gg win");
	return (0);

} */