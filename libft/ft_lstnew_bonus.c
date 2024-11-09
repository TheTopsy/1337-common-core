#include "libft.h"
//#include<stdlib.h>
//#include<stdio.h>

t_list	*ft_lstnew(void *content)
{
	t_list	*node1;
	
	node1 = (t_list *)malloc(sizeof(t_list));
	if(!node1)
		return NULL;
	node1->content = content;
	node1->next = NULL;

	return (node1);
}
