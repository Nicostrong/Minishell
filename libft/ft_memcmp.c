/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 13:42:27 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/06/17 11:08:47 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * <cat>memory</cat>
 *
 * <summary>
 *	int	ft_memcmp(const void *s1, const void* s2, size_t n)
 * </summary>
 *
 * <description>
 *	ft_memcmp compare the n first byte of the memory area s1 with the memory
 *	area s2.
 * </description>
 *
 * <param type="const void *" name="s1">memory area 1</param>
 * <param type="const void *" name="s2">memory area 2</param>
 * <param type="size_t" name="n">number of byte to scan</param>
 *
 * <return>
 *	0 if no difference or more than 0 if different.
 * </return>
 *
 */

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*src1;
	unsigned char	*src2;
	size_t			index;

	src1 = (unsigned char *)s1;
	src2 = (unsigned char *)s2;
	index = 0;
	while (index < n)
	{
		if (src1[index] != src2[index])
			return (src1[index] - src2[index]);
		index++;
	}
	return (0);
}
