#include"libft.h"

void    ft_lstadd_back(t_list **lst, t_list *new)
{
    if (!lst || !new)
        return ;
    if (*lst)
        ft_lstlast(*lst)->next = new;
    else
        *lst = new;
}
/*void ft_lstadd_back(t_list **lst, t_list *new)
{
	if(!new)
		return ;
	if(!lst)
	{
		*lst = new;
		return ;
	}
	while((*lst)->next)
	{
		*lst = (*lst)->next;
	}
	(*lst)->next = new;
}
int main()
{
        t_list **lst = malloc(sizeof(t_list));
        t_list *n1, *n2, *n3, *new;

        *lst = malloc(sizeof(t_list));
        n1 = malloc(sizeof(t_list));
        n2 = malloc(sizeof(t_list));
        n3 = malloc(sizeof(t_list));
	new = malloc(sizeof(t_list)); 

        (*lst)->next = n1;
        n1->next = n2;
        n2->next = NULL;
	
	new->content = "abcbahede";
        
	ft_lstadd_back(lst, new);
	
	*lst = (*lst)->next;
	n3 = *lst;
        
	printf("%s\n", (char *)n3->content);
}*/
