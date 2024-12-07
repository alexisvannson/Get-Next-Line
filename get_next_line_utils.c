/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avannson  <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 14:21:34 by avannson          #+#    #+#             */
/*   Updated: 2024/12/07 23:25:32 by avannson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


// sayeee

/*
void	ft_display_line(char *filename)
{
	int		fd;
	int		read_items;
	char	str;
    

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
}*/