/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:00:12 by locagnio          #+#    #+#             */
/*   Updated: 2024/11/04 14:00:12 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <limits.h>

typedef struct s_struct
{
	const char	*str;
	char		flags[7];
	int			nb1;
	int			nb2;
	int			zeros;
}	t_struct;

int			srch_flag(char *s, char c);
int			ft_strcmp(char *s1, char *s2);
int			standard_conds(t_struct v, int i);
int			print_this_bs(va_list args, t_struct v);
char		bonus_flag_finder(int i, t_struct v);
void		ft_putnbr(int *count, long n);
void		ft_putstr(char *s, int *count, int limit);
void		ft_putunbr(int *count, unsigned long n);
void		hexa_print(size_t nb, t_struct v, char x);
void		ft_print_char(char c, t_struct v, int i, int *count);
void		ft_print_int(long nb, t_struct v, int i, int *count);
void		ft_print_hexa(long nb, t_struct v, int i, int *count);
void		ft_print_str(char *str, t_struct v, int i, int *count);
void		ft_print_ptr(size_t ptr, t_struct v, int i, int *count);
void		ft_print_uns_int(long nb, t_struct v, int i, int *count);
void		ft_print_percent(char percent, t_struct v, int i, int *count);
size_t		ft_strlen(const char *s);
t_struct	flag_filter(int i, t_struct v);
t_struct	flags(char c, t_struct v);
t_struct	erase_flag(char erased, t_struct v);
t_struct	parse_nd_flags2(int *i, t_struct v);
t_struct	keep_prior_flag(char erased, char prior, t_struct v);

#endif