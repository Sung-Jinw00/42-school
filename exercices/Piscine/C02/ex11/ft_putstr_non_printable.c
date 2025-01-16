/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 10:46:06 by locagnio          #+#    #+#             */
/*   Updated: 2024/10/02 16:15:39 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr_non_printable(char *str)
{
	int		i;
	char	*hexa;

	i = 0;
	hexa = "0123456789abcdef";
	while (str[i] != '\0')
	{
		if (str[i] < 32 || str[i] == 127)
		{
			ft_putchar('\\');
			ft_putchar(hexa[(unsigned char)str[i] / 16]);
			ft_putchar(hexa[(unsigned char)str[i] % 16]);
		}
		else
			ft_putchar(str[i]);
		i++;
	}
}

/* int main(void)
{
	char str[] = "He\rllo\n W\torld.";

	ft_putstr_non_printable(str);
	return(0);
} */