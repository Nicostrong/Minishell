/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 13:40:51 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/06/17 11:09:07 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * <cat>str</cat>
 *
 * <summary>
 *	size_t	ft_strlcpy(char *dst, const char *src, size_t size)
 * </summary>
 *
 * <description>
 *	ft_strlcpy copy a src string to dest. It take the full size of the
 *	buffer and add the NULL-terminate char.
 * </description>
 *
 * <param type="char *" name="dst">pointer of destination</param>
 * <param type="const char *" name="src">pointer of sourcing</param>
 * <param type="size_t" name="n">size of dest</param>
 *
 * <return>
 *	the lenth of src without '\0'.
 * </return>
 *
 */

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t		len;

	len = ft_strlen(src);
	if (!dst || !src)
		return (0);
	if (size != 0)
	{
		while ((1 < size--) && *src)
			*dst++ = *src++;
		*dst = 0;
	}
	return (len);
}
