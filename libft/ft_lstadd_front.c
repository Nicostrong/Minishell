/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 17:27:55 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/06/17 11:08:36 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * <cat>list</cat>
 *
 * <summary>
 *	void	ft_lstadd_front(t_list **lst, t_list *new)
 * </summary>
 *
 * <description>
 * 	ft_lstadd_front add a new list at the front of the liked list.
 * </description>
 *
 * <param type="t_list **" name="lst">list of linked list</param>
 * <param type="t_list *" name="new">list to add</param>
 *
 * <return>
 *	a pointer to a new list.
 * </return>
 *
 */

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!new)
		return ;
	new->next = *lst;
	*lst = new;
}
