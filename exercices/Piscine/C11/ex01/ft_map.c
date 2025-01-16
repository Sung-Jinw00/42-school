/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 12:27:00 by locagnio          #+#    #+#             */
/*   Updated: 2024/09/22 13:17:41 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_strdup(int *src, int length)
{
	int	*cpy;
	int	i;

	i = 0;
	cpy = (int *)malloc(sizeof(int) * (length));
	if (!cpy)
		return (NULL);
	while (i < length)
	{
		cpy[i] = src[i];
		i++;
	}
	return (cpy);
}

/* int	ft_42(int val)
{
	val += 42;
	return (val);
}

#include <stdio.h> */

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	i;
	int	*cpy;

	i = 0;
	cpy = ft_strdup(tab, length);
	while (i < length)
	{
		cpy[i] = f(tab[i]);
		i++;
	}
	return (cpy);
}

/* #include <limits.h>

int	main(void)
{
	int tab[5] = {INT_MIN, -42, -0, 42, INT_MAX -42};
	int length = 5;
	int *cpy;
	int i = 0;

	cpy = ft_map(tab, length, &ft_42);
	printf("adresse de tab : %p\n", tab);
	while (i < length)
	{
		printf("%d\n", tab[i]);
		i++;
	}
	i = 0;
	printf("adresse de cpy : %p\n", cpy);
	while (i < length)
	{
		printf("%d\n", cpy[i]);
		i++;
	}
	free(cpy);
	return (0);
} */