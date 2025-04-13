/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 18:16:22 by marvin            #+#    #+#             */
/*   Updated: 2025/04/08 18:16:22 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_extras.h"

int	main(int ac, char **av)
{
	if (ac != 2)
		return (0);
	char *str = ft_ftoa(ft_atod(av[1]), ft_strrclen(av[1], '.'));

	if (!ft_strcmp(str, av[1]))
		return (ft_write(1, "nickel\n"));
	return (printf("eclate au sol\nresultat : %s\n", str));
}
