/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursivity.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 16:36:53 by marvin            #+#    #+#             */
/*   Updated: 2024/10/16 16:36:53 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

int	*ft_write_cond(char **av, int val_max)
{
	int	*conditions;
	int		len;
	int		i;
	int 	j;

	i = 0;
	j = 0;
	len = val_max * 4;
	conditions = (int *)malloc(sizeof(int) * len);
	if (!conditions)
		return (NULL);
	while (av[1][i])
	{
		conditions[j++] = av[1][i] - 48;
		i += 2;
		if (av[1][i - 1] == '\0')
			break;
	}
	return (conditions);
}

void	ft_putstr(datas *params, int **answer)
{
	int	box;
	int line;

	box = 0;
	line = 0;
	verif_conds(params, answer, line);
	write_conds(params->conditions, 1, 0, params->val_max);
	while (line < params->val_max)//tant que j'ai pas ecrit ma derniere ligne
	{
		while (box < params->val_max)//tant que je suis pas arriver a la derniere case de chaque ligne
		{
			if (box == 0)//si je suis a la premiere case, j'ecris la conddtion corresponndante
				write_conds(params->conditions, 3, line, params->val_max);
			answer[line][box] += 48;
			write(1, &answer[line][box], 1);
			if (box < params->val_max - 1)
				write(1, " ", 1);
			else if (box == params->val_max - 1)
			{
				write_conds(params->conditions, 4, line, params->val_max);
				write(1, "\n", 1);
			}
			box++;
		}
		box = 0;
		line++;
	}
	write_conds(params->conditions, 2, 0, params->val_max);

}

int	ft_recursive_verif(datas *params, int **answer, int line)
{
	int	*reset;
	int result;
	int cmb_nb;

	reset = answer[line];
	cmb_nb = ft_recursive_factorial(params->val_max) - 1;//je pars de la derniere combinaison
	answer[line] = find_comb(params, &cmb_nb, reset, line, answer);//je trouve la premiere ligne correcte
	result = 0;
	while (line < params->val_max)//tant que j'ai pas atteint mon nombre de lignes max
	{
		if (answer[line][0] != 0 && check_lines_bloc(params, answer, line))//je test ma valeur avec les valeurs precedentes
		{//si c'est bon
			if (line == params->val_max - 1)//si j'arrive a la derniere case validee
			{
				ft_putstr(params, answer);//j'ecris la reponse
				result++;
			}
			else
				result += ft_recursive_verif(params, answer, line + 1);//je vais a la prochaine case
		}
		cmb_nb -= 1;
		answer[line] = find_comb(params, &cmb_nb, reset, line, answer);//je cherche une autre solution
		if (result == 1 || cmb_nb == -1)
			break;
	}
	return (result);
}

int	rush01(char **av, int val_max)
{
	datas *params;
	int **answer;
	int	i;
	int j;
	int line;

	params = malloc(sizeof(datas));
	params->combs = all_possibilities(1, val_max);//j'alloue ma grille de reponses
	params->conditions = ft_write_cond(av, val_max);//j'assigne ma grille de conditions
	answer = malloc(sizeof(int *) * val_max);//j'alloue ma grille de reponses
	if (!answer /* || !params->conditions || !params->combs */)
		return (0);
	i = 0;
	while (i < val_max)
	{
		answer[i] = ft_calloc(answer[i], val_max);
		i++;
	}
	line = 0;
	params->val_max = val_max;
	if (cond_peers_validity(params->conditions, params->val_max))
		i = ft_recursive_verif(params, answer, line);//je verifie les valeurs
	else
		error_peers();
	j = 0;
	while (j < ft_recursive_factorial(val_max))
		free(params->combs[j++]);
	free(params->conditions);
	free(answer);
	free(params);//je free mes mallocs
	if (i == 0)//si j'ai pas trouve de reponses correctes, erreur
		write(2, "aucune solution trouvee\n", 24);
	return (0);
}
