/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: topsy <adahab@student.1337.ma>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 18:57:51 by adahab            #+#    #+#             */
/*   Updated: 2024/11/10 18:57:52 by adahab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*n;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		n = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = (*lst)->next;
		*lst = n;
	}
	free(*lst);
}
/*void dl(void *content)
{
	free(content);
}
int	main(void)
{
	t_list **lst = malloc(sizeof(t_list));
		t_list *n1, *n2, *n3;

		*lst = malloc(sizeof(t_list));
		n1 = malloc(sizeof(t_list));
		n2 = malloc(sizeof(t_list));
		n3 = malloc(sizeof(t_list));

		(*lst)->next = n1;
		n1->next = n2;
		n2->next = NULL;

	n2->content = malloc(2);
		((char *)n2->content)[0] = '1';

	printf("%s\n", (char *)n2->content);

}*/
