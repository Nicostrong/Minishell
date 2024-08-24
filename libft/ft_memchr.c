/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 13:42:18 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/06/17 11:08:46 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * <cat>memory</cat>
 *
 * <summary>
 *	void	*ft_memchr(condt void *s, int c, size_t n)
 * </summary>
 *
 * <description>
 *	ft_memchr scan an area memory pointed by s on n bytes to find the char c.
 * </description>
 *
 * <param type="const void *" name="s">source of memory area</param>
 * <param type="int" name="c">char to find</param>
 * <param type="size_t" name="n">number of byte to scan</param>
 *
 * <return>
 *	a pointer to the matching byte or a NULL pointer no occurence matching.
 * </return>
 *
 */

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*area;

	area = (unsigned char *)s;
	while (n--)
	{
		if (*area == (unsigned char)c)
			return ((void *)area);
		area++;
	}
	return (NULL);
}
