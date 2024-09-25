/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 11:18:34 by locagnio          #+#    #+#             */
/*   Updated: 2024/09/24 21:05:22 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib.h"

int	main(int ac, char **av)
{
	char	**res;
	int *the_prime_square;
	int i = 0;
	int j = 0;
	t_coords *save;

	if (ac != 2)
		return (0);
	save = malloc(sizeof(t_coords));
	res = gen_tab_of_tab(read_file(av[1]));
	the_prime_square = search_square(res, catch_param(read_file(av[1])), save);
	printf("colonne : %d\n", the_prime_square[0]);
	printf("ligne : %d\n", the_prime_square[1]);
	printf("taille du carre : %d\n", the_prime_square[2]);
	i = 0;
	res = the_square(the_prime_square, res, save);
	while (res[j])
	{
		while (res[j][i])
		{
			write(1, &res[j][i], 1);
			i++;
		}
		if (j < catch_param2(read_file(av[1])))
			write(1, "\n", 1);
		i = 0;
		j++;
	}
}
