/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 10:22:14 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/06/17 11:08:17 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * <cat>memory</cat>
 *
 * <summary>
 *	void	ft_bzero(void *s, size_t n)
 * </summary>
 *
 * <description>
 *	ft_bzero erases n bytes of memory area pointed by s with '\0' char.
 *	it's call ft_memset.
 * </description>
 *
 * <param type="void *" name="s">memory area</param>
 * <param type="size_t" name="n">number of byte to erase</param>
 *
 * <return>
 *	void.
 * </return>
 *
 */

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
