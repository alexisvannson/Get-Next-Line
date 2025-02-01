/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avannson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 09:03:27 by avannson          #+#    #+#             */
/*   Updated: 2025/01/12 12:59:54 by avannson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	is_in(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_getline(char *stash)
{
	int		i;
	char	*line;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		line = malloc((i + 2) * sizeof(char));
	else
		line = malloc((i + 1) * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (stash[i] && (stash[i] != '\n'))
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*read_and_store(int fd, char **stash)
{
	char	*buffer;
	char	*temp;
	int		reader;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	reader = BUFFER_SIZE;
	while (!is_in(*stash, '\n') && reader == BUFFER_SIZE)
	{
		reader = read(fd, buffer, BUFFER_SIZE);
		if (reader < 0)
			return (free(buffer), free(*stash), *stash = NULL, NULL);
		buffer[reader] = '\0';
		temp = ft_strjoin(*stash, buffer);
		if (!temp)
			return (free(buffer), free(*stash), *stash = NULL, NULL);
		free(*stash);
		*stash = temp;
	}
	free(buffer);
	return (*stash);
}

char	*extract_line(char **stash)
{
	char	*line;
	char	*new_stash;

	if (!*stash || !(*stash)[0])
		return (free(*stash), *stash = NULL, NULL);
	line = ft_getline(*stash);
	if (!line)
		return (free(*stash), *stash = NULL, NULL);
	new_stash = ft_keep(*stash, '\n');
	free(*stash);
	*stash = new_stash;
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*stash;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!stash)
		stash = ft_strdup("");
	if (!stash)
		return (NULL);
	if (!read_and_store(fd, &stash))
		return (NULL);
	return (extract_line(&stash));
}
