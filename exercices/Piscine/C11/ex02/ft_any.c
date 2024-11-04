/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_any.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 12:50:31 by locagnio          #+#    #+#             */
/*   Updated: 2024/09/22 13:18:39 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include <stdio.h>

int	ft_char(char *tab)
{
	if (tab[0])
		return (1);
	return (0);
} */

int	ft_any(char **tab, int (*f)(char*))
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (tab[i])
	{
		if (f(tab[i]))
			count++;
		i++;
	}
	if (count != 0)
		return (1);
	return (0);
}
/* #include <stdlib.h>

int main(void)
{
	char *tab1[4];
	char *tab2[13];

	tab1[0] = "";
	tab1[1] = "";
	tab1[2] = "";
	tab1[3] = NULL;

	tab2[0] = "";
	tab2[1] = "";
	tab2[2] = "";
	tab2[3] = "";
	tab2[4] = "";
	tab2[5] = "";
	tab2[6] = "";
	tab2[7] = "";
	tab2[8] = "";
	tab2[9] = "";
	tab2[10] = "";
	tab2[11] = "";
	tab2[12] = NULL;
	
	printf("%d\n", ft_any(tab1, &ft_char));
	printf("%d\n", ft_any(tab2, &ft_char));
	return (0);
} */