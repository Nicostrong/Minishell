/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:28:38 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/06/17 11:08:40 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * <cat>list</cat>
 *
 * <summary>
 * 	void	ft_lstiter(t_list *lst, void (*f)(void *))
 * </summary>
 *
 * <description>
 * 	ft_lstiter iter the list and apply a function on eatch element of the list.
 * </description>
 *
 * <param type="t_list *" name="lst">list of linked list to del</param>
 * <param type="void *" name="f">function with param (void *)</param>
 *
 * <return>
 * 	void.
 * </return>
 *
 */

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}
