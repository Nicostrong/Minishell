/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 16:04:18 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/06/17 11:08:31 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * <cat>bool</cat>
 *
 * <summary>
 *	int	ft_isprint(int c)
 * </summary>
 *
 * <description>
 *	checks if the character is in the standard "C" [32-127].
 * </description>
 *
 * <param type="int" name="c">char to test</param>
 *
 * <return>
 *	1 if c is printable.
 *	0 if c isn't printable.
 * </return>
 *
 */

int	ft_isprint(int c)
{
	return (c >= 32 && c < 127);
}
