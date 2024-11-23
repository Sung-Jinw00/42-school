/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 16:05:11 by locagnio          #+#    #+#             */
/*   Updated: 2024/11/23 18:53:59 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parser(int i, int *count, t_struct v, va_list args)
{
	if (v.str[i] == 'c')
		ft_print_char((char)va_arg(args, int), v, i, count);
	else if (v.str[i] == 's')
		ft_print_str(va_arg(args, char *), v, i, count);
	else if (v.str[i] == 'p')
		ft_print_ptr((size_t)va_arg(args, void *), v, i, count);
	else if (v.str[i] == 'd' || v.str[i] == 'i')
		ft_print_int(va_arg(args, int), v, i, count);
	else if (v.str[i] == 'u')
		ft_print_uns_int(va_arg(args, int), v, i, count);
	else if (v.str[i] == 'x' || v.str[i] == 'X')
		ft_print_hexa(va_arg(args, int), v, i, count);
	else if (v.str[i] == '%')
		ft_print_percent('%', v, i, count);
}

int	parse_nd_flags(int i, int *count, t_struct v, va_list args)
{
	while (!standard_conds(v, i))
	{
		if ((v.str[i] >= '1' && v.str[i] <= '9')
			|| v.str[i] == '.')
			v = parse_nd_flags2(&i, v);
		else
		{
			v = flags(bonus_flag_finder(i, v), v);
			i += 1;
		}
	}
	v = flag_filter(i, v);
	parser(i, count, v, args);
	return (i);
}

int	print_this_bs(va_list args, t_struct v)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (v.str[i])
	{
		if (v.str[i] == '%')
			i = parse_nd_flags(i + 1, &count, v, args);
		else
		{
			write(1, &v.str[i], 1);
			count++;
		}
		i++;
	}
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list		args;
	t_struct	v;
	int			count;
	int			i;

	if (!str)
		return (0);
	i = 0;
	v.str = str;
	while (i < 7)
		v.flags[i++] = 0;
	v.nb1 = 0;
	v.nb2 = 0;
	v.zeros = 0;
	va_start(args, str);
	count = print_this_bs(args, v);
	va_end(args);
	return (count);
}

#include "../tests/tests.h"
#include <limits.h>

void	tests_point(void)
{
	printf("original : %d\n", printf("original :   \
	|%c|%s|%p|%u|%i|%d|%x|%X|%%|\n", 0, 0, 0, 0, 0, 0, 0, 0));
	printf("copie    : %d\n", ft_printf("copie    :   \
	|%c|%s|%p|%u|%i|%d|%x|%X|%%|\n", 0, 0, 0, 0, 0, 0, 0, 0));
	printf("\n\n\n");
}

#include <stdio.h>
int main(void)
{
	/* tests_c(0);
	tests_s(NULL);
	tests_d(-128);
	tests_i(-128);
	tests_u(-128);
	tests_x(-128);
	tests_x_maj(-128);
	tests_percent();
	tests_point(); */

	/* char c = 0;
	printf("//////////////////// Tests avec 'c' = 0 ////////////////////\n");
	printf("/////test sans flags/////\n");
	printf("original : %d\n", printf("original :   |%c|\n", c));
	fflush(stdout);
	printf("/////test de champ 10/////\n");
	printf("original : %d\n", printf("original :   |%10c|\n", c));
	fflush(stdout);
	printf("\n/////test de champ 10 avec '-'/////\n");
	printf("original : %d\n", printf("original :   |%-10c|\n", c));
	fflush(stdout);
	printf("\n/////test de champ 10 avec '0'/////\n");
	printf("original : %d\n", printf("original :   |%010c|\n", c));
	fflush(stdout);
	printf("\n/////test 10 chiffres apres la virgule /////\n");
	printf("original : %d\n\n", printf("original :   |%.10c|\n", c));
	fflush(stdout);
	printf("/////test de champ 3/////\n");
	printf("original : %d\n", printf("original :   |%3c|\n", c));
	fflush(stdout);
	printf("\n/////test de champ 3 avec '-'/////\n");
	printf("original : %d\n", printf("original :   |%-3c|\n", c));
	fflush(stdout);
	printf("\n/////test de champ 3 avec '0'/////\n");
	printf("original : %d\n", printf("original :   |%03c|\n", c));
	fflush(stdout);
	printf("\n/////test 3 chiffres apres la virgule /////\n");
	printf("original : %d\n\n", printf("original :   |%.3c|\n", c));
	fflush(stdout);
	printf("\n/////test de champ avec ' '/////\n");
	printf("original : %d\n", printf("original :   |% c|\n", c));
	fflush(stdout);
	printf("\n/////test de champ avec '+'/////\n");
	printf("original : %d\n", printf("original :   |%+c|\n", c));
	fflush(stdout);
	printf("\n/////test de champ avec '#'/////\n");
	printf("original : %d\n", printf("original :   |%#c|\n", c));
	fflush(stdout);
	printf("\n\n\n");
	c = 'l';
	printf("//////////////////// Tests avec 'c' = '%c' ////////////////////\n", c);
	printf("/////test sans flags/////\n");
	printf("original : %d\n", printf("original :   |%c|\n", c));
	fflush(stdout);
	printf("/////test de champ 10/////\n");
	printf("original : %d\n", printf("original :   |%10c|\n", c));
	fflush(stdout);
	printf("\n/////test de champ 10 avec '-'/////\n");
	printf("original : %d\n", printf("original :   |%-10c|\n", c));
	fflush(stdout);
	printf("\n/////test de champ 10 avec '0'/////\n");
	printf("original : %d\n", printf("original :   |%010c|\n", c));
	fflush(stdout);
	printf("\n/////test 10 chiffres apres la virgule /////\n");
	printf("original : %d\n\n", printf("original :   |%.10c|\n", c));
	fflush(stdout);
	printf("/////test de champ 3/////\n");
	printf("original : %d\n", printf("original :   |%3c|\n", c));
	fflush(stdout);
	printf("\n/////test de champ 3 avec '-'/////\n");
	printf("original : %d\n", printf("original :   |%-3c|\n", c));
	fflush(stdout);
	printf("\n/////test de champ 3 avec '0'/////\n");
	printf("original : %d\n", printf("original :   |%03c|\n", c));
	fflush(stdout);
	printf("\n/////test 3 chiffres apres la virgule /////\n");
	printf("original : %d\n\n", printf("original :   |%.3c|\n", c));
	fflush(stdout);
	printf("\n/////test de champ avec ' '/////\n");
	printf("original : %d\n", printf("original :   |% c|\n", c));
	fflush(stdout);
	printf("\n/////test de champ avec '+'/////\n");
	printf("original : %d\n", printf("original :   |%+c|\n", c));
	fflush(stdout);
	printf("\n/////test de champ avec '#'/////\n");
	printf("original : %d\n", printf("original :   |%#c|\n", c));
	fflush(stdout);
	printf("\n\n\n"); */

	/* char *s = 0;
	printf("//////////////////// Tests avec 's' = %s ////////////////////\n", s);
	printf("/////test sans flags/////\n");
	printf("original : %d\n", printf("original :   |%s|\n", s));
	fflush(stdout);
	printf("/////test de champ 10/////\n");
	printf("original : %d\n", printf("original :   |%10s|\n", s));
	fflush(stdout);
	printf("\n/////test de champ 10 avec '-'/////\n");
	printf("original : %d\n", printf("original :   |%-10s|\n", s));
	fflush(stdout);
	printf("\n/////test de champ 10 avec '0'/////\n");
	printf("original : %d\n", printf("original :   |%010s|\n", s));
	fflush(stdout);
	printf("\n/////test 10 chiffres apres la virgule /////\n");
	printf("original : %d\n\n", printf("original :   |%.10s|\n", s));
	fflush(stdout);
	printf("/////test de champ 3/////\n");
	printf("original : %d\n", printf("original :   |%3s|\n", s));
	fflush(stdout);
	printf("\n/////test de champ 3 avec '-'/////\n");
	printf("original : %d\n", printf("original :   |%-3s|\n", s));
	fflush(stdout);
	printf("\n/////test de champ 3 avec '0'/////\n");
	printf("original : %d\n", printf("original :   |%03s|\n", s));
	fflush(stdout);
	printf("\n/////test 3 chiffres apres la virgule /////\n");
	printf("original : %d\n\n", printf("original :   |%.3s|\n", s));
	fflush(stdout);
	printf("\n/////test de champ avec ' '/////\n");
	printf("original : %d\n", printf("original :   |% s|\n", s));
	fflush(stdout);
	printf("\n/////test de champ avec '+'/////\n");
	printf("original : %d\n", printf("original :   |%+s|\n", s));
	fflush(stdout);
	printf("\n/////test de champ avec '#'/////\n");
	printf("original : %d\n", printf("original :   |%#s|\n", s));
	fflush(stdout);
	printf("\n\n\n");
	s = "Yo boi";
	printf("//////////////////// Tests avec 's' = \"%s\" ////////////////////\n", s);
	printf("/////test sans flags/////\n");
	printf("original : %d\n", printf("original :   |%s|\n", s));
	fflush(stdout);
	printf("/////test de champ 10/////\n");
	printf("original : %d\n", printf("original :   |%10s|\n", s));
	fflush(stdout);
	printf("\n/////test de champ 10 avec '-'/////\n");
	printf("original : %d\n", printf("original :   |%-10s|\n", s));
	fflush(stdout);
	printf("\n/////test de champ 10 avec '0'/////\n");
	printf("original : %d\n", printf("original :   |%010s|\n", s));
	fflush(stdout);
	printf("\n/////test 10 chiffres apres la virgule /////\n");
	printf("original : %d\n\n", printf("original :   |%.10s|\n", s));
	fflush(stdout);
	printf("/////test de champ 3/////\n");
	printf("original : %d\n", printf("original :   |%3s|\n", s));
	fflush(stdout);
	printf("\n/////test de champ 3 avec '-'/////\n");
	printf("original : %d\n", printf("original :   |%-3s|\n", s));
	fflush(stdout);
	printf("\n/////test de champ 3 avec '0'/////\n");
	printf("original : %d\n", printf("original :   |%03s|\n", s));
	fflush(stdout);
	printf("\n/////test 3 chiffres apres la virgule /////\n");
	printf("original : %d\n\n", printf("original :   |%.3s|\n", s));
	fflush(stdout);
	printf("\n/////test de champ avec ' '/////\n");
	printf("original : %d\n", printf("original :   |% s|\n", s));
	fflush(stdout);
	printf("\n/////test de champ avec '+'/////\n");
	printf("original : %d\n", printf("original :   |%+s|\n", s));
	fflush(stdout);
	printf("\n/////test de champ avec '#'/////\n");
	printf("original : %d\n", printf("original :   |%#s|\n", s));
	fflush(stdout);
	printf("\n\n\n"); */


	char *ptr = 0;
	printf("//////////////////// Tests avec 'p' = %p ////////////////////\n", ptr);
	printf("/////test sans flags/////\n");
	printf("original : %d\n", printf("original :   |%p|\n", ptr));
	fflush(stdout);
	printf("/////test de champ 10/////\n");
	printf("original : %d\n", printf("original :   |%10p|\n", ptr));
	fflush(stdout);
	printf("\n/////test de champ 10 avec '-'/////\n");
	printf("original : %d\n", printf("original :   |%-10p|\n", ptr));
	fflush(stdout);
	printf("\n/////test de champ 10 avec '0'/////\n");
	printf("original : %d\n", printf("original :   |%010p|\n", ptr));
	fflush(stdout);
	printf("\n/////test 10 chiffres apres la virgule /////\n");
	printf("original : %d\n\n", printf("original :   |%.10p|\n", ptr));
	fflush(stdout);
	printf("/////test de champ 3/////\n");
	printf("original : %d\n", printf("original :   |%3p|\n", ptr));
	fflush(stdout);
	printf("\n/////test de champ 3 avec '-'/////\n");
	printf("original : %d\n", printf("original :   |%-3p|\n", ptr));
	fflush(stdout);
	printf("\n/////test de champ 3 avec '0'/////\n");
	printf("original : %d\n", printf("original :   |%03p|\n", ptr));
	fflush(stdout);
	printf("\n/////test 3 chiffres apres la virgule /////\n");
	printf("original : %d\n\n", printf("original :   |%.3p|\n", ptr));
	fflush(stdout);
	printf("\n/////test de champ avec ' '/////\n");
	printf("original : %d\n", printf("original :   |% p|\n", ptr));
	fflush(stdout);
	printf("\n/////test de champ avec '+'/////\n");
	printf("original : %d\n", printf("original :   |%+p|\n", ptr));
	fflush(stdout);
	printf("\n/////test de champ avec '#'/////\n");
	printf("original : %d\n", printf("original :   |%#p|\n", ptr));
	fflush(stdout);
	printf("\n\n\n");
	void *ptr2 = (void *)0x343545;
	printf("//////////////////// Tests avec 'p' = %p ////////////////////\n", ptr2);
	printf("/////test sans flags/////\n");
	printf("original : %d\n", printf("original :   |%p|\n", ptr2));
	fflush(stdout);
	printf("/////test de champ 20/////\n");
	printf("original : %d\n", printf("original :   |%20p|\n", ptr2));
	fflush(stdout);
	printf("\n/////test de champ 20 avec '-'/////\n");
	printf("original : %d\n", printf("original :   |%-20p|\n", ptr2));
	fflush(stdout);
	printf("\n/////test de champ 20 avec '0'/////\n");
	printf("original : %d\n", printf("original :   |%020p|\n", ptr2));
	fflush(stdout);
	printf("\n/////test 20 chiffres apres la virgule /////\n");
	printf("original : %d\n\n", printf("original :   |%.20p|\n", ptr2));
	fflush(stdout);
	printf("/////test de champ 3/////\n");
	printf("original : %d\n", printf("original :   |%3p|\n", ptr2));
	fflush(stdout);
	printf("\n/////test de champ 3 avec '-'/////\n");
	printf("original : %d\n", printf("original :   |%-3p|\n", ptr2));
	fflush(stdout);
	printf("\n/////test de champ 3 avec '0'/////\n");
	printf("original : %d\n", printf("original :   |%03p|\n", ptr2));
	fflush(stdout);
	printf("\n/////test 3 chiffres apres la virgule /////\n");
	printf("original : %d\n\n", printf("original :   |%.3p|\n", ptr2));
	fflush(stdout);
	printf("\n/////test de champ avec ' '/////\n");
	printf("original : %d\n", printf("original :   |% p|\n", ptr2));
	fflush(stdout);
	printf("\n/////test de champ avec '+'/////\n");
	printf("original : %d\n", printf("original :   |%+p|\n", ptr2));
	fflush(stdout);
	printf("\n/////test de champ avec '#'/////\n");
	printf("original : %d\n", printf("original :   |%#p|\n", ptr2));
	fflush(stdout);
	printf("\n\n\n");

	/* int d = 0;
	printf("//////////////////// Tests avec 'd' = %d ////////////////////\n", d);
	printf("/////test sans flags/////\n");
	printf("original : %d\n", printf("original :   |%d|\n", d));
	fflush(stdout);
	printf("/////test de champ 10/////\n");
	printf("original : %d\n", printf("original :   |%10d|\n", d));
	fflush(stdout);
	printf("\n/////test de champ 10 avec '-'/////\n");
	printf("original : %d\n", printf("original :   |%-10d|\n", d));
	fflush(stdout);
	printf("\n/////test de champ 10 avec '0'/////\n");
	printf("original : %d\n", printf("original :   |%010d|\n", d));
	fflush(stdout);
	printf("\n/////test 10 chiffres apres la virgule /////\n");
	printf("original : %d\n\n", printf("original :   |%.10d|\n", d));
	fflush(stdout);
	printf("/////test de champ 3/////\n");
	printf("original : %d\n", printf("original :   |%3d|\n", d));
	fflush(stdout);
	printf("\n/////test de champ 3 avec '-'/////\n");
	printf("original : %d\n", printf("original :   |%-3d|\n", d));
	fflush(stdout);
	printf("\n/////test de champ 3 avec '0'/////\n");
	printf("original : %d\n", printf("original :   |%03d|\n", d));
	fflush(stdout);
	printf("\n/////test 3 chiffres apres la virgule /////\n");
	printf("original : %d\n\n", printf("original :   |%.3d|\n", d));
	fflush(stdout);
	printf("\n/////test de champ avec ' '/////\n");
	printf("original : %d\n", printf("original :   |% d|\n", d));
	fflush(stdout);
	printf("\n/////test de champ avec '+'/////\n");
	printf("original : %d\n", printf("original :   |%+d|\n", d));
	fflush(stdout);
	printf("\n/////test de champ avec '#'/////\n");
	printf("original : %d\n", printf("original :   |%#d|\n", d));
	fflush(stdout);
	printf("\n\n\n");
	d = -123;
	printf("//////////////////// Tests avec 'd' = %d ////////////////////\n", d);
	printf("/////test sans flags/////\n");
	printf("original : %d\n", printf("original :   |%d|\n", d));
	fflush(stdout);
	printf("/////test de champ 10/////\n");
	printf("original : %d\n", printf("original :   |%10d|\n", d));
	fflush(stdout);
	printf("\n/////test de champ 10 avec '-'/////\n");
	printf("original : %d\n", printf("original :   |%-10d|\n", d));
	fflush(stdout);
	printf("\n/////test de champ 10 avec '0'/////\n");
	printf("original : %d\n", printf("original :   |%010d|\n", d));
	fflush(stdout);
	printf("\n/////test 10 chiffres apres la virgule /////\n");
	printf("original : %d\n\n", printf("original :   |%.10d|\n", d));
	fflush(stdout);
	printf("/////test de champ 3/////\n");
	printf("original : %d\n", printf("original :   |%3d|\n", d));
	fflush(stdout);
	printf("\n/////test de champ 3 avec '-'/////\n");
	printf("original : %d\n", printf("original :   |%-3d|\n", d));
	fflush(stdout);
	printf("\n/////test de champ 3 avec '0'/////\n");
	printf("original : %d\n", printf("original :   |%03d|\n", d));
	fflush(stdout);
	printf("\n/////test 3 chiffres apres la virgule /////\n");
	printf("original : %d\n\n", printf("original :   |%.3d|\n", d));
	fflush(stdout);
	printf("\n/////test de champ avec ' '/////\n");
	printf("original : %d\n", printf("original :   |% d|\n", d));
	fflush(stdout);
	printf("\n/////test de champ avec '+'/////\n");
	printf("original : %d\n", printf("original :   |%+d|\n", d));
	fflush(stdout);
	printf("\n/////test de champ avec '#'/////\n");
	printf("original : %d\n", printf("original :   |%#d|\n", d));
	fflush(stdout);
	printf("\n\n\n");
	d = 1;
	printf("//////////////////// Tests avec 'd' = %d ////////////////////\n", d);
	printf("/////test sans flags/////\n");
	printf("original : %d\n", printf("original :   |%d|\n", d));
	fflush(stdout);
	printf("/////test de champ 10/////\n");
	printf("original : %d\n", printf("original :   |%10d|\n", d));
	fflush(stdout);
	printf("\n/////test de champ 10 avec '-'/////\n");
	printf("original : %d\n", printf("original :   |%-10d|\n", d));
	fflush(stdout);
	printf("\n/////test de champ 10 avec '0'/////\n");
	printf("original : %d\n", printf("original :   |%+010d|\n", d));
	fflush(stdout);
	printf("\n/////test 10 chiffres apres la virgule /////\n");
	printf("original : %d\n\n", printf("original :   |%+.10d|\n", d));
	fflush(stdout);
	printf("/////test de champ 3/////\n");
	printf("original : %d\n", printf("original :   |%3d|\n", d));
	fflush(stdout);
	printf("\n/////test de champ 3 avec '-'/////\n");
	printf("original : %d\n", printf("original :   |%-3d|\n", d));
	fflush(stdout);
	printf("\n/////test de champ 3 avec '0'/////\n");
	printf("original : %d\n", printf("original :   |%03d|\n", d));
	fflush(stdout);
	printf("\n/////test 3 chiffres apres la virgule /////\n");
	printf("original : %d\n\n", printf("original :   |%.3d|\n", d));
	fflush(stdout);
	printf("\n/////test de champ avec ' '/////\n");
	printf("original : %d\n", printf("original :   |% d|\n", d));
	fflush(stdout);
	printf("\n/////test de champ avec '+'/////\n");
	printf("original : %d\n", printf("original :   |%+d|\n", d));
	fflush(stdout);
	printf("\n/////test de champ avec '#'/////\n");
	printf("original : %d\n", printf("original :   |%#d|\n", d));
	fflush(stdout);
	printf("\n\n\n"); */

	/* int i = 0;
	printf("//////////////////// Tests avec 'i' = %i ////////////////////\n", i);
	printf("/////test sans flags/////\n");
	printf("original : %d\n", printf("original :   |%i|\n", i));
	fflush(stdout);
	printf("/////test de champ 10/////\n");
	printf("original : %d\n", printf("original :   |%10i|\n", i));
	fflush(stdout);
	printf("\n/////test de champ 10 avec '-'/////\n");
	printf("original : %d\n", printf("original :   |%-10i|\n", i));
	fflush(stdout);
	printf("\n/////test de champ 10 avec '0'/////\n");
	printf("original : %d\n", printf("original :   |%010i|\n", i));
	fflush(stdout);
	printf("\n/////test 10 chiffres apres la virgule /////\n");
	printf("original : %d\n\n", printf("original :   |%.10i|\n", i));
	fflush(stdout);
	printf("/////test de champ 3/////\n");
	printf("original : %d\n", printf("original :   |%3i|\n", i));
	fflush(stdout);
	printf("\n/////test de champ 3 avec '-'/////\n");
	printf("original : %d\n", printf("original :   |%-3i|\n", i));
	fflush(stdout);
	printf("\n/////test de champ 3 avec '0'/////\n");
	printf("original : %d\n", printf("original :   |%03i|\n", i));
	fflush(stdout);
	printf("\n/////test 3 chiffres apres la virgule /////\n");
	printf("original : %d\n\n", printf("original :   |%.3i|\n", i));
	fflush(stdout);
	printf("\n/////test de champ avec ' '/////\n");
	printf("original : %d\n", printf("original :   |% i|\n", i));
	fflush(stdout);
	printf("\n/////test de champ avec '+'/////\n");
	printf("original : %d\n", printf("original :   |%+i|\n", i));
	fflush(stdout);
	printf("\n/////test de champ avec '#'/////\n");
	printf("original : %d\n", printf("original :   |%#i|\n", i));
	fflush(stdout);
	printf("\n\n\n");
	i = -1;
	printf("//////////////////// Tests avec 'i' = %i ////////////////////\n", i);
	printf("/////test sans flags/////\n");
	printf("original : %d\n", printf("original :   |%i|\n", i));
	fflush(stdout);
	printf("/////test de champ 10/////\n");
	printf("original : %d\n", printf("original :   |%10i|\n", i));
	fflush(stdout);
	printf("\n/////test de champ 10 avec '-'/////\n");
	printf("original : %d\n", printf("original :   |%-10i|\n", i));
	fflush(stdout);
	printf("\n/////test de champ 10 avec '0'/////\n");
	printf("original : %d\n", printf("original :   |%010i|\n", i));
	fflush(stdout);
	printf("\n/////test 10 chiffres apres la virgule /////\n");
	printf("original : %d\n\n", printf("original :   |%.10i|\n", i));
	fflush(stdout);
	printf("/////test de champ 3/////\n");
	printf("original : %d\n", printf("original :   |%3i|\n", i));
	fflush(stdout);
	printf("\n/////test de champ 3 avec '-'/////\n");
	printf("original : %d\n", printf("original :   |%-3i|\n", i));
	fflush(stdout);
	printf("\n/////test de champ 3 avec '0'/////\n");
	printf("original : %d\n", printf("original :   |%03i|\n", i));
	fflush(stdout);
	printf("\n/////test 3 chiffres apres la virgule /////\n");
	printf("original : %d\n\n", printf("original :   |%.3i|\n", i));
	fflush(stdout);
	printf("\n/////test de champ avec ' '/////\n");
	printf("original : %d\n", printf("original :   |% i|\n", i));
	fflush(stdout);
	printf("\n/////test de champ avec '+'/////\n");
	printf("original : %d\n", printf("original :   |%+i|\n", i));
	fflush(stdout);
	printf("\n/////test de champ avec '#'/////\n");
	printf("original : %d\n", printf("original :   |%#i|\n", i));
	fflush(stdout);
	printf("\n\n\n");
	i = 1;
	printf("//////////////////// Tests avec 'i' = %i ////////////////////\n", i);
	printf("/////test sans flags/////\n");
	printf("original : %d\n", printf("original :   |%i|\n", i));
	fflush(stdout);
	printf("/////test de champ 10/////\n");
	printf("original : %d\n", printf("original :   |%10i|\n", i));
	fflush(stdout);
	printf("\n/////test de champ 10 avec '-'/////\n");
	printf("original : %d\n", printf("original :   |%-10i|\n", i));
	fflush(stdout);
	printf("\n/////test de champ 10 avec '0'/////\n");
	printf("original : %d\n", printf("original :   |%010i|\n", i));
	fflush(stdout);
	printf("\n/////test 10 chiffres apres la virgule /////\n");
	printf("original : %d\n\n", printf("original :   |%.10i|\n", i));
	fflush(stdout);
	printf("/////test de champ 3/////\n");
	printf("original : %d\n", printf("original :   |%3i|\n", i));
	fflush(stdout);
	printf("\n/////test de champ 3 avec '-'/////\n");
	printf("original : %d\n", printf("original :   |%-3i|\n", i));
	fflush(stdout);
	printf("\n/////test de champ 3 avec '0'/////\n");
	printf("original : %d\n", printf("original :   |%03i|\n", i));
	fflush(stdout);
	printf("\n/////test 3 chiffres apres la virgule /////\n");
	printf("original : %d\n\n", printf("original :   |%.3i|\n", i));
	fflush(stdout);
	printf("\n/////test de champ avec ' '/////\n");
	printf("original : %d\n", printf("original :   |% i|\n", i));
	fflush(stdout);
	printf("\n/////test de champ avec '+'/////\n");
	printf("original : %d\n", printf("original :   |%+i|\n", i));
	fflush(stdout);
	printf("\n/////test de champ avec '#'/////\n");
	printf("original : %d\n", printf("original :   |%#i|\n", i));
	fflush(stdout);
	printf("\n\n\n"); */

	/* long u = 0;
	printf("//////////////////// Tests avec 'u' = %u ////////////////////\n", u);
	printf("/////test sans flags/////\n");
	printf("original : %d\n", printf("original :   |%u|\n", u));
	fflush(stdout);
	printf("/////test de champ 15/////\n");
	printf("original : %d\n", printf("original :   |%15u|\n", u));
	fflush(stdout);
	printf("\n/////test de champ 15 avec '-'/////\n");
	printf("original : %d\n", printf("original :   |%-15u|\n", u));
	fflush(stdout);
	printf("\n/////test de champ 15 avec '0'/////\n");
	printf("original : %d\n", printf("original :   |%015u|\n", u));
	fflush(stdout);
	printf("\n/////test 15 chiffres apres la virgule /////\n");
	printf("original : %d\n\n", printf("original :   |%.15u|\n", u));
	fflush(stdout);
	printf("/////test de champ 3/////\n");
	printf("original : %d\n", printf("original :   |%3u|\n", u));
	fflush(stdout);
	printf("\n/////test de champ 3 avec '-'/////\n");
	printf("original : %d\n", printf("original :   |%-3u|\n", u));
	fflush(stdout);
	printf("\n/////test de champ 3 avec '0'/////\n");
	printf("original : %d\n", printf("original :   |%03u|\n", u));
	fflush(stdout);
	printf("\n/////test 3 chiffres apres la virgule /////\n");
	printf("original : %d\n\n", printf("original :   |%.3u|\n", u));
	fflush(stdout);
	printf("\n/////test de champ avec ' '/////\n");
	printf("original : %d\n", printf("original :   |% u|\n", u));
	fflush(stdout);
	printf("\n/////test de champ avec '+'/////\n");
	printf("original : %d\n", printf("original :   |%+u|\n", u));
	fflush(stdout);
	printf("\n/////test de champ avec '#'/////\n");
	printf("original : %d\n", printf("original :   |%#u|\n", u));
	fflush(stdout);
	printf("\n\n\n");
	u = 1;
	printf("//////////////////// Tests avec 'u' = %u ////////////////////\n", u);
	printf("/////test sans flags/////\n");
	printf("original : %d\n", printf("original :   |%u|\n", u));
	fflush(stdout);
	printf("/////test de champ 15/////\n");
	printf("original : %d\n", printf("original :   |%15u|\n", u));
	fflush(stdout);
	printf("\n/////test de champ 15 avec '-'/////\n");
	printf("original : %d\n", printf("original :   |%-15u|\n", u));
	fflush(stdout);
	printf("\n/////test de champ 15 avec '0'/////\n");
	printf("original : %d\n", printf("original :   |%015u|\n", u));
	fflush(stdout);
	printf("\n/////test 15 chiffres apres la virgule /////\n");
	printf("original : %d\n\n", printf("original :   |%.15u|\n", u));
	fflush(stdout);
	printf("/////test de champ 3/////\n");
	printf("original : %d\n", printf("original :   |%3u|\n", u));
	fflush(stdout);
	printf("\n/////test de champ 3 avec '-'/////\n");
	printf("original : %d\n", printf("original :   |%-3u|\n", u));
	fflush(stdout);
	printf("\n/////test de champ 3 avec '0'/////\n");
	printf("original : %d\n", printf("original :   |%03u|\n", u));
	fflush(stdout);
	printf("\n/////test 3 chiffres apres la virgule /////\n");
	printf("original : %d\n\n", printf("original :   |%.3u|\n", u));
	fflush(stdout);
	printf("\n/////test de champ avec ' '/////\n");
	printf("original : %d\n", printf("original :   |% u|\n", u));
	fflush(stdout);
	printf("\n/////test de champ avec '+'/////\n");
	printf("original : %d\n", printf("original :   |%+u|\n", u));
	fflush(stdout);
	printf("\n/////test de champ avec '#'/////\n");
	printf("original : %d\n", printf("original :   |%#u|\n", u));
	fflush(stdout);
	printf("\n\n\n");
	u = -1;
	printf("//////////////////// Tests avec 'u' = %u ////////////////////\n", u);
	printf("/////test sans flags/////\n");
	printf("original : %d\n", printf("original :   |%u|\n", u));
	fflush(stdout);
	printf("/////test de champ 15/////\n");
	printf("original : %d\n", printf("original :   |%15u|\n", u));
	fflush(stdout);
	printf("\n/////test de champ 15 avec '-'/////\n");
	printf("original : %d\n", printf("original :   |%-15u|\n", u));
	fflush(stdout);
	printf("\n/////test de champ 15 avec '0'/////\n");
	printf("original : %d\n", printf("original :   |%015u|\n", u));
	fflush(stdout);
	printf("\n/////test 15 chiffres apres la virgule /////\n");
	printf("original : %d\n\n", printf("original :   |%.15u|\n", u));
	fflush(stdout);
	printf("/////test de champ 3/////\n");
	printf("original : %d\n", printf("original :   |%3u|\n", u));
	fflush(stdout);
	printf("\n/////test de champ 3 avec '-'/////\n");
	printf("original : %d\n", printf("original :   |%-3u|\n", u));
	fflush(stdout);
	printf("\n/////test de champ 3 avec '0'/////\n");
	printf("original : %d\n", printf("original :   |%03u|\n", u));
	fflush(stdout);
	printf("\n/////test 3 chiffres apres la virgule /////\n");
	printf("original : %d\n\n", printf("original :   |%.3u|\n", u));
	fflush(stdout);
	printf("\n/////test de champ avec ' '/////\n");
	printf("original : %d\n", printf("original :   |% u|\n", u));
	fflush(stdout);
	printf("\n/////test de champ avec '+'/////\n");
	printf("original : %d\n", printf("original :   |%+u|\n", u));
	fflush(stdout);
	printf("\n/////test de champ avec '#'/////\n");
	printf("original : %d\n", printf("original :   |%#u|\n", u));
	fflush(stdout);
	printf("\n\n\n"); */

	/* int x = 0;
	printf("//////////////////// Tests avec 'x' pour x = %i ////////////////////\n", x);
	printf("/////test sans flags/////\n");
	printf("original : %d\n", printf("original :   |%x|\n", x));
	fflush(stdout);
	printf("/////test de champ 10/////\n");
	printf("original : %d\n", printf("original :   |%10x|\n", x));
	fflush(stdout);
	printf("\n/////test de champ 10 avec '-'/////\n");
	printf("original : %d\n", printf("original :   |%-10x|\n", x));
	fflush(stdout);
	printf("\n/////test de champ 10 avec '0'/////\n");
	printf("original : %d\n", printf("original :   |%010x|\n", x));
	fflush(stdout);
	printf("\n/////test 10 chiffres apres la virgule /////\n");
	printf("original : %d\n\n", printf("original :   |%.10x|\n", x));
	fflush(stdout);
	printf("/////test de champ 3/////\n");
	printf("original : %d\n", printf("original :   |%3x|\n", x));
	fflush(stdout);
	printf("\n/////test de champ 3 avec '-'/////\n");
	printf("original : %d\n", printf("original :   |%-3x|\n", x));
	fflush(stdout);
	printf("\n/////test de champ 3 avec '0'/////\n");
	printf("original : %d\n", printf("original :   |%03x|\n", x));
	fflush(stdout);
	printf("\n/////test 3 chiffres apres la virgule /////\n");
	printf("original : %d\n\n", printf("original :   |%.3x|\n", x));
	fflush(stdout);
	printf("\n/////test de champ avec ' '/////\n");
	printf("original : %d\n", printf("original :   |% x|\n", x));
	fflush(stdout);
	printf("\n/////test de champ avec '+'/////\n");
	printf("original : %d\n", printf("original :   |%+x|\n", x));
	fflush(stdout);
	printf("\n/////test de champ avec '#'/////\n");
	printf("original : %d\n", printf("original :   |%#x|\n", x));
	fflush(stdout);
	printf("\n\n\n");
	x = -1;
	printf("//////////////////// Tests avec 'x' pour x = %i ////////////////////\n", x);
	printf("/////test sans flags/////\n");
	printf("original : %d\n", printf("original :   |%x|\n", x));
	fflush(stdout);
	printf("/////test de champ 10/////\n");
	printf("original : %d\n", printf("original :   |%10x|\n", x));
	fflush(stdout);
	printf("\n/////test de champ 10 avec '-'/////\n");
	printf("original : %d\n", printf("original :   |%-10x|\n", x));
	fflush(stdout);
	printf("\n/////test de champ 10 avec '0'/////\n");
	printf("original : %d\n", printf("original :   |%010x|\n", x));
	fflush(stdout);
	printf("\n/////test 10 chiffres apres la virgule /////\n");
	printf("original : %d\n\n", printf("original :   |%.10x|\n", x));
	fflush(stdout);
	printf("/////test de champ 3/////\n");
	printf("original : %d\n", printf("original :   |%3x|\n", x));
	fflush(stdout);
	printf("\n/////test de champ 3 avec '-'/////\n");
	printf("original : %d\n", printf("original :   |%-3x|\n", x));
	fflush(stdout);
	printf("\n/////test de champ 3 avec '0'/////\n");
	printf("original : %d\n", printf("original :   |%03x|\n", x));
	fflush(stdout);
	printf("\n/////test 3 chiffres apres la virgule /////\n");
	printf("original : %d\n\n", printf("original :   |%.3x|\n", x));
	fflush(stdout);
	printf("\n/////test de champ avec ' '/////\n");
	printf("original : %d\n", printf("original :   |% x|\n", x));
	fflush(stdout);
	printf("\n/////test de champ avec '+'/////\n");
	printf("original : %d\n", printf("original :   |%+x|\n", x));
	fflush(stdout);
	printf("\n/////test de champ avec '#'/////\n");
	printf("original : %d\n", printf("original :   |%#x|\n", x));
	fflush(stdout);
	printf("\n\n\n");
	x = 1;
	printf("//////////////////// Tests avec 'x' pour x = %i ////////////////////\n", x);
	printf("/////test sans flags/////\n");
	printf("original : %d\n", printf("original :   |%x|\n", x));
	fflush(stdout);
	printf("/////test de champ 10/////\n");
	printf("original : %d\n", printf("original :   |%10x|\n", x));
	fflush(stdout);
	printf("\n/////test de champ 10 avec '-'/////\n");
	printf("original : %d\n", printf("original :   |%-10x|\n", x));
	fflush(stdout);
	printf("\n/////test de champ 10 avec '0'/////\n");
	printf("original : %d\n", printf("original :   |%010x|\n", x));
	fflush(stdout);
	printf("\n/////test 10 chiffres apres la virgule /////\n");
	printf("original : %d\n\n", printf("original :   |%.10x|\n", x));
	fflush(stdout);
	printf("/////test de champ 3/////\n");
	printf("original : %d\n", printf("original :   |%3x|\n", x));
	fflush(stdout);
	printf("\n/////test de champ 3 avec '-'/////\n");
	printf("original : %d\n", printf("original :   |%-3x|\n", x));
	fflush(stdout);
	printf("\n/////test de champ 3 avec '0'/////\n");
	printf("original : %d\n", printf("original :   |%03x|\n", x));
	fflush(stdout);
	printf("\n/////test 3 chiffres apres la virgule /////\n");
	printf("original : %d\n\n", printf("original :   |%.3x|\n", x));
	fflush(stdout);
	printf("\n/////test de champ avec ' '/////\n");
	printf("original : %d\n", printf("original :   |% x|\n", x));
	fflush(stdout);
	printf("\n/////test de champ avec '+'/////\n");
	printf("original : %d\n", printf("original :   |%+x|\n", x));
	fflush(stdout);
	printf("\n/////test de champ avec '#'/////\n");
	printf("original : %d\n", printf("original :   |%#x|\n", x));
	fflush(stdout);
	printf("\n\n\n"); */

	/* int x = 0;
	printf("//////////////////// Tests avec 'X' pour x = %i ////////////////////\n", x);
	printf("/////test sans flags/////\n");
	printf("original : %d\n", printf("original :   |%X|\n", x));
	fflush(stdout);
	printf("/////test de champ 10/////\n");
	printf("original : %d\n", printf("original :   |%10X|\n", x));
	fflush(stdout);
	printf("\n/////test de champ 10 avec '-'/////\n");
	printf("original : %d\n", printf("original :   |%-10X|\n", x));
	fflush(stdout);
	printf("\n/////test de champ 10 avec '0'/////\n");
	printf("original : %d\n", printf("original :   |%010X|\n", x));
	fflush(stdout);
	printf("\n/////test 10 chiffres apres la virgule /////\n");
	printf("original : %d\n\n", printf("original :   |%.10X|\n", x));
	fflush(stdout);
	printf("/////test de champ 3/////\n");
	printf("original : %d\n", printf("original :   |%3X|\n", x));
	fflush(stdout);
	printf("\n/////test de champ 3 avec '-'/////\n");
	printf("original : %d\n", printf("original :   |%-3X|\n", x));
	fflush(stdout);
	printf("\n/////test de champ 3 avec '0'/////\n");
	printf("original : %d\n", printf("original :   |%03X|\n", x));
	fflush(stdout);
	printf("\n/////test 3 chiffres apres la virgule /////\n");
	printf("original : %d\n\n", printf("original :   |%.3X|\n", x));
	fflush(stdout);
	printf("\n/////test de champ avec ' '/////\n");
	printf("original : %d\n", printf("original :   |% X|\n", x));
	fflush(stdout);
	printf("\n/////test de champ avec '+'/////\n");
	printf("original : %d\n", printf("original :   |%+X|\n", x));
	fflush(stdout);
	printf("\n/////test de champ avec '#'/////\n");
	printf("original : %d\n", printf("original :   |%#X|\n", x));
	fflush(stdout);
	printf("\n\n\n");
	x = -1;
	printf("//////////////////// Tests avec 'X' pour x = %i ////////////////////\n", x);
	printf("/////test sans flags/////\n");
	printf("original : %d\n", printf("original :   |%X|\n", x));
	fflush(stdout);
	printf("/////test de champ 10/////\n");
	printf("original : %d\n", printf("original :   |%10X|\n", x));
	fflush(stdout);
	printf("\n/////test de champ 10 avec '-'/////\n");
	printf("original : %d\n", printf("original :   |%-10X|\n", x));
	fflush(stdout);
	printf("\n/////test de champ 10 avec '0'/////\n");
	printf("original : %d\n", printf("original :   |%010X|\n", x));
	fflush(stdout);
	printf("\n/////test 10 chiffres apres la virgule /////\n");
	printf("original : %d\n\n", printf("original :   |%.10X|\n", x));
	fflush(stdout);
	printf("/////test de champ 3/////\n");
	printf("original : %d\n", printf("original :   |%3X|\n", x));
	fflush(stdout);
	printf("\n/////test de champ 3 avec '-'/////\n");
	printf("original : %d\n", printf("original :   |%-3X|\n", x));
	fflush(stdout);
	printf("\n/////test de champ 3 avec '0'/////\n");
	printf("original : %d\n", printf("original :   |%03X|\n", x));
	fflush(stdout);
	printf("\n/////test 3 chiffres apres la virgule /////\n");
	printf("original : %d\n\n", printf("original :   |%.3X|\n", x));
	fflush(stdout);
	printf("\n/////test de champ avec ' '/////\n");
	printf("original : %d\n", printf("original :   |% X|\n", x));
	fflush(stdout);
	printf("\n/////test de champ avec '+'/////\n");
	printf("original : %d\n", printf("original :   |%+X|\n", x));
	fflush(stdout);
	printf("\n/////test de champ avec '#'/////\n");
	printf("original : %d\n", printf("original :   |%#X|\n", x));
	fflush(stdout);
	printf("\n\n\n");
	x = 1;
	printf("//////////////////// Tests avec 'X' pour x = %i ////////////////////\n", x);
	printf("/////test sans flags/////\n");
	printf("original : %d\n", printf("original :   |%X|\n", x));
	fflush(stdout);
	printf("/////test de champ 10/////\n");
	printf("original : %d\n", printf("original :   |%10X|\n", x));
	fflush(stdout);
	printf("\n/////test de champ 10 avec '-'/////\n");
	printf("original : %d\n", printf("original :   |%-10X|\n", x));
	fflush(stdout);
	printf("\n/////test de champ 10 avec '0'/////\n");
	printf("original : %d\n", printf("original :   |%010X|\n", x));
	fflush(stdout);
	printf("\n/////test 10 chiffres apres la virgule /////\n");
	printf("original : %d\n\n", printf("original :   |%.10X|\n", x));
	fflush(stdout);
	printf("/////test de champ 3/////\n");
	printf("original : %d\n", printf("original :   |%3X|\n", x));
	fflush(stdout);
	printf("\n/////test de champ 3 avec '-'/////\n");
	printf("original : %d\n", printf("original :   |%-3X|\n", x));
	fflush(stdout);
	printf("\n/////test de champ 3 avec '0'/////\n");
	printf("original : %d\n", printf("original :   |%03X|\n", x));
	fflush(stdout);
	printf("\n/////test 3 chiffres apres la virgule /////\n");
	printf("original : %d\n\n", printf("original :   |%.3X|\n", x));
	fflush(stdout);
	printf("\n/////test de champ avec ' '/////\n");
	printf("original : %d\n", printf("original :   |% X|\n", x));
	fflush(stdout);
	printf("\n/////test de champ avec '+'/////\n");
	printf("original : %d\n", printf("original :   |%+X|\n", x));
	fflush(stdout);
	printf("\n/////test de champ avec '#'/////\n");
	printf("original : %d\n", printf("original :   |%#X|\n", x));
	fflush(stdout);
	printf("\n\n\n"); */

	/* printf("//////////////////// Tests avec '%%' ////////////////////\n");
	printf("/////test sans flags/////\n");
	printf("original : %d\n", printf("original :   |%%|\n"));
	fflush(stdout);
	printf("/////test de champ 10/////\n");
	printf("original : %d\n", printf("original :   |%10%|\n"));
	fflush(stdout);
	printf("\n/////test de champ 10 avec '-'/////\n");
	printf("original : %d\n", printf("original :   |%-10%|\n"));
	fflush(stdout);
	printf("\n/////test de champ 10 avec '0'/////\n");
	printf("original : %d\n", printf("original :   |%010%|\n"));
	fflush(stdout);
	printf("\n/////test 10 chiffres apres la virgule /////\n");
	printf("original : %d\n\n", printf("original :   |%.10%|\n"));
	fflush(stdout);
	printf("/////test de champ 3/////\n");
	printf("original : %d\n", printf("original :   |%3%|\n"));
	fflush(stdout);
	printf("\n/////test de champ 3 avec '-'/////\n");
	printf("original : %d\n", printf("original :   |%-3%|\n"));
	fflush(stdout);
	printf("\n/////test de champ 3 avec '0'/////\n");
	printf("original : %d\n", printf("original :   |%03%|\n"));
	fflush(stdout);
	printf("\n/////test 3 chiffres apres la virgule /////\n");
	printf("original : %d\n\n", printf("original :   |%.3%|\n"));
	fflush(stdout);
	printf("\n/////test de champ avec ' '/////\n");
	printf("original : %d\n", printf("original :   |% %|\n"));
	fflush(stdout);
	printf("\n/////test de champ avec '+'/////\n");
	printf("original : %d\n", printf("original :   |%+%|\n"));
	fflush(stdout);
	printf("\n/////test de champ avec '#'/////\n");
	printf("original : %d\n", printf("original :   |%#%|\n"));
	fflush(stdout);
	printf("\n\n\n"); */
	return (0);
} 

