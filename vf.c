#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

#define BUFFER_SIZE 20

typedef struct Node {
    char    *str;
    int     count;
    struct Node* next;
} Node;

char *ft_strdup(const char *s) 
{
    size_t  len;
    char    *dup;
    int     i;

    len = 0;
    while (s[len])
        len++;
    dup = malloc(sizeof(char) * (len + 1));
    if (!dup)
        return (NULL);
    i = 0;
    while (s[i])
    {
        dup[i] = s[i];
        i++;
    }
    dup[i] = '\0';
    return (dup);
}

char *ft_strconcat(char *s1, char *s2)
{
    char    *result;
    int     i;
    int     j;
    size_t  total_len;

    if (!s1)
        return (ft_strdup(s2));
    if (!s2)
        return (ft_strdup(s1));
    
    total_len = 0;
    while (s1[total_len])
        total_len++;
    i = 0;
    while (s2[i])
        i++;
    total_len += i;
    
    result = malloc(sizeof(char) * (total_len + 1));
    if (!result)
        return (NULL);
    
    i = 0;
    while (s1[i])
    {
        result[i] = s1[i];
        i++;
    }
    j = 0;
    while (s2[j])
    {
        result[i + j] = s2[j];
        j++;
    }
    result[i + j] = '\0';
    return (result);
}

Node* createNode(char *str)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode)
        return NULL;
    newNode->str = ft_strdup(str);
    if (!newNode->str)
    {
        free(newNode);
        return NULL;
    }
    newNode->count = 0;
    newNode->next = NULL;
    return newNode;
}

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

char *ft_substr(char *str, int start, int len)
{
    char    *result;
    int     i;
    int     str_len;

    if (!str)
        return (NULL);
    str_len = 0;
    while (str[str_len])
        str_len++;
    if (start >= str_len)
        return (ft_strdup(""));
    if (len > str_len - start)
        len = str_len - start;
    
    result = malloc(sizeof(char) * (len + 1));
    if (!result)
        return (NULL);
    
    i = 0;
    while (i < len && str[start + i])
    {
        result[i] = str[start + i];
        i++;
    }
    result[i] = '\0';
    return (result);
}

void insertAtTail(Node** head, char *str)
{
    Node* newNode = createNode(str);
    if (!newNode)
        return;
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

size_t ft_strlen(const char *str)
{
    size_t i;
    
    i = 0;
    while (str[i])
        i++;
    return (i);
}

void ft_putstr(char *src)
{
    if (src)
        write(1, src, ft_strlen(src));
}

char *str_from_List(Node* head)
{
    Node    *temp;
    char    *str;
    char    *temp_str;

    if (!head)
        return (NULL);
    
    str = ft_strdup("");
    if (!str)
        return (NULL);
    
    temp = head;
    while (temp != NULL)
    {
        temp_str = ft_strconcat(str, temp->str);
        free(str);
        str = temp_str;
        temp = temp->next;
    }
    return (str);
}

void freeList(Node* head)
{
    Node* temp;
    
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp->str);
        free(temp);
    }
}

char *get_line_from_buffer(char *buffer, int *start_pos)
{
    int i;
    char *line;

    i = *start_pos;
    while (buffer[i] && buffer[i] != '\n')
        i++;
    
    if (buffer[i] == '\n')
    {
        line = ft_substr(buffer, *start_pos, i - *start_pos + 1);
        *start_pos = i + 1;
    }
    else
    {
        line = ft_substr(buffer, *start_pos, i - *start_pos);
        *start_pos = i;
    }
    return (line);
}

char *ft_display_line(int fd)
{
    static char     buffer[BUFFER_SIZE + 1];
    static int      start_pos = 0;
    static ssize_t  bytes_read = 0;
    Node            *head;
    char            *line;
    char            *temp;

    if (fd < 0)
        return (NULL);

    head = NULL;
    while (1)
    {
        if (start_pos >= bytes_read)
        {
            bytes_read = read(fd, buffer, BUFFER_SIZE);
            if (bytes_read <= 0)
                break;
            buffer[bytes_read] = '\0';
            start_pos = 0;
        }

        line = get_line_from_buffer(buffer, &start_pos);
        if (!head)
            head = createNode(line);
        else
            insertAtTail(&head, line);
        free(line);

        if (is_in(buffer + start_pos - 1, '\n'))
            break;
    }

    if (!head && bytes_read <= 0)
        return (NULL);

    temp = str_from_List(head);
    freeList(head);
    return (temp);
}

int main(int argc, char **argv)
{
    char    *line;
    int     fd;
    
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

    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
    {
        ft_putstr("Cannot read file.\n");
        return (-1);
    }

    while ((line = ft_display_line(fd)) != NULL)
    {
        ft_putstr(line);
        free(line);
    }

    close(fd);
    return (0);
}