/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 12:03:30 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/09/04 12:03:40 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/*
 *	va chercher la partie de la commande qu il y a avant un delimiter.
 */

char *ft_strtok(char *str, const char *delim)
{
	static char	*input = NULL;
	char		*start;

	if (str)
		input = str;
	if (!input)
		return NULL;
	while (*input && ft_strchr(delim, *input))
		input++;
	if (*input == '\0')
		return NULL;
	start = input;
	while (*input && !ft_strchr(delim, *input))
		input++;
	if (*input)
	{
		*input = '\0';
		input++;
	}
	return (start);
}