/*
"%#-76.67x%-178c%#126.17x%-178.97%%-80.63i" ,2705358650u,-128,4292242043u,
-156704363
"%-26.85u%+#100.2%%#0130.74x%#59.63X%086x" ,602620792u,1774300267u,835967277u
,2887108754u
"%64.79u%#168.142x%110c" ,1663238694u,2980990023u,-98
"%--99p%94.103s%181.150x% 21d%+16.%" ,17804030627542756824lu,"\n#\fj<Oil\ft7\
tj&^|ddD80t\nIL+,",184469023u,1795574960
"%#73.181X%--47.192X" ,3720784993u,3491116485u
"%-#88.82x" ,3532279970u
"%#196.53X" ,3130516526u
"%  130.137%%#102.18x%059.56u%#167.193X" ,2661836307u,3540858512u,1574239099u
"% 171.152d%p%0197.33u%0+#131.71%" ,2055571139,6109035435017027490lu,
1457993623u
"%98p%147p%#43.85x%++197.126i%195.u" ,17422923310524768300lu,
8561336791391148915lu,839088623u,-1692713526,2802635555u
"%.80s% # 177.44%%#093.105X" ,"Nhfxl\\f}EJyv:>\tgq7kFZ&VUM",392767992u
"%#38.119x%120p%155c%-147.d" ,4216448853u,12423865882424705706lu,-98,
-1967106559
"%48c%-#184.95X%185p" ,48,856683944u,9125943193160606356lu */