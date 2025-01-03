/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   baseline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avannson  <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 18:00:07 by avannson          #+#    #+#             */
/*   Updated: 2025/01/03 22:30:13 by avannson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>


typedef struct Node {
    char    c;
    int count;              
    struct Node* next;
} Node;

Node* createNode(char c) 
{
    Node* newNode = (Node*)malloc(sizeof(Node)); //a proteger plus tard mais doit tjrs rendre une node 
    newNode->c = c;
    newNode->count = 0;
    newNode->next = 0;
    return newNode;
}

void insertAtTail(Node** head, char c) 
{
    Node* newNode = createNode(c);
    if (*head == 0) 
    {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != 0) 
        temp = temp->next;
    temp->next = newNode;
}

// Function to traverse and print the list
void get_string(Node* head, char *str)
{
    Node* temp; 
    int i;
    char c;
    
    i = 0;
    temp = head;
    while (temp != 0) 
    {
        str[i] = temp->c;
        i++;
        temp = temp->next;
    }
}

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

char	*ft_display_line(char *filename)
{
	int		fd;
	int		read_items;
    int     nb_nodes;
	char	*buffer;
    char    *str;
    Node* head;

	read_items = 1;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("Cannot read file.\n");
		return(0);
	}
    head = createNode(read(fd, (void*) buffer, 1)); //initialiser la liste chainée; incompatible integer to pointer conversion passing 'char' to parameter of type 'void *' 
    nb_nodes = 1;
    
	while ((read_items > 0) && (buffer[0] != '\n'))
	{
		read_items = read(fd, buffer, 1);
        insertAtTail(&head, *buffer);
        nb_nodes++;
	}
    str = malloc(nb_nodes *sizeof(char));
    get_string(head, str);
	if (read_items == -1)
	{
		close(fd);
		ft_putstr("Cannot read file.\n");
	}
	close(fd);
    return(str);
}

/*int main(void)
{
    char *str = "sayee";
    int i;
    int nodeCount = 0;
    Node* head;
    
    

    i = 1;
    head = createNode(str[0]);
    while (str[i])
    {
        insertAtTail(&head, str[i]);
        i++;
    }
    printList(head);
}
*/


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
	ft_putstr((argv[1]));
	return (0);
}