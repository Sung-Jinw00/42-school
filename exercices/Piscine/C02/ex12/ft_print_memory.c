/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 19:55:35 by locagnio          #+#    #+#             */
/*   Updated: 2024/10/23 15:31:32 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	print_txt(char *txt)
{
	int	i;

	i = 0;
	while (i <= 15 && txt[i])
	{
		if (txt[i] < 32 || txt[i] == 127)
			write(1, ".", 1);
		else
			write(1, &txt[i], 1);
		i++;
	}
}

void	print_sxtnchar(char *txt, char *hexa)
{
	int	i;

	i = 0;
	while (i < 16 && txt[i])
	{
		write(1, &hexa[txt[i] / 16], 1);
		write(1, &hexa[txt[i] % 16], 1);
		i++;
		if (i % 2 == 0)
			write(1, " ", 1);
	}
	while (i < 16)
	{
		write(1, "  ", 2);
		i++;
		if (i % 2 == 0)
			write(1, " ", 1);
	}
	write(1, " ", 1);
}

void	print_add(size_t adr, char *hexa)
{
	char	addmem[19];
	int		i;

	i = 15;
	addmem[18] = 0;
	addmem[17] = ' ';
	addmem[16] = ':';
	while (adr > 0)
	{
		addmem[i] = hexa[adr % 16];
		adr /= 16;
		i--;
	}
	while (i >= 0)
	{
		addmem[i] = '0';
		i--;
	}
	ft_putstr(addmem);
}

void	ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;
	char			*memadd;
	char			*hexa;
	size_t			adr;

	hexa = "0123456789abcdef";
	i = 0;
	if (size == 0)
		return ;
	memadd = (char *)addr;
	while (memadd[i] && i <= size)
	{
		adr = (size_t)addr + i;
		print_add(adr, hexa);
		print_sxtnchar(memadd + i, hexa);
		print_txt(memadd + i);
		write (1, "\n", 1);
		i += 16;
	}
}

/* int main(void)
{
	ft_print_memory("Bonjour les amis, c'est fou tout ce qu'on peut faire avec\
	 print_memory... lol lol lol.          ....xxxxo...........xxxx...........\
	 ox 	xxxoo.....o....xxxx.o...o.........o..........o.o.......o.........o\
	 .....o...", 208);
	return (0);
} */
