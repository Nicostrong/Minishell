/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:16:30 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/08/30 09:09:36 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * <cat>str</cat>
 *
 * <summary>
 *	char	*ft_substr(char const *s, unsigned int start, size_t len)
 * </summary>
 *
 * <description>
 *	ft_substr creat a new string from the string s at the index start for 
 *	len char. the pointer is allocated with malloc.
 * </description>
 *
 * <param type="char const *" name="s">string to substring</param>
 * <param type="unsigned int" name="start">start index of new string</param>
 * <param type="size_t" name="len">len of new string</param>
 *
 * <return>
 *	a pointer to the new string or NULL if allocation faill.
 * </return>
 *
 */

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	index;
	size_t	len_new;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	len_new = ft_strlen(s) - start + 1;
	if (len_new > len)
		len_new = len + 1;
	new = (char *)malloc(len_new * sizeof(char));
	if (!new)
		return (NULL);
	index = 0;
	while (len-- && s[start])
		new[index++] = s[start++];
	new[index] = 0;
	return (new);
}
