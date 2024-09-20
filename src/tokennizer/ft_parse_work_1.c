/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_work_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 09:36:23 by phkevin           #+#    #+#             */
/*   Updated: 2024/09/20 09:37:08 by phkevin          ###   Luxembour.lu      */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_quote(int *i, int leninp, char *input, t_token **tok)
{
	int		start;
	char	*value;
	char	quote;

	quote = input[*i];
	start = ++(*i);
	while (*i < leninp && input[*i] != quote)
		(*i)++;
	if (*i < leninp)
	{
		value = ft_strndup(&input[start], *i - start);
		ft_append_token(tok, T_SQUOTE, value);
		free(value);
		(*i)++;
	}
	else
	{
		printf("Erreur : guillemet simple non fermé\n");
		exit (EXIT_FAILURE);
	}
}

void	ft_dquote(int *i, int leninp, char *input, t_token **tok)
{
	int		start;
	char	*value;
	char	quote;

	quote = input[*i];
	start = ++(*i);
	while (*i < leninp && input[*i] != quote)
		(*i)++;
	if (*i < leninp)
	{
		value = ft_strndup(&input[start], *i - start);
		ft_append_token(tok, T_DQUOTE, value);
		free(value);
		(*i)++;
	}
	else
	{
		printf("Erreur : guillemet double non fermé\n");
		exit (EXIT_FAILURE);
	}
}

void	ft_var(int *i, int leninp, char *input, t_token **tok)
{
	int		start;
	char	*value;

	start = ++(*i);
	ft_append_token(tok, T_VAR, "$");
	while (*i < leninp && ft_isvarchar(input[*i]))
		(*i)++;
	value = ft_strndup(&input[start], *i - start);
	ft_append_token(tok, T_KEY, value);
	free(value);
}

void	ft_wildcardopt(int *i, int leninp, char *input, t_token **tok)
{
	int		start;
	char	*value;

	start = ++(*i);
	if (input[*i] == '*')
	{
		while (*i < leninp && ft_issep(input[*i]))
			(*i)++;
		value = ft_strndup(&input[start], *i - start);
		ft_append_token(tok, T_WILDCARD, value);
		free(value);
	}
	else if (input[*i] == '-')
	{
		while (*i < leninp && !ft_issep(input[*i]))
			(*i)++;
		value = ft_strndup(&input[start], *i - start);
		ft_append_token(tok, T_OPT, value);
		free(value);
	}

}

void	ft_isbuiltin(int *i, int leninp, char *input, t_token **tok)
{
	int		start;
	char	*value;

	start = *i;
	while (*i < leninp && !ft_issep(input[*i]) && 
		input[*i] != '|' && input[*i] != '&' && 
		input[*i] != '<' && input[*i] != '>' && 
		input[*i] != '(' && input[*i] != ')' && 
		input[*i] != '\'' && input[*i] != '"' &&
		input[*i] != '$' && input[*i] != '*')
		(*i)++;
	value = ft_strndup(&input[start], *i - start);
	if (ft_strequal(value, "echo") || ft_strequal(value, "cd") ||
		ft_strequal(value, "env") || ft_strequal(value, "export") ||
		ft_strequal(value, "unset") || ft_strequal(value, "exit"))
		ft_append_token(tok, T_BUILTIN, value);
	else if (ft_strchr(value, '/'))	// || on arrive a executer le binaire => pipex ft_get_access
		ft_append_token(tok, T_CMD, value);
	else
		ft_append_token(tok, T_WORD, value);
	free(value);
}