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

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int			i;
	int			j;
	char		*final;
	size_t		total_len;

	if (!s1 || !s2)
		return (NULL);
	total_len = ft_strlen(s1) + ft_strlen(s2);
	final = malloc((total_len + 1) * sizeof(char));
	if (!final)
		return (NULL);
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

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t		i;
	size_t		src_len;

	i = 0;
	src_len = 0;
	while (src[src_len])
		src_len++;
	if (size == 0)
		return (src_len);
	while (src[i] && i < (size - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}

char	*ft_keep(char *str, int search_str)
{
	char	*remainder;
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (str[i] && str[i] != (char)search_str)
		i++;
	if (str[i] == (char)search_str)
		i++;
	len = ft_strlen(&str[i]);
	remainder = malloc(sizeof(char) * (len + 1));
	if (!remainder)
		return (NULL);
	ft_strlcpy(remainder, &str[i], len + 1);
	return (remainder);
}

char	*ft_strdup(const char *s1)
{
	char	*cpy;
	int		i;

	if (!s1)
		return (NULL);
	i = 0;
	while (s1[i])
		i++;
	cpy = malloc((i + 1) * sizeof(char));
	if (!cpy)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		cpy[i] = s1[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}
