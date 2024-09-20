/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 10:08:59 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/09/20 09:09:27 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	ft_isvarchar(char c)
{
	return (ft_isalnum(c) || c == '_');
}

t_token	*ft_parse_cmd(char *input)
{
	t_token	*tokens;
	char	*value;
	char	quote;
	int		i;
	int		len_input;
	int		start;

	tokens = NULL;
	i = 0;
	start = 0;
	len_input = ft_strlen(input);
	while (i < len_input)
	{
		if (ft_issep(input[i]))
			i++;
		else if (input[i] == '|')
		{
			if (input[i + 1] == '|')
			{
				ft_append_token(&tokens, T_OR, "||");
				i += 2;
			}
			else
			{
				ft_append_token(&tokens, T_PIPE, "|");
				i++;
			}
		}
		else if (input[i] == '&')
		{
			if (input[i + 1] == '&')
			{
				ft_append_token(&tokens, T_AND, "&&");
				i += 2;
			}
			else
				i++;
		}
		else if (input[i] == '<')
		{
			if (input[i + 1] == '<')
			{
				ft_append_token(&tokens, T_HEREDOC, "<<");
				i += 2;
				while (i < len_input && ft_issep(input[i]))
					i++;
				start = i;
				while (i < len_input && !ft_issep(input[i]))
					i++;
				value = ft_strndup(&input[start], i - start);
				ft_append_token(&tokens, T_EOF, value);
				free(value);
			}
			else
			{
				ft_append_token(&tokens, T_F_IN, "<");
				i++;
				while (i < len_input && ft_issep(input[i]))
					i++;
				start = i;
				while (i < len_input && !ft_issep(input[i]))
					i++;
				value = ft_strndup(&input[start], i - start);
				ft_append_token(&tokens, T_FILENAME, value);
				free(value);
			}
		}
		else if (input[i] == '>')
		{
			if (input[i + 1] == '>')
			{
				ft_append_token(&tokens, T_F_OUT_APPEND, ">>");
				i += 2;
			}
			else
			{
				ft_append_token(&tokens, T_F_OUT, ">");
				i++;
			}
			while (i < len_input && ft_issep(input[i]))
				i++;
			start = i;
			while (i < len_input && !ft_issep(input[i]))
				i++;
			value = ft_strndup(&input[start], i - start);
			ft_append_token(&tokens, T_FILENAME, value);
			free(value);
		}
		else if (input[i] == '(')
		{
			ft_append_token(&tokens, T_SUBSHELL, "(");
			i++;
		}
		else if (input[i] == ')')
		{
			ft_append_token(&tokens, T_SUBSHELL, ")");
			i++;
		}
		else if (input[i] == '\'')
		{
			quote = input[i];
			start = ++i;
			while (i < len_input && input[i] != quote)
				i++;
			if (i < len_input)
			{
				value = ft_strndup(&input[start], i - start);
				ft_append_token(&tokens, T_SQUOTE, value);
				free(value);
				i++;
			}
			else
			{
				printf("Erreur : guillemet simple non fermé\n");
				exit (EXIT_FAILURE);
			}
		}
		else if (input[i] == '"')
		{
			quote = input[i];
			start = ++i;
			while (i < len_input && input[i] != quote)
				i++;
			if (i < len_input)
			{
				value = ft_strndup(&input[start], i - start);
				ft_append_token(&tokens, T_DQUOTE, value);
				free(value);
				i++;
			}
			else
			{
				printf("Erreur : guillemet double non fermé\n");
				exit (EXIT_FAILURE);
			}
		}
		else if (input[i] == '$')
		{
			ft_append_token(&tokens, T_VAR, "$");
			start = ++i;
			while (i < len_input && ft_isvarchar(input[i]))
				i++;
			value = ft_strndup(&input[start], i - start);
			ft_append_token(&tokens, T_KEY, value);
			free(value);
		}
		else if (input[i] == '*')
		{
			start = ++i;
			while (i < len_input && ft_issep(input[i]))
				i++;
			value = ft_strndup(&input[start], i - start);
			ft_append_token(&tokens, T_WILDCARD, value);
			free(value);
		}
		else if (input[i] == '-')
		{
			start = i;
			while (i < len_input && !ft_issep(input[i]))
				i++;
			value = ft_strndup(&input[start], i - start);
			ft_append_token(&tokens, T_OPT, value);
			free(value);
		}
		else
		{
			start = i;
			while (i < len_input && !ft_issep(input[i]) && 
				input[i] != '|' && input[i] != '&' && 
				input[i] != '<' && input[i] != '>' && 
				input[i] != '(' && input[i] != ')' && 
				input[i] != '\'' && input[i] != '"' &&
				input[i] != '$' && input[i] != '*')
				i++;
			value = ft_strndup(&input[start], i - start);
			if (ft_strequal(value, "echo") || ft_strequal(value, "cd") ||
				ft_strequal(value, "env") || ft_strequal(value, "export") ||
				ft_strequal(value, "unset") || ft_strequal(value, "exit"))
				ft_append_token(&tokens, T_BUILTIN, value);
			else if (ft_strchr(value, '/'))	// || on arrive a executer le binaire => pipex ft_get_access
				ft_append_token(&tokens, T_CMD, value);
			else
				ft_append_token(&tokens, T_WORD, value);
			free(value);
		}
	}
	return (tokens);
}

///////////////////////////////////////////////////////////////////////////////
//		DEBUG	DEBUG	DEBUG	DEBUG	DEBUG	DEBUG	DEBUG	DEBUG	DEBUG
///////////////////////////////////////////////////////////////////////////////

char	*ft_get_token_name(e_token token)
{
	switch (token)
	{
		case T_WORD: return "T_WORD";
		case T_BUILTIN: return "T_BUILTIN";
		case T_CMD: return "T_CMD";
		case T_OPT: return "T_OPT";
		case T_PIPE: return "T_PIPE";
		case T_OR: return "T_OR";
		case T_AND: return "T_AND";
		case T_F_IN: return "T_F_IN";
		case T_HEREDOC: return "T_HEREDOC";
		case T_EOF: return "T_EOF";
		case T_F_OUT: return "T_F_OUT";
		case T_F_OUT_APPEND: return "T_F_OUT_APPEND";
		case T_FILENAME: return "T_FILENAME";
		case T_SUBSHELL: return "T_SUBSHELL";
		case T_DQUOTE: return "T_DQUOTE";
		case T_SQUOTE: return "T_SQUOTE";
		case T_VAR: return "T_VAR";
		case T_KEY:	return "T_KEY";
		case T_WILDCARD: return "T_WILDCARD";
		case T_END: return "T_END";
		default: return "UNKNOWN";
	}
}

void	ft_print_tokens(t_token *tokens)
{
	t_token	*current;

	current = tokens;
	while (current)
	{
		printf("Token = %s\t\ttype = %s\n", current->value, ft_get_token_name(current->type));
		current = current->next;
	}
}