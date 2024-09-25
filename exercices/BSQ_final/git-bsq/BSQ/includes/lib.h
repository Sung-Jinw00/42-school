/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 14:30:54 by locagnio          #+#    #+#             */
/*   Updated: 2024/09/25 23:37:06 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_H
# define LIB_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct s_coords
{
	int		line;
	int		col;
	int		size;
	int		line_backup;
	int		col_backup;
	int		backup_obst;
	char	empty;
	char	obstacle;
	char	full;
}	t_coords;

int		catch_param2(char *buffer);
int		ft_atoi(char *str);
void	assign_new_coords(int *coords, t_coords *save);
void	ft_init_lol(t_coords *save);
void	solver(char **map, t_coords *save);
void	find_first_square(int *coords, char **map, t_coords *save);
int		count_line_break(char *buff, t_coords *save);
int		ft_skip_obst(char **map, t_coords *save);
int		find_first_y(char **map, t_coords *save);
int		solver_part2(char **map, t_coords *save, int k, int count);
int		ft_countlen(char *buff);
char	*read_file(char *filename);
char	*catch_param(char *buffer);
int		*search_square(char **tab, char *buffer, t_coords *save);
int		*find_another_square(int *coords, char **map, t_coords *save);
char	**gen_tab_of_tab(char *buff, char **tab, t_coords *save, int c);
char	**the_square(int *coords, char **tab, t_coords *res);
int		ft_strlen(char *str);
int		print_final(char **res, char *x);
char	*read_syscall(void);
void	error(void);
char	**ft_split(char *str, char *charset);
char	**write_split(char *str, char **split, char *charset, int i);
int		len_word(char *str, char *charset);
int		ft_cnt_words(char *str, char *charset);
int		skip_charset(char i, char *charset);
int		loop_main(char *x, int c);
int		check_map(char **res);
char	*ft_strcpy(char *dest, char *src);
char	*ft_strdup(char *src);
int		count_line_break2(char *buff);
int		syscall_bsq(char *x);

#endif