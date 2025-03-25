/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 18:06:36 by locagnio          #+#    #+#             */
/*   Updated: 2025/03/21 16:43:20 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* int	ft_strcmp(char *s1, char *s2)
{
	int		i;
	int		result;
	int		i;
	char	*temp;

	i = 0;
	result = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			result = s1[i] - s2[i];
			return (result);
		}
		i++;
	}
	return (result);
} */
void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int		i;
	char	*temp;

	i = 0;
	while (tab[i + 1])
	{
		if (cmp(tab[i], tab[i + 1]) > 0)
		{
			temp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = temp;
			i = -1;
		}
		i++;
	}
}
//////////////a mettre dans la fonction pour afficher////////////
/*
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	char *tab1[4];
	char *tab2[10];
	char *tab3[7];
	char *tab4[3];
	int i = 0;

	tab1[0] = "bateau";
	tab1[1] = "bataille";
	tab1[2] = "blaireau";
	tab1[3] = NULL;

	tab2[0] = "echarpe";
	tab2[1] = "ecran";
	tab2[2] = "enum";
	tab2[3] = "ecole";
	tab2[4] = "esekoisa";
	tab2[5] = "edemwa";
	tab2[6] = "qu'est-ce que je fais de ma vie ?";
	tab2[7] = "BSQ";
	tab2[8] = "banane";
	tab2[9] = NULL;

	tab3[0] = "hallo";
	tab3[1] = "hallo";
	tab3[2] = "monsieur";
	tab3[3] = "l'";
	tab3[4] = "ordi";
	tab3[5] = "nateur";
	tab3[6] = NULL;

	tab4[0] = "oui";
	tab4[1] = "non";
	tab4[2] = NULL;


	ft_advanced_sort_string_tab(tab1, &ft_strcmp);
	while (tab1[i])
	{
		printf("tableau %d tab1 : %s\n", i, tab1[i]);
		i++;
	}
	printf("\n");
	i = 0;
	ft_advanced_sort_string_tab(tab2, &ft_strcmp);
	while (tab2[i])
	{
		printf("tableau %d tab2 : %s\n", i, tab2[i]);
		i++;
	}
	printf("\n");
	i = 0;
	ft_advanced_sort_string_tab(tab3, &ft_strcmp);
	while (tab3[i])
	{
		printf("tableau %d tab3 : %s\n", i, tab3[i]);
		i++;
	}
	printf("\n");
	i = 0;
	ft_advanced_sort_string_tab(tab4, &ft_strcmp);
	while (tab4[i])
	{
		printf("tableau %d tab4 : %s\n", i, tab4[i]);
		i++;
	}
	return (0);
} */