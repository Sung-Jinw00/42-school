/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 21:01:16 by locagnio          #+#    #+#             */
/*   Updated: 2024/09/05 21:25:05 by locagnio         ###   ########.fr       */
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

/*int ft_strlen(int *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}*/

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;

	size -= 1;
	i = 0;
	j = 1;
	while (i <= size)
	{
		while (j <= size)
		{
			if (tab[i] > tab[j])
			{
				ft_swap(&tab[i], &tab[j]);
				i = 0;
				j = 1;
			}
			j++;
		}
		i++;
		j = i + 1;
	}
}
/*
int main(void)
{
	int tab[] = {3, -7, 36, 7, 28};
	int size;

	size = 0;
	size = ft_strlen(tab);
	ft_sort_int_tab(tab, size);
	return (0);
}
*/

//////////a mettre a la fin de ft_sort_int_tab//////
/*
	i = 0;
	while (i <= size)
	{
		printf("%d\n", tab[i]);
		i++;
	}*/