/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 13:42:06 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/06/17 11:09:53 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * <cat>str</cat>
 *
 * <summary>
 *	char	*ft_strnstr(const char *big, const char *little, size_t len)
 * </summary>
 *
 * <description>
 *	ft_strnstr chearch little string on big string.
 * </description>
 *
 * <param type="const char *" name="big">source of memory area</param>
 * <param type="const char *" name="little">source of memory area</param>
 * <param type="size_t" name="len">number of byte to copy</param>
 *
 * <return>
 *	if little is empty => pointer to big.
 *	if no occurence of little in big => NULL.
 *	if little in big => pointer to little in big.
 * </return>
 *
 */

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*cp_big;
	char	*cp_lit;
	size_t	i_b;
	size_t	len_lit;

	cp_big = (char *)big;
	cp_lit = (char *)little;
	len_lit = ft_strlen(little);
	if (!little || *cp_lit == 0)
		return (cp_big);
	i_b = 0;
	while (i_b < len && cp_big[i_b])
	{
		if (cp_big[i_b] == cp_lit[0])
		{
			if (len - i_b >= len_lit)
				if (!ft_strncmp((const char *)&cp_big[i_b], little, len_lit))
					return (&cp_big[i_b]);
		}
		i_b++;
	}
	return (NULL);
}
