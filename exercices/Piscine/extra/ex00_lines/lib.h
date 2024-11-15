/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 18:04:31 by marvin            #+#    #+#             */
/*   Updated: 2024/10/16 18:04:31 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_H
# define LIB_H

typedef struct params
{
	int val_max;
	int ** combs;
	int *conditions;
} datas;

# include <unistd.h>
# include <stdlib.h>

int	*ft_write_cond(char **av, int val_max);
int cmp_dup_col(datas *params, int **answer, int line);
int check_t_nb_and_dupl(datas *params, int **answer, int line);
int check_conds(datas *params, int **answer, int line);
int check_lines_bloc(datas *params, int **answer, int line);
int visible_rev_towers_in_col(datas *params, int **answer, int box, int line);
int visible_rev_towers_in_line(datas *params, int **answer, int line);
int visible_towers_in_col(datas *params, int **answer, int box, int line);
int visible_towers_in_line(datas *params, int **answer, int line);
int	error_peers(void);
int	ft_error_sol(void);
int	ft_error(void);
int	ft_error_dupl(void);
int	ft_strlen(char *str);
int	go_to_r01(char **av, int val_max);
int	ft_if_ac_2(char **av, int val_max);
int	main(int ac, char **av);
void	write_conds(int *conditions, int bordure, int cases, int val_max);
void	verif_conds(datas *params, int **answer, int line);
int	*ft_strdup(int *src, int size);
int **all_possibilities(int min, int max);
int	cross_opti(int *conditions, int box, int val_max);
int *ft_calloc(int *tab, int size);
int cond_peers_validity(int * conditions, int val_max);
int	ft_recursive_factorial(int nb);
int	if_charset(int val, int *charset, int k);
void	ft_putstr(datas *params, int **answer);
int	ft_recursive_verif(datas *params, int **answer, int line);
int	rush01(char **av, int indice);
int	up_line_conds(int cases, int val_max);
int	low_line_conds(int cases, int val_max);
int	left_col_conds(int cases, int val_max);
int	right_col_conds(int cases, int val_max);
int	ft_strcmp(int s1, int s2);
int	up_border(int cases, int val_max);
int	low_border(int cases, int val_max);
int	left_border(int cases, int val_max);
int	right_border(int cases, int val_max);
int	find_equiv_box(int box, int val_max, int line);
int *find_comb(datas *params, int *combinaison, int *reset, int line, int **answer);
int cmp_dup_1col(int **answer, int line, int box, int cur_val);

#endif