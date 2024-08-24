/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 13:42:34 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/06/17 11:08:15 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * <cat>bool</cat>
 *
 * <summary>
 *	static int	ft_isspace(int c)
 * </summary>
 *
 * <description>
 *	ft_isspace function test the char passed in param if it's an spacename.
 *	an spacename is this char[9-13 && 32].
 * </description>
 *
 * <param type="int" name="c">char to test</param>
 *
 * <return>
 *	1 if c is in spacename
 *	or
 *	0 if c isn't in spacename.
 * </return>
 *
 */

static int	ft_isspace(int c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

/*
 * <cat>convert</cat>
 *
 * <summary>
 *	int	ft_atoi(const char *nptr)
 * </summary>
 *
 * <description>
 *	atoi convert a string with numerical char to interger type.
 *	it pass all space determined by isspace, can take only optional char '+'
 *	or '-', and numerical char.
 * </description>
 *
 * <param type="const void *" name="nptr">pointer to string to convert</param>
 *
 * <return>
 *	an interger like written on the *nptr with '-' if the number is negatif.
 * </return>
 *
 */

int	ft_atoi(const char *nptr)
{
	char	*s;
	int		nb;
	int		neg;

	s = (char *)nptr;
	nb = 0;
	neg = 0;
	while (ft_isspace(*s))
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			neg = 1;
		s++;
	}
	while (ft_isdigit(*s))
	{
		nb = (nb * 10) + (*s - '0');
		s++;
	}
	if (neg)
		return (-nb);
	return (nb);
}
