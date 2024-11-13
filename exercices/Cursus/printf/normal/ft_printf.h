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
}	t_struct;

size_t	ft_strlen(const char *s);
void	ft_putnbr_fd(int *count, int n, int fd);
void	ft_putunbr_fd(int *count, unsigned long n, int fd);
void	ft_putstr_fd(char *s, int fd);
char	*ft_itoa_base(long long n, const char *base);
int		ft_printf(const char *str, ...);
void	ft_redpill(int i, int *count, t_struct v, va_list args);

#endif

/* 1copie :   2147483647 2147483648 4294967295 0 4294967295 0 4294967254 */