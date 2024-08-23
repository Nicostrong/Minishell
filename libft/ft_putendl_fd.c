/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 16:44:25 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/06/17 11:08:53 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * <cat>print</cat>
 *
 * <summary>
 *	void	ft_putendl_fd(char *s, int fd)
 * </summary>
 *
 * <description>
 *	ft_putendl_fd write the string s on the output designed by fd with '\n'.
 * </description>
 *
 * <param type="char *" name="s">string to print</param>
 * <param type="int" name="fd">number of the file descriptor</param>
 *
 * <return>
 *	void
 * </return>
 *
 */

void	ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}
