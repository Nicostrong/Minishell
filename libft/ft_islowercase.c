/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_islowercase.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 12:24:46 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/06/17 11:08:29 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * <cat>bool</cat>
 *
 * <summary>
 *	int	ft_islowercase(int c)
 * </summary>
 *
 * <description>
 *	ft_islowercase check if the char in parameter is in lower case or not.
 * </description>
 *
 * <param type="int" name="c">char to test</param>
 *
 * <return>
 *	1 if the char c is in lower case.
 *	0 if the char c isn't in lower case.
 * </return>
 *
 */

int	ft_islowercase(int c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	return (0);
}
