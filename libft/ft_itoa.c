/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 15:49:15 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/09/06 10:03:38 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * <cat>str</cat>
 *
 * <summary>
 *	static int	ft_count_digit(long long n)
 * </summary>
 *
 * <description>
 *	ft_count_digit count the number of digit on n.
 * </description>
 *
 * <param type="long long" name="n">nomber</param>
 *
 * <return>
 *	the number of digit in the number n.
 * </return>
 *
 */

static int	ft_count_digit(long long n)
{
	int	len;

	if (n == 0 || n == -0)
		return (1);
	len = 0;
	if (n < 0)
		len = 1;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

/*
 * <cat>convert</cat>
 *
 * <summary>
 *	char	*ft_itoa(int n)
 * </summary>
 *
 * <description>
 *	ft_itoa convert an integer to string. it allocate memory to create the 
 *	string.
 * </description>
 *
 * <param type="int" name="n">integer to convert in string</param>
 *
 * <return>
 *	a pointer allocated to the string.
 * </return>
 *
 */

char	*ft_itoa(int n)
{
	int			len;
	long long	nbr;
	char		*ret;

	len = ft_count_digit(n);
	nbr = (long long)n;
	if (n < 0)
		nbr *= -1;
	ret = (char *)ft_calloc((len + 1), sizeof(char));
	if (!ret)
		return (NULL);
	ret[len--] = '\0';
	while (len >= 0)
	{
		ret[len] = nbr % 10 + '0';
		nbr /= 10;
		len--;
	}
	if (n < 0)
		ret[0] = '-';
	return (ret);
}
