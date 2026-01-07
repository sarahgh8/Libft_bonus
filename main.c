#include "libft.h"

void lstprint(t_list *head)
{
    t_list *temp;

    temp = head;
    while(temp)
    {
        printf("%d ", *((int *)temp->content));
        temp = temp->next;
    }
    printf("\n");
}

void fun(void *c)
{
    *(int *)c *= 2;
}

void *fu(void *c)
{
    int *new = malloc(sizeof(int));
    *new = *(int *)c * 2;
    return new;
}

void use_delone(t_list **head, void (*del)(void *))
{
    t_list *delnode = *head;
    *head = (*head)->next;
    ft_lstdelone(delnode, del);
}

int main()
{
    int *num;
    int i;
    t_list *head;
    t_list *new_node;

    head = NULL;
    i = 1;
    while(i <= 5)
    {
        num = malloc(sizeof(int));
        *num = i;
        new_node = ft_lstnew(num);
        ft_lstadd_back(&head, new_node);
        i++;
    }
    lstprint(head);
    ft_lstiter(head, fun);
    lstprint(head);

    t_list *new_list = ft_lstmap(head, fu, free);
    lstprint(new_list);

    printf("%d\n", ft_lstsize(head));

    int *ft;

    ft = malloc(sizeof(int));
    *ft = 42;
    t_list *test_node = ft_lstnew(ft);
    ft_lstadd_front(&new_list, test_node);
    lstprint(new_list);


    use_delone(&head, free);
    lstprint(head);

    ft_lstclear(&head, free);
    ft_lstclear(&new_list, free);
    return 0;
}