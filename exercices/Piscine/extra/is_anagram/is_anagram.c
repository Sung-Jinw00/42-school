/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_anagram.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 13:32:12 by marvin            #+#    #+#             */
/*   Updated: 2024/10/24 13:32:12 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_anagram(char *a, char *b)
{
	int     array[96];
	int     i;
	int j;

	i = -1;
	while (++i < 96)
		array[i] = 0;
	i = -1;
	while (a[++i])
	{
		j = a[i] - 32;
		array[j] += 1;
	}
	i = -1;
	while (b[++i])
	{
		j = b[i] - 32;
		array[j] -= 1;
	}
	i = -1;
	while (++i < 96)
		if (array[i] != 0)
			return (0);
	return (1);
}

#include <stdio.h>

/* int	main(void)
{
	int i = 0;
	int k = 32;
	int l = 126;

	char tab1[1000001];
	char tab2[1000001];

	while (i < 1000000)
	{
		if (k < 126 && l == 32)
		{
			tab1[i] = k;
			tab2[i] = l;
			k++;
		}
		else if (k == 126 && l > 32)
		{
			tab1[i] = k;
			tab2[i] = l;
			l--;
		}
		i++;
	}
	tab1[i] = 0;
	tab2[i] = 0;
	if (is_anagram(tab1, tab2))
		printf("1");
	else
		printf("0");
	return(0);
} */

int main(int ac, char **av)
{
	if (ac == 3)
	{
		if (is_anagram(av[1], av[2]))
		{
			printf("1");
			return (1);
		}
	}
	printf("0");
	return (0);	
}