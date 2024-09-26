/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 11:15:29 by locagnio          #+#    #+#             */
/*   Updated: 2024/09/26 16:27:22 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	if (str[0] != '9' - i + 1)
		write(1, ", ", 2);
}

void	ft_rev_sort(char *tab, int len)
{
	int	max;
	int	temp;

	max = 0;
	temp = len;
	while (temp > 0 && tab[temp] - 1 == tab[temp - 1])
		temp--;
	tab[temp - 1]++;
	while (temp <= len)
	{
		tab[temp] = '0';
		temp++;
	}
}

void	ft_sort_int_tab(char *tab, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (i <= size)
	{
		while (j <= size)
		{
			if (tab[i] >= tab[j])
			{
				tab[j] = tab[i] + 1;
				i = 0;
				j = 1;
			}
			j++;
		}
		i++;
		j = i + 1;
	}
}

void	ft_print_combn(int n)
{
	char	tab[10];
	int		len;

	len = 0;
	while (n > 0)
	{
		tab[len] = '0';
		len++;
		n--;
	}
	tab[len] = 0;
	len--;
	while (tab[0] != '9' - len + 1 && tab[len] != ':')
	{
		ft_sort_int_tab(tab, len);
		ft_putstr(tab);
		if (tab[len] == '9' && tab[0] != '9' - len)
			ft_rev_sort(tab, len);
		tab[len]++;
	}
	write(1, "\n", 1);
}

/* #include <stdio.h>
int	main(void)
{
	printf("combinaisons d'1 nombre :\n");
	ft_print_combn(1);
	write(1, "\n", 1);
	printf("combinaisons de 2 nombres :\n");
	ft_print_combn(2);
	write(1, "\n", 1);
	printf("combinaisons de 3 nombres :\n");
	ft_print_combn(3);
	write(1, "\n", 1);
	printf("combinaisons de 4 nombres :\n");
	ft_print_combn(4);
	write(1, "\n", 1);
	printf("combinaisons de 5 nombres :\n");
	ft_print_combn(5);
	write(1, "\n", 1);
	printf("combinaisons de 6 nombres :\n");
	ft_print_combn(6);
	write(1, "\n", 1);
	printf("combinaisons de 7 nombres :\n");
	ft_print_combn(7);
	write(1, "\n", 1);
	printf("combinaisons de 8 nombres :\n");
	ft_print_combn(8);
	write(1, "\n", 1);
	printf("combinaisons de 9 nombres :\n");
	ft_print_combn(9);
	return (0);
} */
