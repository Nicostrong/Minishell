/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tree_utils_0.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 11:32:16 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/09/19 11:20:11 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/*
 *	create node tree
 */

t_tree	*ft_create_node_tree(e_token type, char *cmd)
{
	t_tree	*node;

	node = (t_tree *)ft_calloc(1, sizeof(t_tree));
	if (!node)
		return (NULL);	//	exit faillure avec message error MALLOC
	node->type = type;
	if (cmd)
		node->cmd = ft_strdup(cmd);
	else
		node->cmd = NULL;
	node->left = NULL;
	node->right = NULL;
	node->next = NULL;
	return (node);
}

t_tree	*ft_parse_heredoc(t_token **tokens)
{
	t_tree	*heredoc_node;
	t_tree	*new_node;
	t_tree	*parent_node;
	t_tree	*cmd_node;
	t_token	*cur;
	
	heredoc_node = ft_create_node_tree((*tokens)->type, NULL);
	cur = (*tokens)->next;
	if (cur && cur->type == T_EOF)
	{
		new_node = ft_create_node_tree(cur->type, cur->value);
		heredoc_node->next = new_node;
		cur = cur->next;
	}
	parent_node = heredoc_node;
	while (cur && !(cur->type == T_PIPE || cur->type == T_AND || cur->type == T_OR))
	{
		if (cur->type >= T_WORD && cur->type <= T_CMD)
		{
			cmd_node = ft_create_node_tree(cur->type, cur->value);
			parent_node->next = cmd_node;
			parent_node = cmd_node;
		}
		else if (cur->type == T_OPT)
		{
			new_node = ft_create_node_tree(cur->type, cur->value);
			parent_node->next = new_node;
			parent_node = new_node;
		}
		else if (cur->type >= T_F_IN && cur->type <= T_F_OUT_APPEND)
		{
			new_node = ft_create_node_tree(cur->type, cur->value);
			parent_node->next = new_node;
			parent_node = new_node;
			cur = cur->next;
			if (cur && cur->type == T_FILENAME)
			{
				new_node->next  =ft_create_node_tree(cur->type, cur->value);
				parent_node = new_node->next;
			}
		}
		cur = cur->next;
	}
	*tokens = cur;
	return (heredoc_node);
}

t_tree	*ft_parse_subshell(t_token **tokens)
{
	t_tree	*head_sub;
	t_tree	*new_node;
	t_tree	*parent_node;
	t_token	*cur;

	head_sub = NULL;
	new_node = NULL;
	parent_node = NULL;
	cur = (*tokens)->next;
	while (cur && !(cur->type == T_SUBSHELL && ft_strequal(cur->value, ")")))
	{
		new_node = ft_create_node_tree(cur->type, cur->value);
		if (!head_sub)
			head_sub = new_node;
		else if (parent_node)
		{
			if (cur->type == T_PIPE || cur->type == T_AND || cur->type == T_OR)
			{
				new_node->left = head_sub;
				head_sub = new_node;
			}
			else
				parent_node->right = new_node;
		}
		parent_node = new_node;
		cur = cur->next;
	}
	if (cur && cur->type == T_SUBSHELL && ft_strequal(cur->value, ")"))
		cur = cur->next;
	*tokens = cur;
	return (head_sub);
}

t_tree	*ft_handle_var(t_token **cur, t_tree **parent_node)
{
	t_tree *new_node;
	
	new_node = ft_create_node_tree((*cur)->type, (*cur)->value);
	if (*parent_node)
		(*parent_node)->next = new_node;
	*parent_node = new_node;
	*cur = (*cur)->next;
	if (*cur && (*cur)->type == T_KEY)
	{
		new_node = ft_create_node_tree((*cur)->type, (*cur)->value);
		(*parent_node)->next = new_node;
		*parent_node = new_node;
		*cur = (*cur)->next;
	}
	return (new_node);
}

t_tree	*ft_handle_cmd(t_token **cur, t_tree **head, t_tree **parent_node)
{
	t_tree *new_node;
	
	new_node = ft_create_node_tree((*cur)->type, (*cur)->value);
	if (!*head)
		*head = new_node;
	else
		(*parent_node)->next = new_node;
	*parent_node = new_node;
	*cur = (*cur)->next;
	return (new_node);
}
