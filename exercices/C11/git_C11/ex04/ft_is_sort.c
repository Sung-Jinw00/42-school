/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 16:11:44 by locagnio          #+#    #+#             */
/*   Updated: 2024/09/24 13:34:30 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp_negative(int *s1, int length)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
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
	int	result;

	i = 0;
	result = 0;
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
	int	count;

	count = 0;
	i = 0;
	while (i + 1 < length && tab[i] == tab[i + 1])
		i++;
	if (tab[i + 1])
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
	int tab1[3] = {42, 0, -42};//trie a l'envers
	int tab2[4] = {-42, 41, -39, -40};//non trie
	int tab3[3] = {0, 0, 0};//trie
	int tab4[9] = {INT_MIN, -40, -39, 0, 0, 0, 41, 41, INT_MAX};//trie
	int tab5[3] = {41, 42, 41};//non trie
	int length = 3;
	int resultat;
	
	resultat = ft_is_sort(tab1, length, &ft_minicmp);
	printf("tab1 : %d\n", resultat);
	resultat = ft_is_sort(tab2, length, &ft_minicmp);
	printf("tab2 : %d\n", resultat);
	resultat = ft_is_sort(tab3, length, &ft_minicmp);
	printf("tab3 : %d\n", resultat);
	resultat = ft_is_sort(tab4, length, &ft_minicmp);
	printf("tab4 : %d\n", resultat);
	resultat = ft_is_sort(tab5, length, &ft_minicmp);
	printf("tab5 : %d\n", resultat);
	
	return (0);
} */