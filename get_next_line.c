/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avannson  <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 13:50:07 by avannson          #+#    #+#             */
/*   Updated: 2024/12/04 14:47:26 by avannson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char    *get_next_line(int fd)
{
    int		read_items;
    char	buffer;

    read_items = 1;
	if (fd == -1)
	{
		ft_putstr("Cannot read file.\n");
		return ;
	}
    while (read_items > 0)
	{
		read_items = read(fd, buffer, 1);
		if (buffer == '\n')
            break;
	}
}

#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 20

void	ft_putstr(char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		write(1, &src[i], 1);
		i++;
	}
}

void	ft_display_file(char *filename)
{
	int		fd;
	int		read_items;
	char	buffer[BUFFER_SIZE];
    

	read_items = 1;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("Cannot read file.\n");
		return ;
	}
	while (read_items > 0)
	{
		read_items = read(fd, buffer, BUFFER_SIZE);
		write(1, buffer, read_items);
	}
	if (read_items == -1)
	{
		close(fd);
		ft_putstr("Cannot read file.\n");
	}
	close(fd);
}

int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		ft_putstr("File name missing.\n");
		return (-1);
	}
	if (argc > 2)
	{
		ft_putstr("Too many arguments.\n");
		return (-1);
	}
	ft_display_file(argv[1]);
	return (0);
}