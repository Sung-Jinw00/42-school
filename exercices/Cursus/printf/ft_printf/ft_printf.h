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
	void		*arg;
	char		flag_order[7];
	int			nb1;
	int			nb2;
	int			zerosnb;
}	t_struct;

int			ft_digits(long long n);
int			ft_atoi(const char *nptr);
int			ft_strchr(char *s, char c);
int			ft_strcmp(char *s1, char *s2);
int			bonus_conds(t_struct v, int i);
int			ft_len_field(int i, t_struct v);
int			ft_printf(const char *str, ...);
int			special_cases(t_struct v, int i);
int			standard_conds(t_struct v, int i);
int			assign_if_non_nb(t_struct v, int i);
int			len_field_nb2(t_struct v, int len_val, int i);
int			if_plus(int i, t_struct v, int *count);
int			assign_j(int strlen, t_struct v, int i);
int			print_this_bs(va_list args, t_struct v);
int			len_if_x(t_struct v, int i, int len_val);
int			printfzeronb(t_struct v, int i);
int			limit_string(int len_field, int strlen, t_struct v, int i);
char		bonus_flag_finder(int i, t_struct v);
char		*if_hashtag(t_struct v, int i);
char		*ft_strndup(char *str, size_t n);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_itoa_base(long long n, const char *base);
char		*print_ptr(size_t adr, int *count, char *hexa);
void		ft_putstr(char *s);
void		if_plus_or_space(t_struct v);
void		*ft_calloc(size_t nmemb, size_t size);
void		print_char(t_struct v, int len_field);
void		ft_putunbr(int *count, unsigned long n);
void		print_nb(t_struct v, int len_field, int i);
void		ft_putnbr(int *count, long long n, t_struct v);
void		ft_write_answer2(int i, int len_field, t_struct v);
void		print_string2(int j, int limit, t_struct v, int i);
void		print_string3(int j, t_struct v, int i, int len_field);
void		print_nb3(t_struct v, int len_field, int len_nb, int i);
void		ft_bredpill(int i, int *count, t_struct v, va_list args);
void		print_string(t_struct v, int len_field, int i, int trigger);
size_t		ft_strlen(const char *s);
t_struct	parseur2(int *i, t_struct v);
t_struct	fill_parser(char c, t_struct v);
t_struct	erase_flag(char erased, t_struct v);
t_struct	ft_preprint_nb(t_struct v, int *len_field);
t_struct	keep_prior_flag(char erased, char prior, t_struct v);
t_struct	assign_val(int i, t_struct v, va_list args, long long nb);
t_struct	assign_val3(int i, t_struct v, va_list args, long long nb);
t_struct	assign_val2(int i, t_struct v, va_list args, long long nb);

#endif