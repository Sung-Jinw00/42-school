/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 17:02:46 by locagnio          #+#    #+#             */
/*   Updated: 2024/11/12 18:17:57 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printflibft.h"

int	ft_digits(long nbr)
{
	int count;

	count = 1;
	while (nbr >= 10)
	{
		nbr /= 10;
		count++;
	}
	return (count);
}

int	ft_adressedemorts(const char *str, int i, void *arg, va_list args)
{
	char	ptr[16];
	int		i;
	char	*hexa;
	size_t adr;

	adr = (size_t)va_arg(args, void *);
	hexa = "0123456789ABCDEF";
	i = 2;
	while (adr > 0)
	{
		adr /= 16;
		i++;
	}
	i--;
	return (i);
}

int	ft_lenandprint(const char *str, int i, void *arg, va_list args)
{
	int j;

	j = 0;
	if (str[i] == '-')
		ft_redpill(str, i, arg, args);
	if (str[i] == 'c' || str[i] == '%')
		return (1);
	else if (str[i] == 's')
	{
		arg = va_arg(args, char *);
		return (ft_strlen((const char *)arg));
	}
	else if (str[i] == 'd' || str[i] == 'i' || str[i] == 'u')
	{
		*(int *)arg = va_arg(args, int);
		return (ft_digits((long)arg));
	}
	else if (str[i] == 'p')
		return(ft_adressedemorts(str, i, arg, args));
	else
	{
		*(int *)arg = va_arg(args, int);
		arg = ft_itoa_base(*(int *)arg, "0123456789ABCDEF");
		return (ft_digits((long)arg));
	}
}

void	ft_flags(const char *str, int i, void *arg, va_list args)
{
	int j;
	long nbr;
	int len_elem;

	j = 0;
	nbr = 0;
	i++;
	len_elem = 0;
	nbr = ft_miniatoi(str + i);//je recupere le chiffre apres -
	i += ft_digits(nbr);//je regarde combien de chiffres ce nombre a pour incrementer i
	if (str[i] == 'c' || str[i] == 's' || str[i] == 'd' || str[i] == 'i'
		|| str[i] == 'u' || str[i] == 'x' || str[i] == 'X' || str[i] == '%')
		len_elem = ft_lenandprint(str, i, arg, args);//je prends la len de mon caractere ou chiffre
	//else if (str[i] == 'p')
	if (str[i] == '0')
	{
		while ((nbr--) - len_elem)//tant que mon chiffre - la longueur de mon caractere ou chiffre >= 0
			write(1, "0", 1);//j'ecris des zeros
		ft_redpill(str, i, arg, args);//et j'ecris mon chiffre;
	}
	else if (str[i] == '-')
	{
		while ((nbr--) - len_elem)//tant que mon chiffre - la longueur de mon caractere ou chiffre >= 0
			write(1, " ", 1);//j'ecris des espaces
	}	
}
