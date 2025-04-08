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

/* int main(void)
{
	char ***str = 

	str = ft_calloc(sizeof(char **), 4);
	str[0] = ft_split("Mythos y LEYENDAS", " ");
	str[1] = ft_split("You want to see the free", " ");
	str[2] = ft_split("Yeh, but you dun like", " ");
	str[3] = NULL;

	for (int i = 0; i < 4; i++)
	{
		printf("tab %d = ", i);
		if (str[i])
			print_dlb_tabs(str[i]);
		else if (!str[i])
			printf("(NULL)\n");
	}
	ft_free_splits_array(&str);
	if (!str)
		printf("tab = (NULL)\n");
	return (0);
} */

int	main(void)
{
	unsigned int	i;

	ft_ato_universal("-37", &i, "unsigned int");
	printf("i = %d\n", i);
	return (0);
}
