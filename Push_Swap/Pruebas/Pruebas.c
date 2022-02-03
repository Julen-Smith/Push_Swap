
#include "Libft/libft.h"

typedef struct s_data
{
    int nbr;
    void *next;
} t_data;


void    ft_alloc_tree(t_data *head)
{
    int i = 0;
    
    while(&head[i])
    {
        if(&head[i+1] != NULL)
            head[i].next = (void *)head[i+1];
        i++;
    }
}
 


int main(int argc, char *argv[])
{
    t_data *head;

    head = malloc(sizeof(t_data) * 5);
    ft_alloc_tree(head);

    return (1);
}


