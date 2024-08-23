/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 16:34:08 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/06/17 11:08:55 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * <cat>print</cat>
 *
 * <summary>
 *	void	ft_putnbr_fd(int n, int fd)
 * </summary>
 *
 * <description>
 *	ft_putnbr_fd write the number n on the output designed by fd.
 * </description>
 *
 * <param type="int" name="n">number to print</param>
 * <param type="int" name="fd">number of the file descriptor</param>
 *
 * <return>
 *	void.
 * </return>
 *
 */

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n *= -1;
	}
	if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	else
		ft_putchar_fd(n + '0', fd);
}
