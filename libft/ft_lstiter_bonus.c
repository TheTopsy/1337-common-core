#include "libft.h"
void ft_lstiter(t_list *lst, void (*f)(void *))
{
	while(lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}
/*f(void *content)
{
	content = "00";
}
int main()
{
	
}*/
