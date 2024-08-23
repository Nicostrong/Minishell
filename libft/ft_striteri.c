/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 16:20:29 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/06/17 11:09:02 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * <cat>str</cat>
 *
 * <summary>
 * 	void	ft_striteri(char *s, void (*f)(unsigned int, char *))
 * </summary>
 *
 * <description>
 *	ft_striteri call for eatch char of the string s, a function who apply some
 *	modification at eatch char of the string.
 * </description>
 *
 * <param type="char *" name="s">string to evaluate</param>
 * <param type="void *" name="f">function with param (u_int, char *)</param>
 *
 * <return>
 * 	void.
 * </return>
 *
 */

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	index;

	index = 0;
	while (s[index])
	{
		f(index, &s[index]);
		index++;
	}
}
