/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 16:11:44 by locagnio          #+#    #+#             */
/*   Updated: 2024/09/26 12:13:59 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp_negative(int *s1, int length)
{
	int	i;

	i = 0;
	while (i + 1 < length)
	{
		if (s1[i] < s1[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	ft_strcmp(int *s1, int length)
{
	int	i;

	i = 0;
	while (i + 1 < length)
	{
		if (s1[i] > s1[i + 1])
			return (0);
		i++;
	}
	return (1);
}

/* int	ft_minicmp(int s1, int s2)
{
	return (s1 - s2);
} */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;

	i = 0;
	while (i + 1 < length && tab[i] == tab[i + 1])
		i++;
	if (i < length)
	{
		if (f(tab[i], tab[i + 1]) > 0)
		{
			if (!ft_strcmp_negative(tab + i, length - i))
				return (0);
		}
		if (f(tab[i], tab[i + 1]) < 0)
		{
			if (!ft_strcmp(tab + i, length - i))
				return (0);
		}
	}
	return (1);
}

/* #include <stdio.h>
#include <limits.h>
int main(void)
{
	int tab1[5] = {42, 0, -42};//trie a l'envers
	int tab2[4] = {-42, 41, -39, -40};//non trie
	int tab3[3] = {0, -1};//trie
	int tab4[9] = {INT_MIN, -40, -39, 0, 0, 0, 41, 41, INT_MAX};//trie
	int tab5[3] = {41, 42, 41};//non trie
	int resultat;
	
	resultat = ft_is_sort(tab1, 3, &ft_minicmp);
	printf("tab1 : %d\n", resultat);
	resultat = ft_is_sort(tab2, 4, &ft_minicmp);
	printf("tab2 : %d\n", resultat);
	resultat = ft_is_sort(tab3, 2, &ft_minicmp);
	printf("tab3 : %d\n", resultat);
	resultat = ft_is_sort(tab4, 9, &ft_minicmp);
	printf("tab4 : %d\n", resultat);
	resultat = ft_is_sort(tab5, 3, &ft_minicmp);
	printf("tab5 : %d\n", resultat);
	
	return (0);
} */