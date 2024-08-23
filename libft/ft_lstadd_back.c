/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 08:12:32 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/06/17 11:08:35 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * <cat>list</cat>
 *
 * <summary>
 *	void	ft_lstadd_back(t_list **lst, t_list *new)
 * </summary>
 *
 * <description>
 *	ft_lstadd_back add a new list at the end of the liked list.
 * </description>
 *
 * <param type="t_list **" name="lst">list of linked list</param>
 * <param type="t_list *" name="new">list to add</param>
 *
 * <return>
 * 	void.
 * </return>
 *
 */

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (!new)
		return ;
	if (*lst)
		ft_lstlast(*lst)->next = new;
	else
		*lst = new;
}
