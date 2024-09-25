/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 20:11:36 by locagnio          #+#    #+#             */
/*   Updated: 2024/09/05 21:19:40 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>*/

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	k;

	k = *a;
	*a = *a / *b;
	*b = k % *b;
}
/*
int main(void)
{
	int a;
	int b;

	a = 6;
	b = 3;

	ft_ultimate_div_mod(&a, &b);
	printf("a = %d\nb = %d\n", a, b);
	return (0);
}*/