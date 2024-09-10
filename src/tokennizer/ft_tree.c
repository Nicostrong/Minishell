/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tree.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 09:59:20 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/09/09 21:43:12 by nfordoxc         ###   Luxembourg.lu     */
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
	t_token	*cur;

	cur = (*tokens)->next;
	head_sub = ft_parse_token_to_tree(&cur);
	while (cur && !(cur->type == T_SUBSHELL && ft_strequal(cur->value, ")")))
		cur = cur->next;
	if (cur && cur->type == T_SUBSHELL && ft_strequal(cur->value, ")"))
		cur = cur->next;
	*tokens = cur;
	return (head_sub);
}

/*
 *	create tree
 */

t_tree	*ft_parse_token_to_tree(t_token **tokens)
{
	t_token	*cur;
	t_tree	*head;
	t_tree	*new_node;

	cur = *tokens;
	head = NULL;
	while (cur)
	{
		if (cur->type == T_WORD || cur->type == T_CMD || cur->type == T_BUILTIN)
		{
			new_node = ft_create_node_tree(cur->type, cur->value);
			if (!head)
				head = new_node;
			else
				head->next = new_node;
			cur = cur->next;
		}
		else if (cur->type == T_VAR)
		{
			new_node = ft_create_node_tree(cur->type, cur->value);
			if (head)
				head->next = new_node;
			cur = cur->next;
			if (cur && cur->type == T_KEY)
			{
				new_node = ft_create_node_tree(cur->type, cur->value);
				head->next->next = new_node;
				cur = cur->next;
			}
		}
		else if (cur->type == T_PIPE || cur->type == T_OR || cur->type == T_AND)
		{
			new_node = ft_create_node_tree(cur->type, NULL);
			new_node->left = head;
			cur = cur->next;
			new_node->right = ft_parse_token_to_tree(&cur);
			head = new_node;
			break ;
		}
		else if (cur->type == T_F_IN || cur->type == T_HEREDOC || cur->type == T_F_OUT || cur->type == T_F_OUT_APPEND)
		{
			new_node = ft_create_node_tree(cur->type, NULL);
			cur = cur->next;
			if (cur && cur->type == T_FILENAME)
			{
				new_node->right = ft_create_node_tree(cur->type, cur->value);
				if (head)
					head->next = new_node;
				cur = cur->next;
			}
		}
		else if (cur->type == T_SUBSHELL && ft_strequal(cur->value, "("))
		{
			new_node = ft_parse_subshell(&cur);
			if (!head)
				head = new_node;
			else
				head->next = new_node;
		}
		else if (cur->type == T_OPT)
		{
			new_node = ft_create_node_tree(cur->type, cur->value);
			if (head)
				head->next = new_node;
			cur = cur->next;
		}
		else if (cur->type == T_DQUOTE || cur->type == T_SQUOTE)
		{
			new_node = ft_create_node_tree(cur->type, cur->value);
			if (head)
				head->next = new_node;
			cur = cur->next;
		}
		else
			cur = cur->next;
	}
	return (head);
}

///////////////////////////////////////////////////////////////////////////////
//		DEBUG	DEBUG	DEBUG	DEBUG	DEBUG	DEBUG	DEBUG	DEBUG	DEBUG
///////////////////////////////////////////////////////////////////////////////

void	ft_print_tree(t_tree *node)
{
	if (!node)
		return ;
	if (node->type)
		printf("NODE : %s\n", ft_get_token_name(node->type));
	if (node->cmd)
		printf("Commande : %s\n", node->cmd);
	if (node->left)
	{
		printf("LEFT :\n");
		ft_print_tree(node->left);
	}
	if (node->right)
	{
		printf("RIGHT :\n");
		ft_print_tree(node->right);
	}
	if (node->next)
	{
		printf("Next :\n");
		ft_print_tree(node->next);
	}
}