/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tree.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 09:59:20 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/09/11 12:08:51 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/*
 *	create tree
 */

t_tree	*ft_parse_token_to_tree(t_token **tokens)
{
	t_token	*cur;
	t_tree	*head;
	t_tree	*parent_node;

	cur = *tokens;
	head = NULL;
	parent_node = NULL;
	while (cur)
	{
		if (cur->type == T_WORD || cur->type == T_CMD || cur->type == T_BUILTIN)
			ft_handle_cmd(&cur, &head, &parent_node);
		else if (cur->type == T_VAR)
			ft_handle_var(&cur, &parent_node);
		else if (cur->type == T_PIPE || cur->type == T_OR || cur->type == T_AND)
		{
			ft_handle_pipe_or_and(&cur, &head);
			return (head);
		}
		else if (cur->type == T_F_IN || cur->type == T_HEREDOC || cur->type == T_F_OUT || cur->type == T_F_OUT_APPEND)
			ft_handle_file(&cur, &parent_node);
		else if (cur->type == T_SUBSHELL && ft_strequal(cur->value, "("))
			ft_handle_sub(&cur, &head, &parent_node);
		else if (cur->type == T_OPT)
			ft_handle_option(&cur, &parent_node);
		else if (cur->type == T_DQUOTE || cur->type == T_SQUOTE)
			ft_handle_quote(&cur, &parent_node);
		else
			cur = cur->next;
	}
	return (head);
}

///////////////////////////////////////////////////////////////////////////////
//		DEBUG	DEBUG	DEBUG	DEBUG	DEBUG	DEBUG	DEBUG	DEBUG	DEBUG
///////////////////////////////////////////////////////////////////////////////

void	ft_print_tree(t_tree *node, int depth)
{
	int	i;

	i = -1;
	if (!node)
		return ;
	while (++i < depth)
		printf("\t");
	printf("NODE : %s\n", ft_get_token_name(node->type));
	if (node->cmd)
	{
		i = -1;
		while (++i < depth)
			printf("\t");
		printf("Commande : %s\n", node->cmd);
	}
	if (node->left)
	{
		i = -1;
		while (++i < depth)
			printf("\t");
		printf("LEFT :\n");
		ft_print_tree(node->left, depth + 1);
	}
	if (node->right)
	{
		i = -1;
		while (++i < depth)
			printf("\t");
		printf("RIGHT :\n");
		ft_print_tree(node->right, depth + 1);
	}
	if (node->next)
	{
		i = -1;
		while (++i < depth)
			printf("\t");
		printf("Next :\n");
		ft_print_tree(node->next, depth);
	}
}
/*
t_tree	*ft_parse_token_to_tree(t_token **tokens)
{
	t_token	*cur;
	t_tree	*head;
	t_tree	*new_node;
	t_tree	*parent_node;

	cur = *tokens;
	head = NULL;
	parent_node = NULL;
	while (cur)
	{
		if (cur->type == T_WORD || cur->type == T_CMD || cur->type == T_BUILTIN)
		{
			new_node = ft_create_node_tree(cur->type, cur->value);
			if (!head)
				head = new_node;
			else
				parent_node->next = new_node;
			parent_node = new_node;
			cur = cur->next;
		}
		else if (cur->type == T_VAR)
		{
			new_node = ft_create_node_tree(cur->type, cur->value);
			if (parent_node)
				parent_node->next = new_node;
			parent_node = new_node;
			cur = cur->next;
			if (cur && cur->type == T_KEY)
			{
				new_node = ft_create_node_tree(cur->type, cur->value);
				parent_node->next = new_node;
				parent_node = new_node;
				cur = cur->next;
			}
		}
		else if (cur->type == T_PIPE || cur->type == T_OR || cur->type == T_AND)
		{
			new_node = ft_create_node_tree(cur->type, NULL);
			new_node->left = head;
			cur = cur->next;
			if (cur)
			{
				new_node->right = ft_parse_token_to_tree(&cur);
				head = new_node;
			}
			return (head);
		}
		else if (cur->type == T_F_IN || cur->type == T_HEREDOC || cur->type == T_F_OUT || cur->type == T_F_OUT_APPEND)
		{
			new_node = ft_create_node_tree(cur->type, NULL);
			cur = cur->next;
			if (cur && cur->type == T_FILENAME)
			{
				new_node->right = ft_create_node_tree(cur->type, cur->value);
				if (parent_node)
					parent_node->next = new_node;
				parent_node = new_node;
				cur = cur->next;
			}
		}
		else if (cur->type == T_SUBSHELL && ft_strequal(cur->value, "("))
		{
			new_node = ft_parse_subshell(&cur);
			if (!head)
				head = new_node;
			else
				parent_node->next = new_node;
			parent_node = new_node;
		}
		else if (cur->type == T_OPT)
		{
			new_node = ft_create_node_tree(cur->type, cur->value);
			if (parent_node)
				parent_node->next = new_node;
			parent_node = new_node;
			cur = cur->next;
		}
		else if (cur->type == T_DQUOTE || cur->type == T_SQUOTE)
		{
			new_node = ft_create_node_tree(cur->type, cur->value);
			if (parent_node)
				parent_node->next = new_node;
			parent_node = new_node;
			cur = cur->next;
		}
		else
			cur = cur->next;
	}
	return (head);
}*/