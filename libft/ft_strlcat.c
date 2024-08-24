/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 13:41:00 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/06/17 11:09:05 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * <cat>str</cat>
 *
 * <summary>
 *	size_t	ft_strlcat(char *dest, const char *src, size_t size)
 * </summary>
 *
 * <description>
 *	ft_strlcat concat two full C string (with '\0'). It take at the maximal
 *	the full size of dest - 1 (for '\0').
 *	ft_strlcat add (size - ft_strlen(dest) - 1) bytes and the '\0'.
 * </description>
 *
 * <param type="char *" name="dest">string of destination</param>
 * <param type="const char *" name="src">string to add at dest</param>
 * <param type="size_t" name="size">number of byte of final string</param>
 *
 * <return>
 *	if the buffer of dest is greather of size, it return size + len_dest.
 *	else it return tje total lentght of dest + src.
 * </return>
 *
 */

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	len_src;
	size_t	len_dest;
	size_t	index;

	len_src = ft_strlen(src);
	len_dest = ft_strlen(dest);
	if (size <= len_dest)
		return (len_src + size);
	index = 0;
	while (*src && (len_dest + index < size - 1))
		dest[len_dest + index++] = *src++;
	dest[len_dest + index] = 0;
	return (len_dest + len_src);
}
