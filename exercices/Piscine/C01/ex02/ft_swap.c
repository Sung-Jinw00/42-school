/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 19:29:00 by locagnio          #+#    #+#             */
/*   Updated: 2024/10/04 11:36:13 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int	k;

	k = *a;
	*a = *b;
	*b = k;
}

/* int main(void)
{
	int a;
	int b;

	a = 3;
	b = 6;
	printf("a = %d\nb = %d\n\n", a, b);
	ft_swap(&a, &b);
	printf("a = %d\nb = %d\n", a, b);
	return(0);
} */
