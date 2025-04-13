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

int main(void)
{
    char *tab2[] = {"bonjour", "tout", "le", "monde", NULL};
    char *tab3[] = {"hello", "world", NULL};
    char **tableau[] = {tab2, tab3, NULL};  // Tableau de tableaux de chaînes
    char ***ptr = tableau;  // Pointeur vers un tableau de tableaux de chaînes

    // Exemple avec un char***
    printf("Count of words in char ***: %d\n", ft_count_words((void *)ptr));

    // Exemple avec un char**
    printf("Count of words in char **: %d\n", ft_count_words(tab2));

    return 0;
}
