/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 15:56:24 by locagnio          #+#    #+#             */
/*   Updated: 2024/09/22 13:18:55 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* int	ft_char(char *tab)
{
	if (tab[0])
		return (1);
	return (0);
} */

int	ft_count_if(char **tab, int length, int (*f)(char*))
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (i < length)
	{
		if (f(tab[i]) != 0)
			count++;
		i++;
	}
	return (count);
}

/* #include <stdlib.h>
#include <stdio.h>

int main(void)
{
	char *tab1[4];
	char *tab2[13];

	tab1[0] = "";
	tab1[1] = "";
	tab1[2] = "";
	tab1[3] = NULL;

	tab2[0] = "1";
	tab2[1] = "5";
	tab2[2] = "\t";
	tab2[3] = "";
	tab2[4] = "";
	tab2[5] = "0";
	tab2[6] = "";
	tab2[7] = "oui";
	tab2[8] = "ozef";
	tab2[9] = "";
	tab2[10] = "";
	tab2[11] = "non";
	tab2[12] = NULL;
	
	printf("%d\n", ft_count_if(tab1, 3, &ft_char));
	printf("%d\n", ft_count_if(tab2, 12, &ft_char));
	return (0);
} */