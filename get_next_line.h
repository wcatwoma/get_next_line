/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcatwoma <wcatwoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 21:14:46 by wcatwoma          #+#    #+#             */
/*   Updated: 2021/02/08 23:10:35 by wcatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

# include <unistd.h>
# include <stdlib.h>

int			get_next_line(int fd, char **line);
int			ft_strlen(const char *s);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_cut_after_endl(char *tmp);
char		*ft_cut_before_endl(char *tmp);
char		*ft_govno_code(char *cached, char *res, int i);
int			ft_govno_len(const char *s, char *res, int i);

#endif
