/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 16:05:11 by locagnio          #+#    #+#             */
/*   Updated: 2024/11/22 17:38:17 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	len_field_nb2(t_struct v, int len_val, int i)
{
	int			zeros;
	long long	nb;

	zeros = 0;
	nb = *(long long *)v.arg;
	if (ft_strchr(v.flag_order, '.'))
	{
		if (nb < 0)
			nb = -nb;
		zeros = v.nb2 - ft_digits(nb);
		if (v.nb2 > ft_digits(nb))
			len_val += zeros;
	}
	if ((v.nb1 == 0 || (v.nb1 != 0 && v.nb1 < len_val + 1))
		&& ((ft_strchr(v.flag_order, '+') && *(long long *)v.arg >= 0)
			|| (ft_strchr(v.flag_order, ' ') && *(long long *)v.arg >= 0)))
		v.nb1 = len_val++;
	else if ((ft_strchr(v.flag_order, '+') || ft_strchr(v.flag_order, ' '))
		&& v.nb1 != 0
		&& *(long long *)v.arg >= 0 && (v.str[i] == 'd' || v.str[i] == 'i'))
		len_val++;
	return (len_val);
}

int	printfzeronb(t_struct v, int i)
{
	if (v.arg && ft_strchr(v.flag_order, '#'))
	{
		if (ft_strcmp((char *)v.arg, "0") == 0)
		{
			if (v.str[i] == 'x')
				write(1, "0x", 2);
			else
				write(1, "0X", 2);
		}
	}
	while (v.zerosnb > 0)
	{
		write(1, "0", 1);
		v.zerosnb--;
	}
	return (0);
}

char	*ft_strndup(char *str, size_t n)
{
	char	*cpy;
	size_t	i;

	i = -1;
	cpy = ft_calloc(n + 1, 1);
	if (!cpy)
		return (NULL);
	while (++i < n)
		cpy[i] = str[i];
	cpy[n] = '\0';
	return (cpy);
}

t_struct	ft_preprint_nb(t_struct v, int *len_field)
{
	int	zeros;
	int	sign;

	sign = 0;
	v.zerosnb = 0;
	if (*(long long *)v.arg < 0)
		sign = 1;
	zeros = v.nb2 - ft_digits(*(long long *)v.arg) + sign;
	if (ft_strchr(v.flag_order, '.') && zeros > 0)
		v.zerosnb = zeros;
	if ((ft_strchr(v.flag_order, '+') || ft_strchr(v.flag_order, ' '))
		&& *(long long *)v.arg >= 0
		&& v.nb1 != 0)
		*len_field -= 1;
	return (v);
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
	count = 0;
	v.str = str;
	v.arg = ft_calloc(1, 8);
	while (i < 7)
		v.flag_order[i++] = 0;
	v.nb1 = 0;
	v.nb2 = 0;
	v.zerosnb = 0;
	va_start(args, str);
	count = print_this_bs(args, v);
	va_end(args);
	free(v.arg);
	return (count);
}

/* #include "../tests/tests.h"
#include <limits.h>

void	tests_point(void)
{
	printf("original : %d\n", printf("original :   |%c|%s|%p|%u|%i|%d|%x|%X|%%|\n", 0, 0, 0, 0, 0, 0, 0, 0));
	printf("copie    : %d\n", ft_printf("copie    :   |%c|%s|%p|%u|%i|%d|%x|%X|%%|\n", 0, 0, 0, 0, 0, 0, 0, 0));
	printf("\n\n\n");
}

#include <stdio.h>
int main(void)
{
	tests_c(0);
	tests_s(NULL);
	tests_d(-128);
	tests_i(-128);
	tests_u(-128);
	tests_x(-128);
	tests_x_maj(-128);
	tests_percent();
	tests_point();
	return (0);
}  */

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