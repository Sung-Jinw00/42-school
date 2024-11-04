/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 20:11:36 by locagnio          #+#    #+#             */
/*   Updated: 2024/10/04 11:36:21 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	k;

	k = *a;
	*a = *a / *b;
	*b = k % *b;
}

/* int main(void)
{
	int a;
	int b;

	a = 6;
	b = 3;
	printf("a = %d\nb = %d\n\n", a, b);
	ft_ultimate_div_mod(&a, &b);
	printf("a = %d\nb = %d\n", a, b);
	return (0);
} */