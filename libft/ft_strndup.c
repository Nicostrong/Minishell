/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 13:17:10 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/09/04 13:30:02 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * <cat>str</cat>
 *
 * <summary>
 *	char	*ft_strndup(const char *s, int nbr_char)
 *</summary>
 *
 * <description>
 *	ft_strndup duplicate n char of the string pointed by s to a new pointer.
 * </description>
 *
 * <param type="const char *" name="s">string to duplicate</param>
 * <param type="size_t" name="nbr_char">nubber of char to dup</param>
 *
 * <return>
 *	a new string where n char werre coping on memory area allocated with malloc.
 * </return>
 *
 */

char	*ft_strndup(const char *s, size_t nbr_char)
{
	char	*cpy;
	size_t	len_s;

	if (!s)
		return (NULL);
	len_s = ft_strlen(s);
	if (nbr_char > len_s)
		nbr_char = len_s;
	cpy = (char *)ft_calloc(nbr_char + 1, sizeof(char));
	if (!cpy)
		return (NULL);
	cpy = ft_memcpy(cpy, s, nbr_char);
	cpy[nbr_char] = 0;
	return (cpy);
}
