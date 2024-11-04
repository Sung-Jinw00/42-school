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

#ifndef R01BOXS_h
# define R01BOXS_h

# include <unistd.h>
# include <stdlib.h>

void	boss_killer(int **answer, /* int *conditions,  */int val_max);
int		ft_error(void);
int		error_peers(void);
int		ft_error_sol(void);
int		ft_strlen(char *str);
int		main(int ac, char **av);
int		ft_strcmp(char *s1, char *s2);
int		rush01(char **av, int val_max);
int		go_to_r01(char *av, int val_max);
int		up_border(int box, int val_max);
int		ft_if_ac_2(char **av, int val_max);
int		low_border(int box, int val_max);
int		left_border(int box, int val_max);
int		right_border(int box, int val_max);
int		up_line_conds(int box, int val_max, int *conditions);
int		low_line_conds(int box, int val_max, int *conditions);
int		left_col_conds(int box, int val_max, int *conditions);
int		right_col_conds(int box, int val_max, int *conditions);
void	ft_write_cond(int *cond_gril, char **av, int val_max);
int		same_line(int box, int val_max, int compare);
int		cmp_dup_line(int **answer, int box, int val_max);
int		cond_peers_validity(int * conditions, int val_max);
void	ft_putstr(int **answer, int val_max, int *conditions);
int		cross_opti(int *conditions, int box, int val_max);
int		visible_towers_in_col(int **answer, int box, int val_max, int *conditions);
int		visible_towers_in_line(int **answer, int box, int val_max, int *conditions);
int		visible_rev_towers_in_col(int **answer, int box, int val_max, int *conditions);
int		visible_rev_towers_in_line(int **answer, int box, int val_max, int *conditions);
int		above_cond(int **answer, int box, int val_max, int *conditions);
void	write_conds(int *conditions, int bordure, int box, int val_max);
int		start_check(int *conditions, int **answer, int box, int val_max);
void	verif_conds(int **answer, int val_max, int *conditions);
int 	rev_col_check(int * conditions, int **answer, int box, int val_max);
int 	rev_line_check(int * conditions, int **answer, int box, int val_max);
int		ft_recursive_verif(int **answer, int val_max, int *conds);
int 	same_line(int box, int val_max, int compare);
void	remove_invalid_values(int **answer, int val_max, int box);
void	one_to_5_in_col(int **answer, int val_max, int box, char *da_wae);
void	one_to_5_in_line(int **answer, int val_max, int box, char *da_wae);
void	two_and_one_in_cond(int **answer, int val_max, int box, int *changes, int *conditions);
void	vmax_in_cond(int **answer, int val_max, int box, int *changes, int *conditions);
void	one_in_cond(int **answer, int val_max, int box, int *changes, int *conditions);
void	two_in_cond(int **answer, int val_max, int box, int *changes, int *conditions);
void	one_or_val_max(int *conditions, int **answer, int val_max, int box, int *changes);
void	pre_filling(int *conditions, int **answer, int val_max);
int		ft_count_digits(int **answer, int val_max, int box);
void	last_digit(int **answer, int val_max, int box, int *changes);
void 	init_answer(int **answer, int val_max, int *conds);
int		find_last_digit(int value, int **answer, int val_max);
int		comp_possibilities(int **answer, int val_max, int i, int j);
int		one_possibility_left(int **answer, int box, int val_max);
void	shorten_possibilities_line(int **answer, int val_max, int box, int vals_to_keep, int *changes);
int		compare_same_nbs_line(int **answer, int val_max, int box, int *changes);
void	if_same_vals_line(int **answer, int val_max, int box, int *changes);
void	shorten_possibilities_col(int **answer, int val_max, int box, int vals_to_keep, int *changes);
int		compare_same_nbs_col(int **answer, int val_max, int box, int *changes);
void	if_same_vals_col(int **answer, int val_max, int box, int *changes);
int		**ft_strdup(int **src, int val_max);
void	one_nb_line(int **answer, int k, int box, int val_max);
void	one_nb_col(int **answer, int k, int box, int val_max);
void	one_number_left(int **answer, int box, int val_max);
void	limits(int **answer, int *conditions, int val_max);
void	mini_pre_filling(int *conditions, int **answer, int val_max, int box);
int		check_if_soluce(int **answer, int val_max);

#endif