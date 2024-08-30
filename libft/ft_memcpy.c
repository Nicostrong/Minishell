/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 09:48:29 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/08/30 09:18:19 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * <cat>memory</cat>
 *
 * <summary>
 *	void	*ft_memcpy(void *dest, const void *src, size_t n)
 * </summary>
 *
 * <description>
 *	ft_memcpy copy n bytes from memory area src to memory area dest.
 *	it check if memory area are overlap.
 * </description>
 *
 * <param type="void *" name="dest">memory area of destination</param>
 * <param type="const void *" name="src">source of memory area</param>
 * <param type="size_t" name="n">number of byte to copy</param>
 *
 * <return>
 *	void *.
 * </return>
 *
 */

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	if (!dest || !src)
		return (NULL);
	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	while (n--)
		*d++ = *s++;
	return (dest);
}
