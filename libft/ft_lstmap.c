/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byan <byan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 07:31:12 by byan              #+#    #+#             */
/*   Updated: 2022/01/15 07:58:34 by byan             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*tmp;

	if (lst == 0)
		return (0);
	tmp = ft_lstnew(f(lst -> content));
	if (tmp == 0)
		return (0);
	lst = lst -> next;
	head = tmp;
	while (lst)
	{
		ft_lstadd_back(&tmp, ft_lstnew(f(lst -> content)));
		tmp = tmp -> next;
		if (tmp == 0)
		{
			ft_lstclear(&head, del);
			return (0);
		}
		lst = lst -> next;
	}
	return (head);
}
