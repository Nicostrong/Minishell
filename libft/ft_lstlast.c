/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 17:39:42 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/06/17 11:08:41 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * <cat>list</cat>
 *
 * <summary>
 * 	t_list	*ft_lstlast(t_list *lst)
 * </summary>
 *
 * <description>
 * 	ft_lstlast loop over the linked list to finc the last list.
 * </description>
 *
 * <param type="t_list *" name="lst">linked list</param>
 *
 * <return>
 * 	a pointer to the last list.
 * </return>
 *
 */

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
