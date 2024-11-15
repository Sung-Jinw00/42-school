/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bonus_point.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 15:50:36 by locagnio          #+#    #+#             */
/*   Updated: 2024/11/14 16:10:08 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/*  . gerer n'importe quelle combinaison des flags (-0.) et la taille minimale des convertion */

void	ft_string_point3(int i, int nb, t_struct v, va_list args)
{
	if (v.str[i] == 'p')//si je dois ecrire un pointeur
	{
		v.arg = va_arg(args, void *);
		if (!v.arg)//si j'ai un pointeur null
		{
			nb -= ft_strlen("(nil)");//j'enleve la longueur de (nil)
			while (nb-- > 0)
				write(1, " ", 1);
			write(1, "(nil)", 5);//j'ecris l'erreur
			return ;
		}
		v.arg = print_ptr((size_t)v.arg, -1);//sinon, je converti mon pointeur en hexa
		nb -= ft_strlen((const char *)v.arg);//j'enleve la len de la chaine
		while (nb-- > 0)
			write(1, " ", 1);
		ft_putstr_fd((char *)v.arg, 1);//j'ecris mon pointeur
	}
}

void	ft_string_point2(int i, int nb, t_struct v, va_list args)
{
	int	k;

	k = 0;
	if (v.str[i] == 's')//si c'est une chaine de characteres
	{
		v.arg = va_arg(args, char *);
		if (!v.arg)//si j'ai une chaine vide
		{
			nb -= ft_strlen("(null)");//j'enleve la longueur de (null)
			while (nb-- > 0)
				write(1, " ", 1);
			write(1, "(null)", 6);//j'ecris l'erreur
			return ;
		}
		nb -= ft_strlen((const char *)v.arg);//sinon j'enleve la len de la chaine
		while (nb-- > 0)
			write(1, " ", 1);
		while (((char *)v.arg)[k])//et je l'ecris
			write (1, &((char *)v.arg)[k++], 1);
	}
	else
		ft_string_point3(i, nb, v, args);
}


void	ft_string_point(int i, int nb, t_struct v, va_list args)
{
	int	k;
	long long value;

	value = 0;
	k = 0;
	if (v.str[i] == 'X' || v.str[i] == 'x')//si je veux un nombre en hexadecimal
	{
		value = va_arg(args, int);
		if (v.str[i] == 'X')//je choisis comment je vais ecrire en hexadecimal
			v.arg = ft_itoa_base(value, "0123456789ABCDEF");
		else
			v.arg = ft_itoa_base(value, "0123456789abcdef");
		nb -= ft_strlen((const char *)v.arg);//j'enleve la longueur de la chaine
		while (nb-- > 0)
			write(1, "0", 1);
		while (((char *)v.arg)[k])//j'ecris la chaine
			write (1, &((char *)v.arg)[k++], 1);
	}
	else
		ft_string_point2(i, nb, v, args);
}

void	field_width_point2(int i, int nb, t_struct v, va_list args)
{
	long value;

	value = 0;
	if (v.str[i] == 'u')//si c'est un entier non signé
	{
		value = va_arg(args, int);
		if (value < 0)//je choisi le nombre que je vais ecrire
			*(unsigned long *)v.arg = (unsigned long)(value + (long)INT_MAX * 2 + 2);
		else
			*(unsigned long *)v.arg = (unsigned long)value;
		nb -= ft_digits(*(int *)v.arg);//j'enleve la longueur du nombre
		while (nb-- > 0)
			write(1, "0", 1);
		ft_putunbr_fd(-1, *(unsigned long *)v.arg, 1);//j'ecris le nombre
	}
	else if (v.str[i] == 'p' || v.str[i] == 'x' || v.str[i] == 'X' || v.str[i] == 's')//si c'est une chaine de characteres (en puissance)
		ft_string_point(i, nb, v, args);
}

void	field_width_point(int i, int nb, t_struct v, va_list args)
{
	if (v.str[i] == 'c' || v.str[i] == '%')//si c'est un caractere
	{
		nb -= 1;//j'enleve un espace
		while (nb-- > 0)
			write(1, " ", 1);
			*(char *)v.arg = (char)va_arg(args, int);
		write (1, &*(char *)v.arg, 1);//j'ajoute le caractere
	}
	else if (v.str[i] == 'd' || v.str[i] == 'i')//si c'est des entiers
	{
		*(int *)v.arg = va_arg(args, int);
		nb -= ft_digits(*(int *)v.arg);//j'enleve la longueur de mon chiffre
		if (*(int *)v.arg < 0)
		{
			write(1, "-", 1);
			*(int *)v.arg = -(*(int *)v.arg);
			nb--;
		}
		while (nb-- > 0)
			write(1, "0", 1);
		ft_putnbr_fd(-1, *(int *)v.arg, 1);//j'ecris mon chiffre
	}
	else
		field_width_point2(i, nb, v, args);
}

/* - avec "." : %.(nombre)(suffixe) affiche (nombre) de chiffres apres la
			virgule (a besoin d'un nombre apres pour fonctionner); */
int	ft_bonus_point(int i, int *count, t_struct v, va_list args)
{
	int j;
	int nb;

	nb = 0;
	j = i + 1;
	if (v.str[i] != '.')//si j'ai que des chiffres
	{
		while (v.str[j] >= '0' || v.str[j] <= '9')
			j++;
		if (v.str[j] == '%')
		{
			write(1, &v.str[j], 1);
			*count += 1;
		}
		else
		{
			nb = ft_atoi(v.str + i);//j prends la valeur du nombre
			if ((v.str[i - 1] != '+'))
				nb--;
			*count += nb;//j'ajoute le nombre de caracteres que je vais ecrire au compteur
			field_width_point(j, nb, v, args);//j'ecris et compte en fonction du type
		}
	}
	return (j + 1);
}
//ex : printf("|%-10d|\n", 42)     =     "|42        |"

/*		- je peux faire des combinaisons avec ".", cf ci-dessous;

			* si j'ai une chaine de characteres, (nombre) determine le nombre de caracteres
			a afficher;
			*si j'essai avec des entiers, le numero affiche des zeros supplementaires si la
			taille donne par (nombre) n'est pas remplie (fonctionne comme '0');


	. gerer tous les flags (# +)
		- avec "+" : %+(nombre)(suffixe) affiche explicitement le signe d'un nombre (signés);
		
		- avec " " : % (nombre)(suffixe) affiche un espace devant un nombre (signé) positif
			sans signe '+' ou '-';
		
		- avec "#" : %#(nombre)(e/g/suffixe)
			* si j'ai un 'o', je dois rajouter un 0 devant mon chiffre pour specifier la
			base octale
			* si j'ai un 'x' ou un 'X', je dois rajouter un 0x ou 0X devant mon chiffre
			pour specifier la base hexadecimale.
			* si j'ai un 'e', un 'g', ou un 'f', je dois garantir d'afficher au moins 1
				nombre apres la virgule (float, double, long double);
			* n'a pas d'effets sur %d, %i, %c et %s;*/