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
	int			nb;
}	t_struct;

size_t	ft_strlen(const char *s);
void	ft_putnbr_fd(int *count, int n, int fd);
void	ft_putunbr_fd(int *count, unsigned long n, int fd);
void	ft_putstr_fd(char *s, int fd);
char	*ft_itoa_base(long long n, const char *base);
int		ft_printf(const char *str, ...);
void	ft_yellowpill(int i, int *count, t_struct v, va_list args);
void	ft_bluepill(int i, int *count, t_struct v, va_list args);
char	*print_ptr(size_t adr, int *count);
void	ft_redpill(int i, int *count, t_struct v, va_list args);
int		ft_digits(int n);
int		ft_atoi(const char *nptr);
int		standard_conds(t_struct v, int i);
int		bonus_conds(t_struct v, int i);
void	ft_bonus_nbrs(int i, int *count, t_struct v, va_list args);
void	ft_bonus_line(int i, int *count, t_struct v, va_list args);
void	ft_bonus_zero(int i, int *count, t_struct v, va_list args);
void	ft_bonus_point(int i, int *count, t_struct v, va_list args);
void	ft_bonus_hashtag(int i, int *count, t_struct v, va_list args);
void	ft_bonus_space(int i, int *count, t_struct v, va_list args);
void	ft_bonus_plus(int i, int *count, t_struct v, va_list args);
int		skip_flag_duppl(int i, t_struct v, char flag);
char	bonus_flag_finder(int i, t_struct v);
t_struct	init_struct_vals(t_struct v);
void	*ft_calloc(size_t nmemb, size_t size);

#endif

/* 1copie :   2147483647 2147483648 4294967295 0 4294967295 0 4294967254 */