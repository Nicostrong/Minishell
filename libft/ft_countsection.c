/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countsection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 15:45:19 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/06/17 11:15:29 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * <cat>str</cat>
 *
 * <summary>
 *	int	ft_countsection(char const *s, char c)
 * </summary>
 *
 * <description>
 *	ft_countword count all section in a string. eatch section are separated by
 *	the char c.
 * </description>
 *
 * <param type="char cont *" name="s">string to evaluate</param>
 * <param type="char" name="c">char of separation of section</param>
 *
 * <return>
 *	number of section in the string.
 * </return>
 *
 */

int	ft_countsection(char const *s, char const c)
{
	int	section;
	int	index;

	section = 0;
	index = 0;
	while (s[index])
	{
		while (s[index] == c)
			index++;
		if (s[index] && s[index] != c)
		{
			section++;
			while (s[index] && s[index] != c)
				index++;
		}
	}
	return (section);
}
