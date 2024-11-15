/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 23:12:27 by locagnio          #+#    #+#             */
/*   Updated: 2024/09/22 23:15:02 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

char	*ft_rm_zero(char *str)
{
	int		i;
	int		j;
	int		k;
	char	*temp;

	j = ft_strlen(str);
	i = 0;
	k = 0;
	while (str[i] == '0' && str[i + 1] != '\0')
	{
		i++;
	}
	temp = ft_calloc(sizeof(char) * (j - i + 3), 1);
	if (temp == NULL)
		return (NULL);
	while (str[i])
		temp[k++] = str[i++];
	temp[k] = '\0';
	return (temp);
}

void	*ft_calloc(unsigned count, unsigned size)
{
	void			*ptr;
	unsigned int	i;

	ptr = malloc(count * size);
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (i < count * size)
	{
		((char *)ptr)[i] = 0;
		i++;
	}
	return (ptr);
}
