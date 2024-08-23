/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:20:13 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/06/17 11:08:27 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * <cat>bool</cat>
 *
 * <summary>
 *	int	ft_isdigit(int c)
 * </summary>
 *
 * <description>
 *	checks if the character is in the standard "C" [0-9].
 * </description>
 *
 * <param type="int" name="c">char to test</param>
 *
 * <return>
 *	1 if c is digit.
 *	0 if c isn't digit.
 * </return>
 *
 */

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
