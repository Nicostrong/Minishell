/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 13:41:58 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/08/22 14:59:17 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * <cat>str</cat>
 *
 * <summary>
 *	int	ft_strncmp(const char *s1, const char *s2, size_t n)
 * </summary>
 *
 * <description>
 *	ft_strncmp compare two strings at most n char.
 * </description>
 *
 * <param type="const void *" name="s1">string 1</param>
 * <param type="const void *" name="s2">string 2</param>
 * <param type="size_t" name="n">number of byte to compare</param>
 *
 * <return>
 *	0, if s1 == s2,
 *	a positive value if s1 < s2,
 *	a negative value if s1 > s2.
 * </return>
 *
 */

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	index;

	index = 0;
	if (n == 0)
		return ((unsigned char)0);
	while (*s1 == *s2 && (n - index) > 1)
	{
		s1++;
		s2++;
		index++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}
