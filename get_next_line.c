/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avannson  <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 13:50:07 by avannson          #+#    #+#             */
/*   Updated: 2024/12/05 01:40:40 by avannson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int get_len(int fd)
{
    int		read_items;
	void	*c;
    int     count;
    
    count = 0;
    c = 0;
	read_items = 1;
    while (read_items > 0)
	{
		read_items = read(fd, c, 1);
        count++;
		if ((int)c == '\n')
            return (count); 
	}
    return(-1);
}

char    *get_next_line(int fd)
{
    char	*str;
    void    *c;
    int     len;
    int     reading;
    int     i;
    
    reading = 1;
    c = 0;
    len = get_len(fd);
    str = malloc((len + 1) * sizeof(char));
    if (!str)
        return (0);
    i = 0;
    while (reading > 0)
	{
		reading= read(fd, c, 1);
        str[i] = (char)c;
        i++;
    }
    str[i] = '\0';
    return (str);
}

int     main(int argc, char **argv)
{
    int     fd;

    if (! argc)
        return (-1);
    fd = open(argv[1], O_RDONLY);
    printf("%s", get_next_line(fd));
    return (0);
}
