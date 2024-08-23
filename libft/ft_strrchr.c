/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 13:41:44 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/06/17 11:09:54 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * <cat>str</cat>
 *
 * <summary>
 *	char	*ft_strrchr(const char *s, int c)
 * </summary>
 *
 * <description>
 *	ft_strchr chearch the last occurence of the char c and return a pointer
 *	to this occurence.
 * </description>
 *
 * <param type="const void *" name="s">string to parce</param>
 * <param type="int" name="c">char to find</param>
 *
 * <return>
 *	a pointer to the last occurence of the char c or 0 if the char c not in
 *	the string.
 * </return>
 *
 */

char	*ft_strrchr(const char *s, int c)
{
	char	*last;

	last = NULL;
	if (c > 127)
		return ((char *)s);
	while (*s)
	{
		if (*s == c)
			last = (char *)s;
		s++;
	}
	if (*s == c)
		return ((char *)s);
	return (last);
}
