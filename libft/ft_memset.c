/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 09:48:29 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/06/17 11:08:51 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * <cat>memory</cat>
 *
 * <summary>
 *	void	*ft_memset(void *s, int c, size_t n)
 * </summary>
 *
 * <description>
 *	ft_memset fills the n first bytes of memory pointed by s with the value
 *	of c.
 * </description>
 *
 * <param type="void *" name="s">memory area to fills</param>
 * <param type="int" name="c">value of fill</param>
 * <param type="size_t" name="n">number of byte to fills</param>
 *
 * <return>
 *	void *.
 * </return>
 *
 */

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*str;

	str = (unsigned char *)s;
	while (n--)
		*str++ = c;
	return (s);
}
