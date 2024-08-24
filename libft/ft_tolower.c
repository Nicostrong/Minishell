/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 13:41:23 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/06/17 11:09:59 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * <cat>convert</cat>
 *
 * <summary>
 *	int	ft_tolower(int c)
 * </summary>
 *
 * <description>
 *	ft_tolower replace a upper alpha char to lower alpha char.
 * </description>
 *
 * <param type="int" name="c">char to test</param>
 *
 * <return>
 *	the lowercase of the uppercase c, or the char c if is'nt alpha char.
 * </return>
 *
 */

int	ft_tolower(int c)
{
	if (ft_isalpha(c) == 1)
		return (c + 32);
	return (c);
}
