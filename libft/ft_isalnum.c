/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:37:05 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/06/17 11:08:23 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * <cat>bool</cat>
 *
 * <summary>
 *	int	ft_isalnum(int c)
 * </summary>
 *
 * <description>
 *	checks if the character is in the standard "C" [a-z] || [A-Z] || [0-9].
 * </description>
 *
 * <param type="int" name="c">char to test</param>
 *
 * <return>
 *	1 if c is alpha numerical.
 *	0 if c isn't alpha numerical.
 * </return>
 *
 */

int	ft_isalnum(int c)
{
	return (ft_isdigit(c) || ft_isalpha(c));
}
