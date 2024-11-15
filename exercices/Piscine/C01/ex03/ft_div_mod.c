/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 19:53:01 by locagnio          #+#    #+#             */
/*   Updated: 2024/10/02 14:48:33 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}

/* int main(void)
{
	int a;
	int b;
	int div;
	int mod;

	a = 6;
	b = 4;
	div = 0;
	mod = 0;
	printf("div = %d\nmod = %d\n\n", div, mod);
	ft_div_mod(a, b, &div, &mod);
	printf("div = %d\nmod = %d\n", div, mod);
	return (0);
} */