/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 14:58:28 by locagnio          #+#    #+#             */
/*   Updated: 2024/09/26 19:31:51 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_atoi_base(char *str, char *base);
int	ft_error(char *base);

char	*ft_rev_int_tab(char *tab, int size)
{
	int	i;
	int	k;
	int	n;
	int	sign;

	i = 0;
	n = 1;
	sign = 0;
	if (tab[0] == '-')
	{
		i = 1;
		n = 0;
		sign = 1;
	}
	while (i < (size / 2) + sign)
	{
		k = tab[i];
		tab[i] = tab[size - i - n];
		tab[size - i - n] = k;
		i++;
	}
	return (tab);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_putnbr_base(char *nbr_base_to, int nbr, char *base, int i)
{
	long	nb;
	int		len_base;

	nb = nbr;
	len_base = ft_strlen(base);
	if (nbr == 0)
	{
		nbr_base_to[0] = 48;
		return (nbr_base_to);
	}
	if (nb < 0)
	{
		nbr_base_to[0] = '-';
		nb = -nb;
		i++;
	}
	if (nb >= len_base)
		ft_putnbr_base(nbr_base_to, nb / len_base, base, i + 1);
	nbr_base_to[i] = base[nb % len_base];
	return (nbr_base_to);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		nbr_decimal;
	char	*nbr_base_to;
	int		j;

	j = 0;
	nbr_decimal = 0;
	if (ft_error(base_from) && ft_error(base_to))
	{
		nbr_base_to = (char *)malloc(sizeof(char) * 256);
		while (j < 256)
			nbr_base_to[j++] = 0;
		nbr_decimal = ft_atoi_base(nbr, base_from);
		nbr_base_to = ft_putnbr_base(nbr_base_to, nbr_decimal, base_to, 0);
		nbr_base_to = ft_rev_int_tab(nbr_base_to, ft_strlen(nbr_base_to));
	}
	else
		return (NULL);
	return (nbr_base_to);
}

/* #include <stddef.h>
#include <stdio.h>
#include <unistd.h>

int main(void)
{
	char nbr[] = "";
	char base_from[] = "01";
	char base_to[] = "01";
	char *nbr_base_to;

	nbr_base_to = ft_convert_base(nbr, base_from, base_to);
	printf("%s\n", nbr_base_to);
	free(nbr_base_to);
	return (0);
} */
