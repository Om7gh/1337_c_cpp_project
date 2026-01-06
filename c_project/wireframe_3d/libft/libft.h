/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omghazi <omghazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 04:08:42 by omghazi           #+#    #+#             */
/*   Updated: 2024/02/18 13:28:23 by omghazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <stdlib.h>
# include <stdint.h>
# include <unistd.h>
# include <stdio.h>

# define BUFFER_SIZE 10

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

int		ft_atoi(const char *str);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**ft_split(char const *s, char c);
void	ft_bzero(void *s, size_t n);
void	ft_putendl_fd(char *s, int fd);
size_t	ft_strlen(const char *s);
char	*get_next_line(int fd);
char	*my_strjoin(char *s1, char *s2, int n);
size_t	my_strlen(char *s);
char	*my_strchr(char *s, int c);
char	*my_strdup(char *str);
void	*my_calloc(size_t count, size_t size);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
#endif
