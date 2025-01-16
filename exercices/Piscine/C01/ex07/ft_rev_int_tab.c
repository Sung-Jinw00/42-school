/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 20:24:17 by locagnio          #+#    #+#             */
/*   Updated: 2024/10/02 15:07:32 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	k;

	i = 0;
	while (i < size / 2)
	{
		k = tab[i];
		tab[i] = tab[size - i - 1];
		tab[size - i - 1] = k;
		i++;
	}
}

/* int main(void)
{
	int tab[] = {5, 4, 3, 2, 1};
	int size;

	size = 5;
	ft_rev_int_tab(tab, size);
	return (0);
} */

//////////a mettre a la fin de ft_rev_int_tab//////
/* i = 0;
while (i < size)
{
	printf("%d\n", tab[i]);
	i++;
} */