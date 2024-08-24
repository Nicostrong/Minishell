/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 14:39:32 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/06/17 11:09:56 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * <cat>str</cat>
 *
 * <summary>
 * 	char	*ft_strtrim(char const *s1, char const *set)
 * </summary>
 *
 * <description>
 * 	ft_strtrim creat a new malloc string and remove all char in set at the start
 * 	and at the end of the original string.
 * </description>
 *
 * <param type="char const *" name="s1">string to trim</param>
 * <param type="char const *" name="set">set of char to remove</param>
 *
 * <return>
 * 	a pointer allocated with the new string without the set char.
 * </return>
 *
 */

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*new;

	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	end = ft_strlen(s1);
	while (ft_strchr(set, s1[end - 1]) && end > start)
		end--;
	new = ft_substr(s1, start, (end - start));
	return (new);
}
