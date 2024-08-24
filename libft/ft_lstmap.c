/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:37:18 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/06/17 11:08:42 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * <cat>list</cat>
 * <summary>
 *	t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
 * </summary>
 *
 * <description>
 * 	ft_lstmap apply a function on eatch element of the linked list and save the
 * 	modification on a new linked list. the del function is just to delete if
 * 	it's necesary.
 * </description>
 *
 * <param type="t_list *" name="lst">list of linked list to modify</param>
 * <param type="void *" name="*f">function to apply mod (void *)</param>
 * <param type="void" name="*del">del function  (void *)</param>
 *
 * <return>
 * 	a new linked list or NULL if allocation fail.
 * </return>
 *
 */

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*tmplst;

	if (!lst)
		return (NULL);
	newlst = NULL;
	while (lst)
	{
		tmplst = ft_lstnew(f(lst->content));
		if (!tmplst)
		{
			ft_lstclear(&lst, del);
			return (NULL);
		}
		ft_lstadd_back(&newlst, tmplst);
		lst = lst->next;
	}
	return (newlst);
}
