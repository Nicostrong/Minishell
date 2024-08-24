/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 14:05:18 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/06/17 11:09:04 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * <cat>str</cat>
 *
 * <summary>
 * 	char	*ft_strjoin(char const *s1, char const *s2)
 * </summary>
 *
 * <description>
 * 	ft_strjoin concat s1 and s2 in a new allocated string.
 * </description>
 *
 * <param type="const char *" name="s1">string 1</param>
 * <param type="const char *" name="s2">string 2</param>
 *
 * <return>
 * 	a pointer to the new string allocated with malloc.
 * </return>
 *
 */

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	size_t	index;
	char	*new;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	new = (char *)malloc((len1 + len2 + 1) * sizeof(char));
	if (!new)
		return (NULL);
	index = 0;
	while (*s1)
		new[index++] = *s1++;
	while (*s2)
		new[index++] = *s2++;
	new[index] = 0;
	return (new);
}
