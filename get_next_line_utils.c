/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avannson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 09:23:39 by avannson          #+#    #+#             */
/*   Updated: 2025/01/12 12:56:06 by avannson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*final;

	final = malloc(ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1);
	if (!final)
		return (0);
	i = 0;
	j = 0;
	while (s1[i])
	{
		final[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		final[i + j] = s2[j];
		j++;
	}
	final[i + j] = '\0';
	return (final);
}
/*
char	*ft_strrchr(const char *s, int c)
{
	char	*last_occurrence;

	last_occurrence = NULL;
	while (*s)
	{
		if (*s == (unsigned char)c)
			last_occurrence = (char *)s;
		s++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)s);
	return (last_occurrence);
}*/

char	*ft_keep(const char *str, int search_str)
{
	while (*str)
	{
		if (*str == (char)search_str)
		{
			str++;
			return ((char *)str);
		}
		str++;
	}
	return (0);
}

char	*ft_strdup(const char *s1)
{
	char	*cpy;
	int		i;

	i = 0;
	while (s1[i])
		i++;
	cpy = malloc(i + 1);
	if (!cpy)
		return (0);
	i = 0;
	while (s1[i])
	{
		cpy[i] = s1[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}
