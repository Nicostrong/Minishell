/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tree_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 11:32:16 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/09/11 13:06:02 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/*
 *	create node tree
 */

static t_tree	*ft_create_node_tree(e_token type, char *cmd)
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

/*
 *	parse for subshell
 */

static t_tree	*ft_parse_subshell(t_token **tokens)
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
	if (*cur && (*cur)->type == T_KEY) {
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

t_tree	*ft_handle_pipe_or_and(t_token **cur, t_tree **head)
{
    t_tree *new_node;
	
	new_node = ft_create_node_tree((*cur)->type, NULL);
    new_node->left = *head;
    *cur = (*cur)->next;
    if (*cur)
	{
        new_node->right = ft_parse_token_to_tree(cur);
        *head = new_node;
    }
    return (new_node);
}

t_tree	*ft_handle_file(t_token **cur, t_tree **parent_node)
{
	t_tree *new_node;
	
	new_node = ft_create_node_tree((*cur)->type, NULL);
	*cur = (*cur)->next;
	if (*cur && (*cur)->type == T_FILENAME)
	{
		new_node->right = ft_create_node_tree((*cur)->type, (*cur)->value);
		if (*parent_node)
			(*parent_node)->next = new_node;
		*parent_node = new_node;
		*cur = (*cur)->next;
	}
	return (new_node);
}

t_tree	*ft_handle_sub(t_token **cur, t_tree **head, t_tree **parent_node)
{
	t_tree *new_node;
	
	new_node = ft_parse_subshell(cur);
	if (!*head)
		*head = new_node;
	else
		(*parent_node)->next = new_node;
	*parent_node = new_node;
	return (new_node);
}

t_tree	*ft_handle_option(t_token **cur, t_tree **parent_node)
{
	t_tree *new_node;
	
	new_node = ft_create_node_tree((*cur)->type, (*cur)->value);
	if (*parent_node)
		(*parent_node)->next = new_node;
	*parent_node = new_node;
	*cur = (*cur)->next;
	return (new_node);
}

t_tree	*ft_handle_quote(t_token **cur, t_tree **parent_node)
{
	t_tree *new_node;
	
	new_node = ft_create_node_tree((*cur)->type, (*cur)->value);
	if (*parent_node)
		(*parent_node)->next = new_node;
	*parent_node = new_node;
	*cur = (*cur)->next;
	return (new_node);
}