#include "libft.h"
t_list *ft_lstmap(t_list *lst, void *(*f)(void *),void (*del)(void *))
{
	t_list *n;
	t_list *nlst;
	
	if (!f || !lst)
		return (NULL);
	nlst = NULL;

	while(lst)
	{
		n = ft_lstnew(f(lst->content));
		if (!n)
		{
			ft_lstclear(&n, (*del));
			return (NULL);
		}
		ft_lstadd_back(&nlst, n);
		lst = lst->next;
	}
	return (nlst);
}
