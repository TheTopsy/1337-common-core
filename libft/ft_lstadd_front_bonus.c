#include "libft.h"

void ft_lstadd_front(t_list **lst, t_list *new)
{
	if(!new)
		return ;
	if (!lst)
	{
		*lst = new;
		return ;
	}
	new->next = *lst;
	*lst = new;
}/*
int main()
{
	t_list **lst = malloc(sizeof(t_list));
	t_list *new = malloc(sizeof(t_list));
	
	ft_lstadd_front(lst, new);
	new->content = "afh";
	printf("%s\n", (char *)lst[0]->content);
}*/
