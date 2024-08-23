/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 09:01:52 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/06/17 11:08:38 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * <cat>list</cat>
 *
 * <summary>
 * 	void	ft_lstdelone(t_list *lst, void (*del)(void *))
 * </summary>
 *
 * <description>
 * 	ft_lstdelone remove of the linked list the element lst in calling the
 * 	function del. this function free corectely the list.
 * </description>
 *
 * <param type="t_list *" name="lst">list of linked list to del</param>
 * <param type="void *" name="del">dellist function with param (void *)</param>
 *
 * <return>
 * 	void.
 * </return>
 *
 */

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst)
		return ;
	del(lst->content);
	free(lst);
}
