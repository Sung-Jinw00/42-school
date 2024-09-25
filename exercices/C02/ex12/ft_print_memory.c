/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 19:55:35 by locagnio          #+#    #+#             */
/*   Updated: 2024/09/20 21:11:41 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_print_cont(int adr_cont)
{
	char *hexa;
	char addr_cont[33];
	int i;
	
	hexa = "0123456789abcdef";
	i = 0;
	while (i < 32)
	{
		addr_cont[i] = '0';
		i++;
	}
	addr_cont[i] = 0;
	i--;
	while (addr_cont[i] && i >= 0)
	{
		addr_cont[i] = hexa[adr_cont % 16];
		adr_cont /= 16;
		i--;
	}
	while (i >= 0)
	{
		addr_cont[i] = '0';
		i--;
	}
	printf("%s\n", addr_cont);
}

void	ft_print_add(size_t adr, char *addr_hexa)
{
	char *hexa;
	int i;
	
	hexa = "0123456789abcdef";
	i = 0;
	while (i < 16)
	{
		addr_hexa[i] = '0';
		i++;
	}
	addr_hexa[i] = 0;
	i--;
	while (addr_hexa[i] && i >= 0)
	{
		addr_hexa[i] = hexa[adr % 16];
		adr /= 16;
		i--;
	}
	while (i >= 0)
	{
		addr_hexa[i] = '0';
		i--;
	}
}

int ft_print_memory(void *addr, unsigned int size)
{
	char addr_hexa[17];
	size_t adr_add;
	int adr_cont;
	
	adr_add = (size_t)addr;
	printf("%zu\n", adr_add);
	ft_print_add(adr_add, addr_hexa);
	printf("%s\n", addr_hexa);
	printf("%p\n", addr);
	adr_cont = (long int)addr;
	ft_print_cont(adr_cont);
	

	return (size * 0);
}

int main(void)
{
	ft_print_memory("Hello Word", 11);
	return (0);
}