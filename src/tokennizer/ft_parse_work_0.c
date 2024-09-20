/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_work_0.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 09:31:09 by phkevin           #+#    #+#             */
/*   Updated: 2024/09/20 09:34:40 by phkevin          ###   Luxembour.lu      */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_froward(int *i, char *input, t_token **tok)
{
	if (input[*i] == '|')
	{
		if (input[*i + 1] == '|')
		{
			ft_append_token(tok, T_OR, "||");
			*i += 2;
		}
		else
		{
			ft_append_token(tok, T_PIPE, "|");
			(*i)++;
		}
	}
	else if (input[*i] == '&')
	{
		if (input[*i + 1] == '&')
		{
			ft_append_token(tok, T_AND, "&&");
			*i += 2;
		}
		else
			(*i)++;
	}
}

void	ft_handherdoc(int *i, int leninp, char *input, t_token **tok)
{
	int		start;
	char	*value;

	start = 0;
	ft_append_token(tok, T_HEREDOC, "<<");
	*i += 2;
	while (*i < leninp && ft_issep(input[*i]))
		(*i)++;
	start = *i;
	while (*i < leninp && !ft_issep(input[*i]))
		(*i)++;
	value = ft_strndup(&input[start], *i - start);
	ft_append_token(tok, T_EOF, value);
	free(value);
}

void	ft_handinfi(int *i, int leninp, char *input, t_token **tok)
{
	int		start;
	char	*value;

	start = 0;
	ft_append_token(tok, T_F_IN, "<");
	(*i)++;
	while (*i < leninp && ft_issep(input[*i]))
		(*i)++;
	start = *i;
	while (*i < leninp && !ft_issep(input[*i]))
		(*i)++;
	value = ft_strndup(&input[start], *i - start);
	ft_append_token(tok, T_FILENAME, value);
	free(value);
}

void	ft_append(int *i, int leninp, char *input, t_token **tok)
{
	int		start;
	char	*value;

	start = 0;
	if (input[*i] == '>')
	{
		if (input[*i + 1] == '>')
		{
			ft_append_token(tok, T_F_OUT_APPEND, ">>");
			*i += 2;
		}
		else
		{
			ft_append_token(tok, T_F_OUT, ">");
			(*i)++;
		}
		while (*i < leninp && ft_issep(input[*i]))
			(*i)++;
		start = *i;
		while (*i < leninp && !ft_issep(input[*i]))
			(*i)++;
		value = ft_strndup(&input[start], *i - start);
		ft_append_token(tok, T_FILENAME, value);
		free(value); 
	}
}

void	ft_subshell(int *i, char *input, t_token **tok)
{
	if (input[*i] == '(')
	{
		ft_append_token(tok, T_SUBSHELL, "(");
		(*i)++;
	}
	else if (input[*i] == ')')
	{
		ft_append_token(tok, T_SUBSHELL, ")");
		(*i)++;
	}
}