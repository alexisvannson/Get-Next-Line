/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avannson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 09:50:28 by avannson          #+#    #+#             */
/*   Updated: 2025/01/12 12:50:18 by avannson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(int argc, char **argv)
{
	char	*line;
	int		fd;

	if (argc != 2)
		return (-1);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (-1);
	line = get_next_line(fd);
	while (line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}

/*char	*get_next_line(int fd)
{
	int		reader;
	static char*	stash;
	char	*new_stash;
	char	*line;
	char	*buffer;
	char	*temp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	if (!stash)
		stash = ft_strdup("");
	if (!stash)
	{
		free(buffer);
		return (NULL);
	}
	reader = BUFFER_SIZE;
	while (!(is_in(stash, '\n')) && (reader == BUFFER_SIZE))
	{
		reader = read(fd, buffer, BUFFER_SIZE);
		if (reader < 0)
			return (free(buffer), free(stash), stash = NULL, NULL);
		{
			free(buffer);
			free(stash);
			stash = NULL;
			return (NULL);
		}
		buffer[reader] = '\0';
		temp = ft_strjoin(stash, buffer);
		if (!temp)
		{
			free(buffer);
			free(stash);
			stash = NULL;
			return (NULL);
		}
		free(stash);
		stash = temp;
	}
	if (reader == 0 && (!stash || !stash[0]))
	{
		free(stash);
		free(buffer);
		stash = NULL;
		return (NULL);
	}
	line = ft_getline(stash);
	if (!line)
	{
		free(stash);
		free(buffer);
		stash = NULL;
		return (NULL);
	}
	new_stash = ft_keep(stash, '\n');
	free(stash);
	stash = new_stash;
	free(buffer);
	return (line);
}*/