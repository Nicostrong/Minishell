/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 08:53:00 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/06/19 08:53:02 by nfordoxc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * <cat>memory</cat>
 *
 * <summary>
 *	char **ft_free_array(char **array)
 * </summary>
 *
 * <description>
 *	ft_free_array free all element of the array and the array.
 * </description>
 *
 * <param type="char **" name="array">array of char* to free</param>
 *
 * <return>
 *	NULL.
 * </return>
 *
 */

char	**ft_free_array(char **array)
{
	int	index;

	index = 0;
	while (array[index])
		free(array[index++]);
	free(array);
	return (NULL);
}
