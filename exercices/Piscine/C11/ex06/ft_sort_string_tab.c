/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 17:48:36 by locagnio          #+#    #+#             */
/*   Updated: 2024/09/22 13:21:29 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;
	int	result;

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
}

char	**ft_check(int ac, char **av)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	j = 1;
	while (i < ac)
	{
		while (j < ac)
		{
			if (ft_strcmp(av[i], av[j]) > 0)
			{
				temp = av[i];
				av[i] = av[j];
				av[j] = temp;
			}
			j++;
		}
		i++;
		j = i + 1;
	}
	return (av);
}

void	ft_sort_string_tab(char **tab)
{
	int	len;
	int	i;

	i = 0;
	len = ft_strlen(tab);
	tab = ft_check(len, tab);
}
//////////////a mettre dans la fonction pour afficher////////////
/* 	return (tab);

#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	char *tab1[4];
	char *tab2[10];
	char *tab3[7];
	char *tab4[3];
	char **result;
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


	result = ft_sort_string_tab(tab1);
	while (result[i])
	{
		printf("tableau %d tab1 : %s\n", i, result[i]);
		i++;
	}
	printf("\n");
	i = 0;
	result = ft_sort_string_tab(tab2);
	while (result[i])
	{
		printf("tableau %d tab2 : %s\n", i, result[i]);
		i++;
	}
	printf("\n");
	i = 0;
	result = ft_sort_string_tab(tab3);
	while (result[i])
	{
		printf("tableau %d tab3 : %s\n", i, result[i]);
		i++;
	}
	printf("\n");
	i = 0;
	result = ft_sort_string_tab(tab4);
	while (result[i])
	{
		printf("tableau %d tab4 : %s\n", i, result[i]);
		i++;
	}
	return (0);
} */