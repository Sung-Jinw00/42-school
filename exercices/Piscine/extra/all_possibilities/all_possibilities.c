/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_possibilities.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 13:39:57 by marvin            #+#    #+#             */
/*   Updated: 2025/04/14 18:58:53 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_recursive_factorial(int nb)
{
	if (nb < 0)
		return (0);
	if (nb == 0 || nb == 1)
		return (1);
	return (nb * ft_recursive_factorial(nb - 1));
}

int	if_charset(int val, int *charset, int k)
{
	int	j;

	j = -1;
	while (charset[++j] && j < k)
		if (val == charset[j])
			return (1);
	return (0);
}

int	*ft_strdup(int *src, int size)
{
	int	*cpy;
	int	len_src;
	int	i;

	len_src = size + 1;
	cpy = (int *)malloc(sizeof(int) * len_src);
	if (!cpy)
		return (NULL);
	i = -1;
	while (++i < len_src)
		cpy[i] = src[i];
	return (cpy);
}

int	**all_possibilities(int min, int max)
{
	int	**possibilities;
	int	combinaisons;
	int	i;
	int	j;
	int	k;
	int	save_min;
	int	*solution;

	i = 0;
	j = 0;
	k = max - min + 1;
	save_min = min;
	combinaisons = ft_recursive_factorial(k);
	possibilities = malloc(sizeof(int *) * combinaisons);
	possibilities[i] = malloc(sizeof(int) * k);
	while (min <= max)
		possibilities[i][j++] = min++;
	min = save_min;
	while (++i < combinaisons)
	{
		k = max - min;
		solution = malloc(sizeof(int) * k);
		solution = ft_strdup(possibilities[i - 1], k);
		solution[k]++;
		while (if_charset(solution[k], solution, k))  
			solution[k]++;
		while (solution[k] > max)
		{
			solution[k--] = min;
			solution[k]++;
			while (if_charset(solution[k], solution, k))
				solution[k]++;
		}
		k++;
		while (k - 1 < max - min)
		{
			while (if_charset(solution[k], solution, k))
				solution[k]++;
			k++;                                        
		}
		possibilities[i] = ft_strdup(solution, k + 1);
		free(solution);
	}
	return (possibilities);
}

#include <stdio.h>

int	main(int ac, char **av)
{
	int	min;
	int	max;
	int	**combinaisons;
	int	i = 0, j;

	min = 1;
	max = av[1][0] - 48;
	i = 0, j = 0;
	combinaisons = all_possibilities(min, max);
	while (i < ft_recursive_factorial(max - min + 1))
	{
		printf("sol %d : ", i + 1);
		while (j < max)
		{
			if (!(j < max - 1))
				printf("%d", combinaisons[i][j++]);
			else
				printf("%d, ", combinaisons[i][j++]);
		}
		i++;
		j = 0;
		printf("\n");
	}
	free(combinaisons);
	return (ac * 0);
}
