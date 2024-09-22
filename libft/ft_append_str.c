/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_append_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 20:51:26 by nfordoxc          #+#    #+#             */
/*   Updated: 22/09/2024 15:29:13 by Nicostrong       ###   ########.lu       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * <cat>str</cat>
 *
 * <summary>
 *	char	**ft_append_str(char **array, char *str)
 * </summary>
 *
 * <description>
 *	ft_append_str add a new field to array.
 * </description>
 *
 * <param type="char **" name="array">array where we want to extend</param>
 * <param type="char *" name="str">str we want to add</param>
 *
 * <return>
 *	a new array with the new str append.
 * </return>
 *
 */

char	**ft_append_str(char **array, char *str)
{
	char	**new_array;
	int		i;

	if (!str)
		return (array);
	i = 0;
	while (array && array[i])
		i++;
	new_array = (char **)ft_calloc((i + 2), sizeof(char *));
	if (!new_array)
		return (NULL);
	i = -1;
	while (array && array[++i])
		new_array[i] = ft_strdup(array[i]);
	new_array[++i] = ft_strdup(str);
	new_array[++i] = NULL;
	if (array)
		ft_free_array(array);
	return (new_array);
}
