/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 20:46:57 by locagnio          #+#    #+#             */
/*   Updated: 2024/11/23 19:14:45 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_char(char c, t_struct v, int i, int *count)
{
	if (c == 0 && v.nb1 == 0)//si c vaut zero et que j'ai pas de champ
		*count += 1;
	else if (v.nb1 > 0)//si j'ai un champ
	{
		*count += v.nb1;//j'ajoute la longueur du champ
		if (srch_flag(v.flags, '-') && c != 0)//j'ecris si j'ai un -
		{
			write(1, &c, 1);
			v.nb1--;
		}
		else if (c != 0)//sinon si je peux ecrire le char je lui laisse une place
			v.nb1--;
		while (v.nb1-- > 0)//j'ecris les espaces
			write(1, " ", 1);
		if (c != 0 && !srch_flag(v.flags, '-'))//si j'avais pas de -, j'ecris le caractere
			write(1, &c, 1);
	}
	else
	{
		if (c != 0)
			write(1, &c, 1);
		*count += 1;	
	}
}

void	print_str_if_field(t_struct v, int print_chars, char *str, int *count)
{
	*count += v.nb1;//j'ajoute la longueur du champ
	if (srch_flag(v.flags, '-'))//j'ecris si j'ai un -
		ft_putstr(str, count, print_chars);
	v.nb1 -= print_chars;//j'enleve la longeur a imprimer
	while (v.nb1-- > 0)//j'ecris les espaces
		write(1, " ", 1);
	if (!srch_flag(v.flags, '-'))//si j'avais pas de -, j'ecris la chaine
		ft_putstr(str, count, print_chars);
}

void	ft_print_str(char *str, t_struct v, int i, int *count)
{
	int	print_chars;

	if (!str)
	{
		if (srch_flag(v.flags, '.') && v.nb2 <= 5)//si j'ai un point et pas assez de place pour ecrire null
			str = "";
		else//si j'ai assez de place
			str = "(null)";
	}
	if (ft_strcmp(str, "(null)") && v.nb2 <= 5)//si je peux pas ecrire (null)
		print_chars = 0;
	else if (srch_flag(v.flags, '.') && v.nb2 < (int)ft_strlen((const char *)str))//si le nombre apres le point est plus petit que ma len
		print_chars = v.nb2;//ma limite sera le nombre demander
	else
		print_chars = (int)ft_strlen((const char *)str);//sinon ce sera la len
	if (v.nb1 - print_chars > 0)//si j'ai un champ
		print_str_if_field(v, print_chars, str, count);
	else
		ft_putstr(str, count, print_chars);
	
}

void	ft_null_ptr(t_struct v, int *count)
{
	char	*nil;

	nil = "(nil)";
	if (v.nb1 - 5 > 0 && ft_strcmp(nil, "(nil)"))//si j'ai un champ
	{
		*count += v.nb1;//j'ajoute la longueur du champ
		if (srch_flag(v.flags, '-'))//j'ecris si j'ai un -
			ft_putstr(nil, count, 5);
		v.nb1 -= 5;//j'enleve la longeur a imprimer
		while (v.nb1-- > 0)//j'ecris les espaces
			write(1, " ", 1);
		if (!srch_flag(v.flags, '-'))//si j'avais pas de -, j'ecris la chaine
			ft_putstr(nil, count, 5);
	}
	else
		ft_putstr(nil, count, 5);
}

int	ft_ptrlen(size_t ptr)
{
	int count;

	count = 0;
	while (ptr >= 16)
	{
		ptr /= 16;
		count++;
	}
	return (count);
}

void	print_ptr_if_0(t_struct v, int *count, int ptr_digits)
{
	if (srch_flag(v.flags, '0') && (v.nb1 - 2 - ptr_digits) > v.zeros)//si j'ai plus de zeros avec le champ
		v.zeros = v.nb1 - 2 - ptr_digits;//j'actualise ma data de zeros
	*count += (v.zeros + ptr_digits + 2);
	write(1, "0x", 2);
	while (v.zeros-- > 0)
		write(1, "0", 1);
}

void	print_ptr_if_else(t_struct v, int i, int *count, size_t ptr)
{
	int ptr_digits;

	ptr_digits = ft_ptrlen(ptr);
	if (srch_flag(v.flags, '-'))
	{
		*count += v.nb1;
		v.nb1 -= v.zeros + ptr_digits + 2;
		write(1, "0x", 2);
		while (v.zeros-- > 0)
			write(1, "0", 1);
		hexa_print(ptr, v, v.str[i]);
		while (v.nb1 > 0)
			write(1, " ", 1);
	}
	else
	{
		*count += v.nb1;
		v.nb1 -= v.zeros + ptr_digits + 2;
		while (v.nb1 > 0)
			write(1, " ", 1);
		write(1, "0x", 2);
		while (v.zeros-- > 0)
			write(1, "0", 1);
		hexa_print(ptr, v, v.str[i]);
	}
}

void	ft_print_ptr(size_t ptr, t_struct v, int i, int *count)
{
	int ptr_digits;
	int new_ptr_len;

	ptr_digits = 0;
	new_ptr_len = 0;
	if (!ptr)//si mon pointeur est nul, je gere le cas null
		ft_null_ptr(v, count);
	else//sinon
	{
		ptr_digits = ft_ptrlen(ptr);//je prends la len de mon chiffre
		if (srch_flag(v.flags, '.') && v.nb2 > ptr_digits);//si le chiffre apres '.' est plus grand
			v.zeros = v.nb2 - ptr_digits;//je prends les zeros en plus a imprimer
		if (v.zeros + ptr_digits + 2 > v.nb1 && !srch_flag(v.flags, '0'))//si j'ai un champ plus petit que la len totale de mon pointeur
			v.nb1 = v.zeros + ptr_digits + 2;
		if (srch_flag(v.flags, '0'))
		{
			print_ptr_if_0(v, count, ptr_digits);
			hexa_print(ptr, v, v.str[i]);
		}
		else
			print_ptr_if_else(v, i, count, ptr);
	}
}

void	ft_print_int(long nb, t_struct v, int i, int *count)
{
	ft_putnbr(count, nb);
}

void	ft_print_uns_int(long nb, t_struct v, int i, int *count)
{
	ft_putunbr(count, (unsigned long)nb);
}

void	ft_print_hexa(long nb, t_struct v, int i, int *count)
{
	while (nb > 16)
	{
		hexa_print((size_t)nb, v, v.str[i]);
		nb /= 16;
		*count += 1;
	}
}

void	ft_print_percent(char percent, t_struct v, int i, int *count)
{
	write(1, &percent, 1);
	*count += 1;
}