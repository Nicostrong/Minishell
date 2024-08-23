/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 10:23:49 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/06/17 11:14:49 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * <cat>bool</cat>
 *
 * <summary>
 *	int	ft_isint(void nbr)
 * </summary>
 *
 * <description>
 *	ft_isint function test if the argument is an integer or not.
 * </description>
 *
 * <param type="void" name="nbr">number to evaluate</param>
 *
 * <return>
 *	1 if nbr is an integer.
 *	or
 *	0 if nbr isn't an integer.
 * </return>
 *
 */

int	ft_isint(long long nbr)
{
	if (nbr > 2147483647 || nbr < -2147483648)
		return (0);
	return (1);
}
