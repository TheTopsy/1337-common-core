#include "libft.h"

void ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if(!lst)
		return ;
	if(del)
		del(lst->content);
	free(lst);
}
/*void dl(void *content)
{
	free(content);
}
int main()
{
	t_list *n = malloc(sizeof(t_list));
	
	n->content = malloc(2);
	((char *)n->content)[0] = '1';
	((char *)n->content)[1] = '\0';
        ft_lstdelone(n, dl);
        printf("%s\n", (char *)n->content);
}*/
