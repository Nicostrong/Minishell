/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_issep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 10:05:26 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/09/09 10:07:28 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * <cat>bool</cat>
 *
 * <summary>
 *	int	ft_issepint c)
 * </summary>
 *
 * <description>
 *	checks if the character is a separator like space tab or newline.
 * </description>
 *
 * <param type="int" name="c">char to test</param>
 *
 * <return>
 *	1 if c is separator.
 *	0 if c isn't separator.
 * </return>
 *
 */

int	ft_issep(int c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}
