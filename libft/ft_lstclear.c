/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 13:16:45 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/06/17 11:08:37 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * <cat>list</cat>
 *
 * <summary>
 *	void	ft_lstclear(t_list **lst, void (*del)(void *))
 * </summary>
 *
 * <description>
 * 	ft_lstclear del and free memory of eatch element of the linked list.  It set
 * 	the original pointer at NULL.
 * </description>
 *
 * <param type="t_list **" name="lst">list of linked list</param>
 * <param type="void *" name="f">del function (void *)</param>
 *
 * <return>
 * 	void.
 * </return>
 *
 */

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current_lst;
	t_list	*next_lst;

	if (!lst)
		return ;
	current_lst = *lst;
	while (current_lst)
	{
		next_lst = current_lst->next;
		ft_lstdelone(current_lst, del);
		current_lst = next_lst;
	}
	*lst = NULL;
}
