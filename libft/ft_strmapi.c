/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 16:05:29 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/06/17 11:09:49 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * <cat>convert</cat>
 *
 * <summary>
 *	char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
 * </summary>
 *
 * <description>
 *	ft_strmapi call for eatch char of the string s a function who make some
 *	modification a the char. it creat a new string and allocate memory for this
 *	string.
 * </description>
 *
 * <param type="char const *" name="s">string to evaluate</param>
 * <param type="char *" name="f">function with param type (u_int, char)</param>
 *
 * <return>
 *	a pointer allocated with the new string.
 * </return>
 *
 */

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*ret;
	unsigned int	index;

	index = 0;
	ret = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!ret)
		return (NULL);
	while (s[index])
	{
		ret[index] = f(index, s[index]);
		index++;
	}
	ret[index] = '\0';
	return (ret);
}
