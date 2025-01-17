/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_extras.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:00:12 by locagnio          #+#    #+#             */
/*   Updated: 2025/01/17 21:57:24 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_EXTRAS_H
# define LIBFT_EXTRAS_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				data;
	struct s_list	*next;
} t_list,	t_cell;

int		ft_min(int *tab);
int		ft_max(int *tab);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
int		ft_absolu(int nb);
int		ft_tolower(int c);
int		ft_toupper(int c);
char	*ft_itoa(int n);
double	ft_atod(char *nptr);
int		ft_atoi(const char *nptr);
int		ft_natoi(const char *nptr, int *i);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
void	*ft_upgrade_realloc(void *ptr, size_t size);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memset(void *s, int c, size_t n);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
char	**ft_split(char const *str, char charset);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *src);
char	*ft_strndup(const char *src, int n);
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcat(char *dst, const char *src, size_t dsize);
size_t	ft_strlcpy(char *dst, const char *src, size_t dsize);
size_t	ft_strlen(const char *s);
size_t	ft_strclen(const char *s, char c);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strrchr(const char *s, int c);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);

//chain lists
long	len_list(t_list *L);
void	print_list(t_list *L);
t_list	*free_list(t_list *L);
t_cell	*create_cell(int data);
t_list	*ft_listdup(t_list *src);
int		get_at(t_list *L, int pos);
t_list	*free_at(t_list *L, int pos);
t_list	*ft_listndup(t_list *src, int n);
void	ft_list_sort(t_list **begin_list);
void	ft_list_reverse(t_list **begin_list);
void	set_at(t_list *L, int data, int pos);
t_list	*add_at(t_list *L, int data, int pos);
t_list	*ft_list_find_pos(t_list *begin_list, void *data_ref);
void	ft_list_remove_if(t_list **begin_list, void *data_ref);
t_list	*ft_list_find_data(t_list *begin_list, void *data_ref);
void	ft_list_merge(t_list **begin_list1, t_list *begin_list2);
void	ft_list_foreach_data(t_list *begin_list, void (*f)(void *));
void	ft_sorted_list_merge(t_list **begin_list1, t_list *begin_list2);
void	ft_list_foreach_data_if(t_list *begin_list, void (*f)(void *), \
void *data_ref);

#endif