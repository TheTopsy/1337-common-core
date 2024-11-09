#include "libft.h"

int ft_lstsize(t_list *lst)
{
	int	i;
	t_list *n;

	n = lst;
	i = 0;
	while(n)
	{
		i++;
		n = n->next;
	}
	return i;
}/*
int main()
{
	t_list *lst;
	t_list *n1, *n2, *n3;
	
	lst = malloc(sizeof(t_list));
	n1 = malloc(sizeof(t_list));
	n2 = malloc(sizeof(t_list));
	n3 = malloc(sizeof(t_list));
	
	lst->next = n1;
	n1->next = n2;
	n2->next = n3;
	n3->next = NULL;

	printf("%d\n", ft_lstsize(lst));
}*/
