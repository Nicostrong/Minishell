/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tree_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 14:35:41 by nfordoxc          #+#    #+#             */
/*   Updated: 22/09/2024 17:23:10 by Nicostrong       ###   ########.lu       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/*
 * <cat>minishell</cat>
 *
 * <summary>
 *	t_tree	*ft_create_node_tree(e_token type, char *value)
 * </summary>
 *
 * <description>
 *	ft_create_node_tree create a new node for the tree and set the type and the
 *	cmd value
 * </description>
 *
 * <param type="e_token" name="type">enum of token name</param>
 * <param type="char *" name="value">value to set</param>
 *
 * <return>
 *	a pointer to a new node.
 * </return>
 *
 */

t_tree	*ft_create_node_tree(e_token type, char *value)
{
	t_tree	*node;

	node = (t_tree *)ft_calloc(1, sizeof(t_tree));
	if (!node)
		return (NULL);
	node->type = type;
	if (value)
		node->value = ft_strdup(value);
	else
		node->value = NULL;
	node->left = NULL;
	node->right = NULL;
	node->next = NULL;
	return (node);
}

/*
 * <cat>minishell</cat>
 *
 * <summary>
 *	t_tree	*ft_parse_heredoc(t_token **tokens)
 * </summary>
 *
 * <description>
 *	ft_parse_heredoc parse the T_HEREDOC token to create a heredoc node.
 * </description>
 *
 * <param type="t_token **" name="tokens">list of tokens</param>
 *
 * <return>
 *	a pointer to a new node for the heredoc token.
 * </return>
 *
 */

t_tree	*ft_parse_heredoc(t_token **tokens)
{
	t_tree	*heredoc_node;
	t_tree	*new_node;
	t_token	*cur;

	heredoc_node = ft_create_node_tree((*tokens)->type, NULL);
	cur = (*tokens)->next;
	if (cur && cur->type == T_EOF)
	{
		new_node = ft_create_node_tree(cur->type, cur->value);
		heredoc_node->next = new_node;
		cur = cur->next;
	}
	*tokens = cur;
	return (heredoc_node);
}
