/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_utils_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 15:47:14 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/09/22 16:03:34 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/*
 * <cat>minishell</cat>
 *
 * <summary>
 *	int	ft_isvarchar(char c)
 * </summary>
 *
 * <description>
 *	ft_isvarchar check if the char is a char of variable name or not.
 * </description>
 *
 * <param type="char" name="c">char to evaluate</param>
 *
 * <return>
 *	1 if the char is a char of variable or
 *	0 if it isn't a char of variable.
 * </return>
 *
 */

static int	ft_isvarchar(char c)
{
	return (ft_isalnum(c) || c == '_');
}

/*
 * <cat>minishell</cat>
 *
 * <summary>
 *	void	ft_handle_env_var(char *input, int *i, t_token **tokens)
 * </summary>
 *
 * <description>
 *	ft_handle_env_var catch the correct T_DQUOTE or T_SQUOTE token and add
 *	this on the linked list tokens.
 * </description>
 *
 * <param type="char *" name="input">sting to tokonize</param>
 * <param type="t_token *" name="token">linked list of tokens</param>
 *
 * <return>
 *	void.
 * </return>
 *
 */

void	ft_handle_env_var(char *input, int *i, t_token **tokens)
{
	char	*value;
	int		start;

	ft_append_token(tokens, T_VAR, NULL);
	start = ++(*i);
	while (input[*i] && ft_isvarchar(input[*i]))
		(*i)++;
	value = ft_strndup(&input[start], *i - start);
	ft_append_token(tokens, T_KEY, value);
	free(value);
}

/*
 * <cat>minishell</cat>
 *
 * <summary>
 *	void	ft_handle_d_s_quote(char *input, int *i, t_token **tokens)
 * </summary>
 *
 * <description>
 *	ft_handle_d_s_quote catch the correct T_DQUOTE or T_SQUOTE token and add
 *	this on the linked list tokens.
 * </description>
 *
 * <param type="char *" name="input">sting to tokonize</param>
 * <param type="t_token *" name="token">linked list of tokens</param>
 *
 * <return>
 *	void.
 * </return>
 *
 */

void	ft_handle_d_s_quote(char *input, int *i, t_token **tokens)
{
	char	*value;
	char	quote;
	int		start;

	quote = input[*i];
	start = ++(*i);
	while (input[*i] && input[*i] != quote)
		(*i)++;
	if (input[*i] == quote)
	{
		value = ft_strndup(&input[start], *i - start);
		if (quote == '"')
			ft_append_token(tokens, T_DQUOTE, value);
		else
			ft_append_token(tokens, T_SQUOTE, value);
		free(value);
		(*i)++;
	}
	else
		printf("Erreur : guillemet \"%c\" non fermé\n", quote);
}

/*
 * <cat>minishell</cat>
 *
 * <summary>
 *	void	ft_handle_subshell(char *input, int *i, t_token **tokens)
 * </summary>
 *
 * <description>
 *	ft_handle_subshellcatch the correct T_DQUOTE or T_SQUOTE token and add
 *	this on the linked list tokens.
 * </description>
 *
 * <param type="char *" name="input">sting to tokonize</param>
 * <param type="t_token *" name="token">linked list of tokens</param>
 *
 * <return>
 *	void.
 * </return>
 *
 */

void	ft_handle_subshell(char *input, int *i, t_token **tokens)
{
	if (input[*i] == '(')
		ft_append_token(tokens, T_SUBSHELL, "(");
	else if (input[*i] == ')')
		ft_append_token(tokens, T_SUBSHELL, ")");
	(*i)++;
}
