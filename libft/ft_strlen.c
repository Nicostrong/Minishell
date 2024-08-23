/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 08:33:54 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/06/17 11:09:36 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * <cat>str</cat>
 *
 * <summary>
 *	size_t	ft_strlen(const char *s)
 * </summary>
 *
 * <description>
 *	ft_strlen count the number of bytes on the string s without the '\0'
 * </description>
 *
 * <param type="const char *" name="s">string to evaluate</param>
 *
 * <return>
 *	number of bytes in the string without the null terminate char.
 * </return>
 *
 */

size_t	ft_strlen(const char *s)
{
	size_t	nb_bytes;

	if (!s)
		return (0);
	nb_bytes = 0;
	while (*s++)
		nb_bytes++;
	return (nb_bytes);
}
