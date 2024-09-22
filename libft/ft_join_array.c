/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 14:51:30 by nfordoxc          #+#    #+#             */
/*   Updated: 22/09/2024 15:29:36 by Nicostrong       ###   ########.lu       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * <cat>str</cat>
 *
 * <summary>
 * 	char	*ft_join_array(char **a_str, char sep)
 * </summary>
 *
 * <description>
 * 	ft_join_array join all fields of an str array with sep betwenn each fields.
 * </description>
 *
 * <param type="char **" name="a_str">array of string</param>
 * <param type="char *" name="sep">pointer to a char of separator</param>
 *
 * <return>
 * 	a new allocated string with all fields of the array separated by the char 
 * 	sep.
 * </return>
 *
 */

char	*ft_join_array(char **a_str, char *sep)
{
	char	*join;
	int		index;
	int		len_join;

	if (!a_str || !*a_str)
		return (NULL);
	index = -1;
	len_join = 0;
	while (a_str[++index])
		len_join += ft_strlen(a_str[index]) + 1;
	join = (char *)ft_calloc(len_join, sizeof(char));
	if (!join)
		return (NULL);
	index = -1;
	while (a_str[++index])
	{
		ft_strlcat(join, a_str[index], len_join);
		ft_strlcat(join, sep, len_join);
	}
	join[len_join] = 0;
	return (join);
}
