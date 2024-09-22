/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 10:08:59 by nfordoxc          #+#    #+#             */
/*   Updated: 22/09/2024 15:31:17 by Nicostrong       ###   ########.lu       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/*
 * <cat>minishell</cat>
 *
 * <summary>
 *	t_token	*ft_create_token(e_token type, char *value)
 * </summary>
 *
 * <description>
 *	ft_create_token create a new node on the linked list tokens and set the type
 *	ans the value in the node.
 * </description>
 *
 * <param type="e_token" name="type">type of tokens</param>
 * <param type="char *" name="value">value of the token</param>
 *
 * <return>
 *	the new token with the type and the value setting.
 * </return>
 *
 */

static t_token	*ft_create_token(e_token type, char *value)
{
	t_token	*new;

	new = (t_token *)ft_calloc(1, sizeof(t_token));
	if (!new)
		return (NULL);
	new->type = type;
	new->value = ft_strdup(value);
	new->before = NULL;
	new->next = NULL;
	return (new);
}

/*
 * <cat>minishell</cat>
 *
 * <summary>
 *	void	ft_append_token(t_token **head, e_token type, char *value)
 * </summary>
 *
 * <description>
 *	ft_append_token call the ft_create_token function with the type and the
 *	value and put this new node at the end of the linked list tokens.
 * </description>
 *
 * <param type="t_token **" name="head">head of linked list tokens</param>
 * <param type="e_token" name="type">type of tokens</param>
 * <param type="char *" name="value">value of the token</param>
 *
 * <return>
 *	void.
 * </return>
 *
 */

void	ft_append_token(t_token **head, e_token type, char *value)
{
	t_token	*new;
	t_token	*current;

	new = ft_create_token(type, value);
	if (!head)
		return ;
	if (!*head)
		*head = new;
	else
	{
		current = *head;
		while (current->next)
			current = current->next;
		new->before = current;
		current->next = new;
	}
}

/*
 * <cat>minishell</cat>
 *
 * <summary>
 *	t_token	*ft_parse_cmd(char *input)
 * </summary>
 *
 * <description>
 *	ft_parse_cmd parse the command string and call the correct tokennizer 
 *	function to transforme the string command on linked list of token.
 * </description>
 *
 * <param type="char *" name="input">sting to tokonize</param>
 *
 * <return>
 *	void.
 * </return>
 *
 */

t_token	*ft_parse_cmd(char *input, t_shell *shell)
{
	t_token	*tokens;
	int		i;

	tokens = NULL;
	i = 0;
	while (input[i])
	{
		if (ft_issep(input[i]))
			i++;
		else if (input[i] == '|' || input[i] == '&')
			ft_handle_operator(input, &i, &tokens);
		else if (input[i] == '<')
			ft_handle_file_in(input, &i, &tokens);
		else if (input[i] == '>')
			ft_handle_file_out(input, &i, &tokens);
		else if (input[i] == '"' || input[i] == '\'')
			ft_handle_d_s_quote(input, &i, &tokens);
		else if (input[i] == '$')
			ft_handle_env_var(input, &i, &tokens);
		else if (input[i] == '(' || input[i] == ')')
			ft_handle_subshell(input, &i, &tokens);
		else
			ft_handle_word(input, &i, &tokens, shell);
	}
	return (tokens);
}
