/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 21:01:16 by locagnio          #+#    #+#             */
/*   Updated: 2024/10/19 13:03:15 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 1;
	k = 0;
	while (i < size)
	{
		while (j < size)
		{
			if (tab[i] > tab[j])
			{
				k = tab[i];
				tab[i] = tab[j];
				tab[j] = k;
				i = 0;
				j = 1;
			}
			j++;
		}
		i++;
		j = i + 1;
	}
}

/* int main(void)
{
	int tab[] = {3, -7, 36, 7, 28};
	int size;

	size = 5;
	ft_sort_int_tab(tab, size);
	return (0);
} */

//////////a mettre a la fin de ft_sort_int_tab//////
	/* i = 0;
	while (i < size)
	{
		printf("%d\n", tab[i]);
		i++;
	} */
