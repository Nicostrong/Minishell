/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:51:53 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/06/17 11:08:26 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * <cat>bool</cat>
 *
 * <summary>
 *	int	ft_isascii(int c)
 * </summary>
 *
 * <description>
 *	checks if the character is in the standard "C" ascii [0-127].
 * </description>
 *
 * <param type="int" name="c">char to test</param>
 *
 * <return>
 *	1 if c is ascii char.
 *	0 if c isn't ascii char.
 * </return>
 *
 */

int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}
