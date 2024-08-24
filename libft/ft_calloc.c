/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 13:47:01 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/06/17 11:08:21 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * <cat>memory</cat>
 *
 * <summary>
 *	void	*ft_calloc(size_t nmemb, size_t size)
 * </summary>
 *
 * <description>
 *	ft_calloc allocate memory and set all byte to 0. check the overflow of
 *	int_max for malloc.
 * </description>
 *
 * <param type="size_t" name="nmemb">number of member</param>
 * <param type="size_t" name="size">size in byte of a member</param>
 *
 * <return>
 *	if nmemb or size == 0 => NULL
 *	else => a pointeur with (nmemb * size) byte to 0.
 * </return>
 *
 */

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	size_total;
	void	*ptr;

	size_total = nmemb * size;
	if (size_total == 0)
		return (malloc(1 * sizeof(char)));
	if (size_total > SIZE_MAX)
		return (NULL);
	ptr = malloc(size_total);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, size_total);
	return (ptr);
}
