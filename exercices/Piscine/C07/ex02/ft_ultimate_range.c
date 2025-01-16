/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 14:04:21 by locagnio          #+#    #+#             */
/*   Updated: 2024/09/16 11:21:18 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
/* #include <stddef.h>
#include <stdio.h>
#include <unistd.h> */

int	ft_ultimate_range(int **range, int min, int max)
{
	int	len_range;
	int	i;

	i = 0;
	len_range = max - min;
	if (len_range <= 0)
	{
		range = NULL;
		return (0);
	}
	range[0] = (int *)malloc(sizeof(int) * len_range);
	if (!range)
	{
		range = NULL;
		return (-1);
	}
	while (min < max)
	{
		range[0][i] = min;
		i++;
		min++;
	}
	return (len_range);
}

/* int	main(void)
{
	int **range;
	int max = 100;

	range = malloc(sizeof(int *));
	printf("%d\n", ft_ultimate_range(range, 1, max));
	free(range);
	return (0);
} */
