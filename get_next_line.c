/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcatwoma <wcatwoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 21:14:39 by wcatwoma          #+#    #+#             */
/*   Updated: 2021/02/08 23:09:56 by wcatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char		*ft_govno_code(char *cached, char *res, int i)
{
	int		j;

	j = 0;
	while (cached[i])
		res[j++] = cached[i++];
	res[j] = '\0';
	free(cached);
	return (res);
}

int			ft_govno_len(const char *s, char *res, int i)
{
	int	size;

	if (!s)
		return (0);
	size = 0;
	while (s[size] != '\n' && s[size])
	{
		if (i == 1)
			res[size] = s[size];
		++size;
	}
	return (size);
}

static int	ft_safe_free(char *cached, char *buf, int res)
{
	if (cached)
		free(cached);
	if (buf)
		free(buf);
	return (res);
}

static int	ft_endl_search(char *cached)
{
	char	*copy;

	if (!cached)
		return (1);
	copy = cached;
	while (*copy)
	{
		if (*copy == '\n')
			return (0);
		++copy;
	}
	return (1);
}

int			get_next_line(int fd, char **line)
{
	static char		*cached;
	char			*buf;
	int				r;

	if (!(buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1)))
			|| fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	r = 42;
	while (r > 0 && ft_endl_search(cached))
	{
		r = read(fd, buf, BUFFER_SIZE);
		if (r == -1)
			return (ft_safe_free(cached, buf, -1));
		buf[r] = '\0';
		cached = ft_strjoin(cached, buf);
		if (cached == NULL)
			return (ft_safe_free(cached, buf, -1));
	}
	free(buf);
	if (!(*line = ft_cut_after_endl(cached)))
		return (-1);
	cached = ft_cut_before_endl(cached);
	return ((r == 0) ? 0 : 1);
}
