/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 15:01:50 by locagnio          #+#    #+#             */
/*   Updated: 2024/09/17 15:56:24 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*cpy;
	int		len_src;
	int		i;

	i = 0;
	len_src = ft_strlen(src);
	cpy = (char *)malloc(sizeof(char) * (len_src + 1));
	if (!cpy)
		return (NULL);
	while (src[i] != '\0')
	{
		cpy[i] = src[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	t_stock_str	*tab;

	tab = malloc(sizeof(t_stock_str) * (ac + 1));
	i = 0;
	while (i < ac)
	{
		tab[i].str = av[i];
		tab[i].size = ft_strlen(av[i]);
		tab[i].copy = ft_strdup(av[i]);
		i++;
	}
	tab[i].str = NULL;
	tab[i].size = 0;
	tab[i].copy = NULL;
	return (tab);
} */
//////////////////////exercice//////////////////////////
#include <unistd.h>
#include " ft_stock_str.h"

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = 0;
	while (par[i].str != NULL)
	{
		ft_putstr(par[i].str);
		par[i].size += 48;
		write(1, &par[i].size, 1);
		write(1, "\n", 1);
		ft_putstr(par[i].copy);
		i++;
	}
}

/* int	main(int ac, char **av)
{
	struct s_stock_str	*par;
	par = ft_strs_to_tab(ac, av);
	ft_show_tab(par);
	return (0);
} */