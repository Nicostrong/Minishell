/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrarray.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 13:04:59 by nfordoxc          #+#    #+#             */
/*   Updated: 22/09/2024 15:28:50 by Nicostrong       ###   ########.lu       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * <cat>print</cat>
 *
 * <summary>
 *	void	ft_putstrarray(char **a_str)
 * </summary>
 *
 * <description>
 *	ft_putstrarray print an array of string.
 * </description>
 *
 * <param type="char **" name="a_str">str array to print</param>
 *
 * <return>
 *	void.
 * </return>
 *
 */

void	ft_putstrarray(char **a_str)
{
	int	index;

	if (!a_str)
		return ;
	index = -1;
	while (a_str[++index])
		ft_putendl_fd(a_str[index], 1);
}
