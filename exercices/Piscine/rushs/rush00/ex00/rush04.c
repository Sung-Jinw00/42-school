/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 09:53:23 by locagnio          #+#    #+#             */
/*   Updated: 2024/09/07 17:06:57 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void ft_conditions(int x, int y, int height, int length)
{
	if ((length == 0 && height == 0) || (x > 0 && y > 0 && length == x && height == y))
			ft_putchar('A');
		else if ((length == x && height == 0) || (length == 0 && height == y))
			ft_putchar('C');
		else if (((height == 0 || height == y) && !(length == 0 || length == x))
		|| (!(height == 0 || height == y) && (length == 0 || length == x)))
			ft_putchar('B');
		else
			ft_putchar(' ');
}

int rush(int x, int y)
{
	int length;
	int height;

	length = 0;
	height = 0;
	x -= 1;
	y -= 1;
	while(length <= x && height <= y)
	{
		ft_conditions(x, y, height, length);
		length ++;
		if (length == x + 1 && height != y)
		{
			ft_putchar('\n');
			length = 0;
			height++;
		}
	}
	return (0);
}