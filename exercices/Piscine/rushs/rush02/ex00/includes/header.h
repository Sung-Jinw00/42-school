/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 22:25:20 by locagnio          #+#    #+#             */
/*   Updated: 2024/09/22 23:15:48 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# define BUFFER_SIZE 4096

typedef struct s_sss
{
	char	hund_nb[2];
	char	hundred[4];
	char	tens[3];
	char	unit[2];
	int		len;
}	t_sss;

void	ft_putstr(char *str);
char	*ft_rm_zero(char *str);
void	*ft_calloc(unsigned count, unsigned size);
int		init_struct(int i, t_sss *datas, char *av);
t_sss	*build_struct(int i, t_sss *datas, char *av);
t_sss	*sort_numbers(char *av);
void	free_arr(char **arr);
char	*ft_reallocstr(char *ptr, size_t size);
int		ft_readfile(char *filename, char **buffer);
int		ft_atoa(char *str);
int		ft_str_is_printable(char *str);
char	*ft_trim(char *str);
int		parse_dict(char *dict_name, char **parsed);
int		ft_strcslen(char *str, char *charset);
int		nb_sepable(char *str, char *charset);
char	*ft_strndup(char *src, int n);
char	**ft_split(char *str, char *charset);
char	**ft_split_once(char *str, char *charset);
int		assign_nb(char *av, int i);
void	assign_tens(char *av, int i, t_sss *datas, int j);
void	assign_hundred(t_sss *datas, int j);

#endif