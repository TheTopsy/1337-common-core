/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: topsy <adahab@student.1337.ma>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 18:56:14 by adahab            #+#    #+#             */
/*   Updated: 2024/11/10 18:57:27 by adahab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!new)
		return ;
	if (!lst)
	{
		*lst = new;
		return ;
	}
	new->next = *lst;
	*lst = new;
}
/*
 int main()
 {
		t_list **lst = malloc(sizeof(t_list));
		t_list *new = malloc(sizeof(t_list));

		ft_lstadd_front(lst, new);
		new->content = "afh";
		printf("%s\n", (char *)lst[0]->content);
 }*/
