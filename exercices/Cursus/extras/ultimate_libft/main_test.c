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

#include "ultimate_libft.h"

int	main(void)
{
	char	*answer;

	answer = ft_multiply("-1", "3");
	printf("answer = %s\n", answer);
	free(answer);
	return (0);
}
