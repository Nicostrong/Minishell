/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 13:31:10 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/06/17 11:08:50 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * <cat>memory</cat>
 *
 * <summary>
 *	void	*ft_memmove(void *dst, const void *src, size_t n)
 * </summary>
 *
 * <description>
 *	ft_memmove copy n bytes from memory area src to tempory memory area.
 *	it check if memory area are overlap.
 *	//!\\ n max == ft_strlen(src) + 1 //!\\
 * </description>
 *
 * <param type="void *" name="dst">memory area of destination</param>
 * <param type="const void *" name="src">source of memory area</param>
 * <param type="size_t" name="n">number of byte to copy</param>
 *
 * <return>
 *	void *.
 * </return>
 *
 */

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	if (!dst && ! src)
		return (NULL);
	if (dst < src)
		return (ft_memcpy(dst, src, n));
	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	while (n--)
		*(d + n) = *(s + n);
	return (dst);
}
