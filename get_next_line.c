/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avannson  <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 13:50:07 by avannson          #+#    #+#             */
/*   Updated: 2024/12/05 11:24:06 by avannson         ###   ########.fr       */
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
    uintptr_t val;
    
    count = 0;
    c = 0;
	read_items = 1;
    while (read_items > 0)
	{
		read_items = read(fd, c, 1);
        count++;
        val = (uintptr_t) c ;
		if (val == '\n')
            return (count); 
	}
    return(-1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

size_t	ft_strlcat(char *dest, const char *src, size_t len)
{
	size_t	dest_len;
	size_t	src_len;
	size_t	i;

	if (!dest || !src)
		return (0);
	dest_len = ft_strlen(dest);
	src_len = ft_strlen((char *)src);
	// If `len` is smaller than or equal to the length of `dest`, return `len + src_len`
	if (len <= dest_len)
		return (len + src_len);

	// Start appending from the end of `dest`
	i = 0;
	while (src[i] && (dest_len + i < len - 1))
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';

	return (dest_len + src_len);
}

char    *get_next_line(int fd)
{
    char	*str;
    void    *c;
    int     len;
    int     reading;
    size_t  i;
    
    reading = 1;
    c = 0;
    len = get_len(fd);
    str = malloc((len + 1) * sizeof(char));
    if (!str)
        return (0);
    while (reading > 0)
	{
		reading= read(fd, c, 1);
        i = ft_strlcat(str, c, 1);
        printf("reading %i wesh int %zu et c %s\n",reading, i, (char*)c);
    }
    printf(" sayee %s", str);
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
