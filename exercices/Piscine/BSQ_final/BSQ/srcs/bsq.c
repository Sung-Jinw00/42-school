/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 11:18:34 by locagnio          #+#    #+#             */
/*   Updated: 2024/09/26 13:05:39 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

int	syscall_bsq(char *x)
{
	x = read_syscall();
	if (!loop_main(x, 1))
	{
		error();
		return (0);
	}
	return (1);
}

int	main(int ac, char **av)
{
	char	*x;
	int		i;

	i = 0;
	x = 0;
	if (ac < 1)
		error();
	else if (ac == 1)
	{
		if (!syscall_bsq(x))
			return (0);
	}
	else if (ac > 1)
	{
		while (++i <= ac - 1)
		{
			x = read_file(av[i]);
			if (!x)
				return (0);
			if (!loop_main(x, 0))
				continue ;
		}
	}
	return (0);
}

void	loop_main2(char *bckp, char *x, t_coords *save)
{
	x = catch_param(x);
	if (!bckp)
		return ;
	save[0].empty = x[0];
	save[0].obstacle = x[1];
	save[0].full = x[2];
}

int	loop_main(char *x, int c)
{
	char		**res;
	int			*the_prime_square;
	t_coords	save[2];
	char		*bckp;

	res = NULL;
	bckp = ft_strdup(x);
	loop_main2(bckp, x, save);
	res = gen_tab_of_tab(bckp, res, save, c);
	if (!res || !check_map(res))
	{
		error();
		return (0);
	}
	the_prime_square = search_square(res, catch_param(x), save);
	the_square(the_prime_square, res, save);
	if (!print_final(res, bckp))
	{
		error();
		return (0);
	}
	free(the_prime_square);
	return (1);
}

int	check_map(char **res)
{
	int	i;
	int	j;
	int	c;

	i = 0;
	j = 0;
	c = 0;
	while (res[j])
	{
		i = 0;
		while (res[j][i])
		{
			i++;
			c++;
		}
		j++;
	}
	if (c != i * j)
		return (0);
	return (1);
}
