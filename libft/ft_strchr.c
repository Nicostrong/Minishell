/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 13:41:33 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/06/17 11:08:59 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * <cat>str</cat>
 *
 * <summary>
 *	char	*ft_strchr(const char *s, int c)
 * </summary>
 *
 * <description>
 *	ft_strchr chearch the first occurence of the char c and return a pointer
 *	to this occurence.
 * </description>
 *
 * <param type="const void *" name="s">string to parce</param>
 * <param type="int" name="c">char to find</param>
 *
 * <return>
 *	a pointer to the first occurence of the char c or 0 if the char c not in
 *	the string.
 * </return>
 *
 */

char	*ft_strchr(const char *s, int c)
{
	while (*s && *s != (char)c)
		s++;
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}
