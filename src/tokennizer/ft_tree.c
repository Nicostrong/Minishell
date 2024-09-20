/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tree.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 09:59:20 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/09/20 09:21:30 by nfordoxc         ###   Luxembourg.lu     */
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
	t_tree	*heredoc;
	t_tree	*cmd_node;

	cur = *tokens;
	head = NULL;
	parent_node = NULL;
	while (cur)
	{
		if (cur->type == T_HEREDOC)
		{
			heredoc = ft_parse_heredoc(&cur);
			if (!head)
				head = heredoc;
			else
				parent_node->next = heredoc;
			parent_node = heredoc->next;
		}
		else if (cur->type >= T_WORD && cur->type <= T_CMD)
		{
			cmd_node = ft_handle_cmd(&cur, &head, &parent_node);
			parent_node = cmd_node;
		}
		else if (cur->type == T_VAR)
			ft_handle_var(&cur, &parent_node);
		else if (cur->type >= T_PIPE && cur->type <= T_AND)
		{
			ft_handle_pipe_or_and(&cur, &head);
			return (head);
		}
		else if (cur->type >= T_F_IN && cur->type <= T_F_OUT_APPEND)
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