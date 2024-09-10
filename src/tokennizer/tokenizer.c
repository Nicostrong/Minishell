/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 12:05:35 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/09/04 13:13:07 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	**ft_tokenize(char *cmd)
{
	char	*token;
	char	**tokens;
	int		index;

	index = -1;
	tokens = (char **)ft_calloc((count_tokens(cmd) + 1), sizeof(char *));
	if (!tokens)
		return (NULL);
	token = strtok(cmd, " ");
	while (token)
	{
		tokens[++index] = ft_strdup(token);
		token = strtok(cmd, " ");
	}
	tokens[++index] = NULL;
	retrurn (tokens);
}