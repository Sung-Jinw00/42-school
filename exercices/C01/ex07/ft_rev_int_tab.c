/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 20:24:17 by locagnio          #+#    #+#             */
/*   Updated: 2024/09/07 17:46:55 by locagnio         ###   ########.fr       */
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

// int main(void)
// {
// 	int tab[] = {5, 4, 3, 2, 1, 2, 3, 1};
// 	int size;

// 	size = 8;
// 	printf("%s", ft_rev_int_tab(tab, size));
// 	return (0);
// }

//////////a mettre a la fin de ft_rev_int_tab//////
/*printf("%ls\n", tab);*/