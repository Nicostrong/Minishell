/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tree_utils_0.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 11:32:16 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/09/23 11:07:01 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/*
 * <cat>minishell</cat>
 *
 * <summary>
 *	void	ft_create_attach_node(t_tree **head, t_tree **parent, t_token *cur)
 * </summary>
 *
 * <description>
 *	ft_create_attach_node create and attache the new node on the tree with the 
 *	correct value.
 * </description>
 *
 * <param type="t_tree **" name="head">head of the tree</param>
 * <param type="t_token **" name="parent">parent token</param>
 * <param type="t_token **" name="cur">current token</param>
 *
 * <return>
 *	void.
 * </return>
 *
 */

static void	ft_create_attach_node(t_tree **head, t_tree **parent, t_token *cur)
{
	t_tree	*new_node;

	new_node = ft_create_node_tree(cur->type, cur->value);
	if (!*head)
		*head = new_node;
	else if (cur->type >= T_PIPE && cur->type <= T_AND)
	{
		new_node->left = *head;
		*head = new_node;
	}
	else if (*parent && (*parent)->type >= T_PIPE && (*parent)->type <= T_AND)
		(*parent)->right = new_node;
	else if (*parent)
		(*parent)->next = new_node;
	*parent = new_node;
}

/*
 * <cat>minishell</cat>
 *
 * <summary>
 *	static void	ft_validate_closing_sub(t_token **cur, t_token **tokens)
 * </summary>
 *
 * <description>
 *	ft_validate_closigng_sub check the end of the subshell command and pass to 
 *	the next token.
 * </description>
 *
 * <param type="t_token **" name="cur">current token</param>
 * <param type="t_token **" name="tokens">list of tokens</param>
 *
 * <return>
 *	void.
 * </return>
 *
 */

static void	ft_validate_closing_sub(t_token **cur, t_token **tokens)
{
	if (*cur && (*cur)->type == T_SUBSHELL && ft_strequal((*cur)->value, ")"))
		*cur = (*cur)->next;
	*tokens = *cur;
}

/*
 * <cat>minishell</cat>
 *
 * <summary>
 *	t_tree	*ft_parse_subshell(t_token **tokens)
 * </summary>
 *
 * <description>
 *	ft_parse_subshell parse the T_SUBSHELL token to create a subshell node.
 * </description>
 *
 * <param type="t_token **" name="tokens">list of tokens</param>
 *
 * <return>
 *	a pointer to a new node for the subshell token.
 * </return>
 *
 */

t_tree	*ft_parse_subshell(t_token **tokens)
{
	t_tree	*head;
	t_tree	*parent;
	t_token	*cur;

	head = NULL;
	parent = NULL;
	cur = (*tokens)->next;
	while (cur && !(cur->type == T_SUBSHELL && ft_strequal(cur->value, ")")))
	{
		ft_create_attach_node(&head, &parent, cur);
		cur = cur->next;
	}
	ft_validate_closing_sub(&cur, tokens);
	return (head);
}

/*
 * <cat>minishell</cat>
 *
 * <summary>
 *	void	ft_handle_var(t_token **cur, t_tree **parent)
 * </summary>
 *
 * <description>
 *	ft_handle_var create a tree node for the T_VAR token with the T_KEY value.
 * </description>
 *
 * <param type="t_token **" name="cur">current token</param>
 * <param type="t_tree **" name="parent">parent node of this node</param>
 *
 * <return>
 *	void.
 * </return>
 *
 */

void	ft_handle_var(t_token **cur, t_tree **parent)
{
	t_tree	*new_node;

	new_node = ft_create_node_tree((*cur)->type, (*cur)->value);
	if (*parent)
		(*parent)->next = new_node;
	*parent = new_node;
	*cur = (*cur)->next;
	if (*cur && (*cur)->type == T_KEY)
	{
		new_node = ft_create_node_tree((*cur)->type, (*cur)->value);
		(*parent)->next = new_node;
		*parent = new_node;
		*cur = (*cur)->next;
	}
}

/*
 * <cat>minishell</cat>
 *
 * <summary>
 *	void	ft_handle_cmd(t_token **cur, t_tree **head, t_tree **parent)
 * </summary>
 *
 * <description>
 *	ft_handle_cmd create a tree node for the T_CMD token.
 * </description>
 *
 * <param type="t_token **" name="cur">current token</param>
 * <param type="t_tree **" name="head">head of the tree</param>
 * <param type="t_tree **" name="parent">parent node of this node</param>
 *
 * <return>
 *	void.
 * </return>
 *
 */

void	ft_handle_cmd(t_token **cur, t_tree **head, t_tree **parent)
{
	t_tree	*new_node;

	new_node = ft_create_node_tree((*cur)->type, (*cur)->value);
	if (!*head)
		*head = new_node;
	else
		(*parent)->next = new_node;
	*parent = new_node;
	*cur = (*cur)->next;
	while (*cur && ((*cur)->type == T_WORD || (*cur)->type == T_OPT))
	{
		new_node->next = ft_create_node_tree((*cur)->type, (*cur)->value);
		new_node = new_node->next;
		*cur = (*cur)->next;
	}
	*parent = new_node;
}
