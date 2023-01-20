/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcatwoma <wcatwoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 21:14:29 by wcatwoma          #+#    #+#             */
/*   Updated: 2021/02/08 23:10:18 by wcatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			ft_strlen(const char *s)
{
	int	size;

	if (!s)
		return (0);
	size = 0;
	while (s[size])
		++size;
	return (size);
}

char		*ft_strjoin(char *s1, char *s2)
{
	char		*new;
	char		*tmp;
	int			i;
	int			res_len;

	if (!s1 && !s2)
		return (NULL);
	res_len = (ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char);
	if (!(new = (char *)malloc(res_len)))
		return (NULL);
	i = 0;
	while (i < res_len)
		*(new + i++) = (char)0;
	tmp = new;
	i = 0;
	while (s1 && s1[i] != '\0')
		*(new++) = s1[i++];
	if (s1)
		free(s1);
	while (s2 && *s2 != '\0')
		*(new++) = *(s2++);
	return (tmp);
}

static void	ft_free_for_cut(char *cached)
{
	if (cached)
		free(cached);
}

char		*ft_cut_after_endl(char *cached)
{
	char	*res;
	int		i;

	i = 0;
	i = ft_govno_len(cached, NULL, 0);
	if (!(res = (char*)malloc(sizeof(char) * (i + 1))))
	{
		ft_free_for_cut(cached);
		return (NULL);
	}
	i = ft_govno_len(cached, res, 1);
	res[i] = '\0';
	return (res);
}

char		*ft_cut_before_endl(char *cached)
{
	char	*res;
	char	*copy;
	int		j;

	if (!cached)
		return (NULL);
	j = 0;
	copy = cached;
	while (*copy != '\0' && *copy != '\n')
		++copy;
	if (*copy++ == '\0')
	{
		ft_free_for_cut(cached);
		return (NULL);
	}
	j = 0;
	while (copy[j])
		++j;
	if (!(res = (char*)malloc(sizeof(char) * (j + 1))))
	{
		ft_free_for_cut(cached);
		return (NULL);
	}
	return (ft_govno_code(cached, res, copy - cached));
}
