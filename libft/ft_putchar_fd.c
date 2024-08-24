/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 16:34:08 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/06/17 11:08:52 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * <cat>print</cat>
 *
 * <summary>
 *	void	ft_putchar_fd(char c, int fd)
 * </summary>
 *
 * <description>
 *	ft_putchar_fd write the char c on the output designed by fd.
 *	0 = input
 *	1 = stdout
 *	2 = error
 * </description>
 *
 * <param type="char" name="c">char to print</param>
 * <param type="int" name="fd">number of the file descriptor</param>
 *
 * <return>
 *	void.
 * </return>
 *
 */

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
