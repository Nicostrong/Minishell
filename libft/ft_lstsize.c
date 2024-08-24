/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 17:34:07 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/06/17 11:08:45 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * <cat>list</cat>
 *
 * <summary>
 * 	int	ft_lstsize(t_list *lst)
 * </summary>
 *
 * <description>
 * 	ft_lstsize cunt the number of list in lst.
 * </description>
 *
 * <param type="t_list *" name="lst">linked list</param>
 *
 * <return>
 * 	number of list.
 * </return>
 *
 */

int	ft_lstsize(t_list *lst)
{
	int	len;

	len = 0;
	while (lst)
	{
		lst = lst->next;
		len++;
	}
	return (len);
}
