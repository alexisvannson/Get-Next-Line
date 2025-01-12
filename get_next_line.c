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
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>


int is_in(char *str, char c)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (str[i] == c)
            return (1);
        i++;
    }
    return (0);
}

char	*ft_getline(char* stash)
{
	int	i;
	char*	line;

	i = 0;
	while (stash[i] != '\n')
		i++;
	line = malloc((i + 2) * sizeof(char));
	if (!line)
		return(0);
	i = 0;
	while (stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	line[i] = '\n';
	line[i + 1] = '\0';
	return(line);
}

char *get_next_line(int fd)
{
	static char*	stash;
	char	*line;
	char	*buffer;
	char	*temp;
	int	reader;

	if (fd <= 0 || BUFFER_SIZE <= 0)
	{
		return(0);
	}
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return(0);
	if (!stash)
		stash = ft_strdup("");
	reader = BUFFER_SIZE;
	while(!(is_in(stash,'\n')) && (reader == BUFFER_SIZE))
	{
		reader = read(fd, buffer, BUFFER_SIZE);
		if (reader < 0)
		{
			free(buffer);
			return (0);
		}
		buffer[reader] = '\0';
		temp = ft_strjoin(stash, buffer);
		if (!temp)
		{
			free(buffer);
			free(stash);
			return(0);
		}
		free(stash);
		stash = temp;
		//check si le malloc a fail et free 
	}
	line = ft_getline(stash);
	stash = ft_keep(stash, '\n');//modif pour remonter le reste plutot que de creer une nouvelle addresse
	free(buffer);
	return(line);
}

int main(int argc, char **argv)
{
    char    *line;
    int     fd;
    
    if (argc == 1)
    {
        return (-1);
    }
    if (argc > 2)
    {
        return (-1);
    }

    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
    {
        return (-1);
    }
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s",line);
        //free(line);
    }

    close(fd);
    return (0);
}

