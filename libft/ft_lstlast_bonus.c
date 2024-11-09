#include "libft.h"

t_list *ft_lstlast(t_list *lst)
{
	if(!lst)
		return (NULL);
	while(lst->next)
		lst = lst->next;
	return (lst);
}
/*
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
        n2->next = NULL;
	n2->content = "kkkkk0";

        n3 = ft_lstlast(lst);
	if(n3)
        	printf("%s", (char *)n3->content);
	else
		printf("null\n");
}*/
