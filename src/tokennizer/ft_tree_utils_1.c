/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tree_utils_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 15:56:16 by phkevin           #+#    #+#             */
/*   Updated: 2024/09/18 14:18:01 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

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
		new_node->next = ft_create_node_tree((*cur)->type, (*cur)->value);
		*cur = (*cur)->next;
	}
	if (*parent_node)
		(*parent_node)->next = new_node;
	*parent_node = new_node;
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