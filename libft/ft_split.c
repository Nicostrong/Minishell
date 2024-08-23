/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 15:04:24 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/06/17 11:08:58 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * <cat>str</cat>
 *
 * <summary>
 *	static int	countsection(char const *s, char c)
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

static int	countsection(char const *s, char const c)
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

/*
 * <cat>memory</cat>
 *
 * <summary>
 *	static char	*ft_malloc_row(char const s, char c)
 * </summary>
 *
 * <description>
 * 	ft_malloc_row allocate memory for a section of string ans copy the section
 * 	to this pointer.
 * </description>
 *
 * <param type="char const *" name="s">string to cut in section</param>
 * <param type="char" name="c">char separator of section</param>
 *
 * <return>
 *	a pointer allocated with the section copyed in area memory.
 * </return>
 *
 */

static char	*ft_malloc_row(char const *s, char c)
{
	char	*row;
	int		index;

	index = 0;
	while (s[index] && s[index] != c)
		index++;
	row = (char *)malloc((index + 1) * sizeof(char));
	if (!row)
		return (NULL);
	index = 0;
	while (s[index] && s[index] != c)
	{
		row[index] = s[index];
		index++;
	}
	row[index] = 0;
	return (row);
}

/*
 * <cat>str</cat>
 *
 * <summary>
 * 	char	**ft_split(char const *s, char c)
 * </summary>
 *
 * <description>
 * 	ft_split cut a string at eatch char c and save eatch little sting in an
 * 	array.
 * </description>
 *
 * <param type="char const *" name="s">string to split</param>
 * <param type="char" name="c">char of split</param>
 *
 * <return>
 * 	creat and allocate an array of strings and terminate by NULL.
 * </return>
 *
 */

char	**ft_split(char const *s, char c)
{
	char	**array;
	int		index;

	index = 0;
	if (!s)
		return (NULL);
	array = (char **)malloc((countsection(s, c) + 1) * sizeof (char *));
	if (!array)
		return (NULL);
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			array[index++] = ft_malloc_row(s, c);
			if (!array)
				return (ft_free_array(array));
			while (*s && *s != c)
				s++;
		}
	}
	array[index] = NULL;
	return (array);
}
