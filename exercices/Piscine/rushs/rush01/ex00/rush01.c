/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 13:46:05 by locagnio          #+#    #+#             */
/*   Updated: 2024/09/17 11:42:30 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	ft_error(void);
int	start_check(int *conditions, int *answer, int cases, int val_max);

int	*ft_write_malloc(int *cond_gril, char **av, int indice)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (av[1][i] && i < indice * 8 - 1)
	{
		cond_gril[j] = av[1][i] - 48;
		j++;
		i += 2;
	}
	while (j < 32)
	{
		cond_gril[j] = 0;
		j++;
	}
	return (cond_gril);
}

void	ft_putstr(int *answer, int indice)
{
	int	i;

	i = 0;
	while (answer[i] != '\0')
	{
		answer[i] += 48;
		write(1, &answer[i], 1);
		if (!((i + 1) % indice == 0))
			write(1, " ", 1);
		if ((i + 1) % indice == 0)
			write(1, "\n", 1);
		i++;
	}
}

int	ft_recursive_verif(int *answer, int cases, int indice, int *cond_gril)
{
	int	i;
	int	max_cases;

	max_cases = indice * indice;
	i = indice;
	while (cases <= max_cases)
	{
		while (i >= 1)
		{
			answer[cases] = i;
			if (start_check(cond_gril, answer, cases, indice))
			{
				if (cases == max_cases - 1)
				{
					ft_putstr(answer, indice);
					return (1);
				}
				else
					ft_recursive_verif(answer, cases + 1, indice, cond_gril);
			}
			i--;
		}
		cases = max_cases + 1;
	}
	return (0);
}

int	rush01(char **av, int indice)
{
	int	*answer;
	int	*cond_gril;
	int	cases;
	int	i;
	int	j;

	cases = 0;
	i = 0;
	j = 0;
	answer = (int *)malloc(sizeof(int) *((indice * indice) + 1));
	if (!answer)
		return (0);
	cond_gril = (int *)malloc(sizeof(int) * 32);
	if (!cond_gril)
		return (0);
	cond_gril = ft_write_malloc(cond_gril, av, indice);
	i = ft_recursive_verif(answer, cases, indice, cond_gril);
	free(answer);
	free(cond_gril);
	if (i == 0)
		ft_error();
	return (0);
}
