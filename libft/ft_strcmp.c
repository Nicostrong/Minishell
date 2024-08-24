/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 14:58:23 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/08/23 09:56:18 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * <cat>str</cat>
 *
 * <summary>
 *	int	ft_strcmp(const char *s1, const char *s2)
 * </summary>
 *
 * <description>
 *	ft_strcmp compare two strings completly.
 * </description>
 *
 * <param type="const void *" name="s1">string 1</param>
 * <param type="const void *" name="s2">string 2</param>
 *
 * <return>
 *	0, if s1 == s2,
 *	a positive value if s1 < s2,
 *	a negative value if s1 > s2.
 * </return>
 *
 */

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}
