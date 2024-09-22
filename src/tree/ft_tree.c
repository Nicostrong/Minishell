/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tree.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 09:59:20 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/09/22 18:41:16 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/*
 * <cat>minishell</cat>
 *
 * <summary>
 *	void	ft_parse_ttt_2(t_token **cur, t_tree **head, t_tree ** parent)
 * </summary>
 *
 * <description>
 *	ft_parse_ttt_2 transform the second part of the linked list tokens of the
 *	command on a AST tree for execute each command correctly.
 * </description>
 *
 * <param type="t_token **" name="cur">current token</param>
 * <param type="t_tree **" name="head">head node</param>
 * <param type="t_tree **" name="parent">parent node</param>
 *
 * <return>
 *	void.
 * </return>
 *
 */

static void	ft_parse_ttt_2(t_token **cur, t_tree **head, t_tree **parent)
{
	if ((*cur)->type >= T_F_IN && (*cur)->type <= T_F_OUT_APPEND)
		ft_handle_file(cur, parent);
	else if ((*cur)->type >= T_WORD && (*cur)->type <= T_CMD)
		ft_handle_cmd(cur, head, parent);
	else if ((*cur)->type == T_VAR)
		ft_handle_var(cur, parent);
	else if ((*cur)->type == 13 && (*cur)->value
		&& ft_strequal((*cur)->value, "("))
		ft_handle_sub(cur, head, parent);
	else if ((*cur)->type == T_OPT)
		ft_handle_option(cur, parent);
	else if ((*cur)->type == T_DQUOTE || (*cur)->type == T_SQUOTE)
		ft_handle_quote(cur, parent);
	else
		*cur = (*cur)->next;
}

/*
 * <cat>minishell</cat>
 *
 * <summary>
 *	t_tree	*ft_parse_token_to_tree(t_token **tokens)
 * </summary>
 *
 * <description>
 *	ft_parse_token_to_tree transform the linked list tokens of the command on a 
 *	AST tree for execute each command correctly.
 * </description>
 *
 * <param type="t_token **" name="tokens">linked list of tokens</param>
 *
 * <return>
 *	a pointer to the first node of the tree.
 * </return>
 *
 */

t_tree	*ft_parse_token_to_tree(t_token **tokens)
{
	t_token	*cur;
	t_tree	*head;
	t_tree	*parent;
	t_tree	*new;

	cur = *tokens;
	head = NULL;
	parent = NULL;
	while (cur)
	{
		if (cur->type >= T_PIPE && cur->type <= T_AND)
			return (ft_handle_pipe_or_and(&cur, &head));
		else if (cur->type == T_HEREDOC)
		{
			new = ft_parse_heredoc(&cur);
			if (!head)
				head = new;
			else
				parent->next = new;
			parent = new->next;
		}
		else
			ft_parse_ttt_2(&cur, &head, &parent);
	}
	return (head);
}
