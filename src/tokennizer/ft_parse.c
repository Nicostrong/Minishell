/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 10:08:59 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/09/20 11:35:55 by phkevin          ###   Luxembour.lu      */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_isvarchar(char c)
{
	return (ft_isalnum(c) || c == '_');
}

static void	ft_worktree(int *i, int leninp, char *input, t_token **tok)
{
	ft_froward(i, input, tok);
	if (input[*i] == '<')
	{
		if (input[*i + 1] == '<')
			ft_handherdoc(i, leninp, input, tok);
		else
			ft_handinfi(i, leninp, input, tok);
	}
	else if (input[*i] == '>')
		ft_append(i, leninp, input, tok);
	else if (input[*i] == '(' || input[*i] == ')')
		ft_subshell(i, input, tok);
	else if (input[*i] == '\'')
		ft_quote(i, leninp, input, tok);
	else if (input[*i] == '"')
		ft_dquote(i, leninp, input, tok);
	else if (input[*i] == '$')
		ft_var(i, leninp, input, tok);
	else if (input[*i] == '*' || input[*i] == '-')
		ft_wildcardopt(i, leninp, input, tok);
	else
		ft_isbuiltin(i, leninp, input, tok);
}

/**
 * @brief Analyse et découpe une commande shell en une liste de tokens.
 * 
 * Cette fonction prend une chaîne de caractères représentant une commande
 * shell et la découpe en plusieurs tokens. Les tokens représentent des 
 * opérateurs logiques, des redirections, des variables d'environnement, 
 * des guillemets, des mots simples, des commandes, ou des sous-shells.
 * Chaque token est ajouté à la liste chaînée de tokens.
 * 
 * @param input Chaîne de caractères contenant la commande shell à analyser.
 * 
 * @return t_token* Liste chaînée contenant tous les tokens analysés.
 * 
 * Les différents tokens incluent :
 * - `T_OR`, `T_AND`, `T_PIPE` pour les opérateurs logiques
 * - `T_HEREDOC`, `T_F_IN`, `T_F_OUT`, `T_F_OUT_APPEND` pour les redirections
 * - `T_EOF` pour la fin d'un document (EOF)
 * - `T_CMD`, `T_WORD` pour les commandes et autres mots
 * - `T_VAR`, `T_KEY` pour les variables d'environnement
 * - `T_SQUOTE`, `T_DQUOTE` pour les chaînes entre guillemets
 * - `T_SUBSHELL` pour les sous-shells (parenthèses)
 * - `T_BUILTIN` pour les commandes internes du shell (ex: echo, cd)
 */
t_token	*ft_parse_cmd(char *input)
{
	t_token	*tokens;
	int		i;
	int		len_input;

	tokens = NULL;
	i = 0;
	len_input = ft_strlen(input);
	while (i < len_input)
	{
		if (ft_issep(input[i]))
			i++;
		
		else	
			ft_worktree(&i, len_input, input, &tokens);
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