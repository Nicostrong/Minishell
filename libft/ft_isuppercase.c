/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isuppercase.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 12:20:37 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/06/17 11:08:32 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * <cat>bool</cat>
 *
 * <summary>
 *	int	ft_isuppercase(int c)
 * </summary>
 *
 * <description>
 *	ft_isuppercase check if the char in parameter is in upper case or not.
 * </description>
 *
 * <param type="int" name="c">char to test</param>
 *
 * <return>
 *	1 if the char c is in upper case.
 *	0 if the char c isn't in upper case.
 * </return>
 *
 */

int	ft_isuppercase(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}
