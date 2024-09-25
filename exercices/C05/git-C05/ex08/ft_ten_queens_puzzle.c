/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 10:15:05 by locagnio          #+#    #+#             */
/*   Updated: 2024/09/11 21:00:02 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(int *position)
{
	int	i;
	int	tempc;

	i = 0;
	while (i <= 9)
	{
		tempc = position[i] + '0';
		write(1, &tempc, 1);
		i++;
	}
	write(1, "\n", 1);
}

int	check(int *position, int col)
{
	int	n;

	n = 1;
	while (col - n >= 0)
	{
		if ((position[col - n] == position[col])
			|| ((position[col - n] == position[col] + n))
			|| ((position[col - n] == position[col] - n)))
			return (0);
		n++;
	}
	return (1);
}

int	ft_recursive_verif(int *position, int col)
{
	int	i;
	int	compteur;

	i = 0;
	compteur = 0;
	while (i < 10)
	{
		position[col] = i;
		if (check(position, col))
		{
			if (col == 9)
			{
				ft_putchar(position);
				compteur++;
			}
			else
				compteur += ft_recursive_verif(position, col + 1);
		}
		i++;
	}
	return (compteur);
}

int	ft_ten_queens_puzzle(void)
{
	int	position[10];
	int	col;
	int	compteur;

	compteur = 0;
	col = 0;
	return (ft_recursive_verif(position, col));
}

/*#include <stdio.h>
int	main(void)
{
	printf("%d\n", ft_ten_queens_puzzle());
	return (0);
}*/
