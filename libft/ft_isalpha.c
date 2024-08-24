/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 14:40:43 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/06/17 11:08:24 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * <cat>bool</cat>
 *
 * <summary>
 *	int	ft_isalpha(int c)
 * </summary>
 *
 * <description>
 *	checks if the character is in the standard "C" [a-z||A-Z].
 * </description>
 *
 * <param type="int" name="c">char to test</param>
 *
 * <return>
 *	0 if c isn't alpha.
 *	1 if c is alpha uppercase.
 *	2 if c is alpha lowercase.
 * </return>
 *
 */

int	ft_isalpha(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	else if (c >= 'a' && c <= 'z')
		return (2);
	else
		return (0);
}
