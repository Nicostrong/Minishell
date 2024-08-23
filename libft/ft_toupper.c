/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 13:41:12 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/06/17 11:10:04 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * <cat>convert</cat>
 *
 * <summary>
 *	int	ft_toupper(int c)
 * </summary>
 *
 * <description>
 *	ft_toupper replace a lower alpha char to capitalize char.
 * </description>
 *
 * <param type="int" name="c">char to test</param>
 *
 * <return>
 *	the uppercase of the lowercase c, or the char c if is'nt alpha char.
 * </return>
 *
 */

int	ft_toupper(int c)
{
	if (ft_isalpha(c) == 2)
		return (c - 32);
	return (c);
}
