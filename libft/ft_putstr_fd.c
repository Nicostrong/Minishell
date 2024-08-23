/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 16:34:08 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/06/17 11:08:56 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * <cat>print</cat>
 *
 * <summary>
 *	void	ft_putstr_fd(char *s, int fd)
 * </summary>
 *
 * <description>
 *	ft_putchar_fd write the string s on the output designed by fd.
 * </description>
 *
 * <param type="char *" name="s">string to print</param>
 * <param type="int" name="fd">number of the file descriptor</param>
 *
 * <return>
 *	void.
 * </return>
 *
 */

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	while (*s)
		ft_putchar_fd(*s++, fd);
}
