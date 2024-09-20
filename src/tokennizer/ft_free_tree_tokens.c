/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_tree_tokens.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 15:12:37 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/09/20 09:53:47 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/*
 * <cat>minishell</cat>
 *
 * <summary>
 * 	void	ft_free_env(t_env *env)
 * </summary>
 *
 * <description>
 * 	ft_free_env free all pointer and node of the linked list env.
 * </description>
 *
 * <param type="t_env *" name="env">linked list env</param>
 *
 * <return>
 * 	void.
 * </return>
 *
 */

void	ft_free_env(t_env *env)
{
	t_env	*current;
	t_env	*next;

	next = env;
	while (next)
	{
		current = next;
		next = current->next;
		free(current->key);
		free(current->value);
		free(current);
	}
	env = NULL;
}

/*
 * <cat>minishell</cat>
 *
 * <summary>
 * 	void	ft_free_tokens(t_token *tokens)
 * </summary>
 *
 * <description>
 * 	ft_free_tokens free all tokens on the linked list tokens.
 * </description>
 *
 * <param type="t_token *" name="tokens">linked list token</param>
 *
 * <return>
 * 	void.
 * </return>
 *
 */

void	ft_free_tokens(t_token *tokens)
{
	t_token	*cur;
	t_token	*next;

	if (!tokens)
		return ;
	cur = tokens;
	while (cur)
	{
		next = cur->next;
		if (cur->value)
			free(cur->value);
		free(cur);
		cur = next;
	}
}

/*
 * <cat>minishell</cat>
 *
 * <summary>
 * 	void	ft_free_tree(t_tree *tree)
 * </summary>
 *
 * <description>
 * 	ft_free_tree free the complete tree of tokens.
 * </description>
 *
 * <param type="t_tree *" name="tree">tree AST of tokens</param>
 *
 * <return>
 * 	void.
 * </return>
 *
 */

void	ft_free_tree(t_tree *tree)
{
	if (!tree)
		return;
	if (tree->left)
	{
		ft_free_tree(tree->left);
		tree->left = NULL;
	}
	if (tree->right)
	{
		ft_free_tree(tree->right);
		tree->right = NULL;
	}
	if (tree->next)
	{
		ft_free_tree(tree->next);
		tree->next = NULL;
	}
	if (tree->cmd)
	{
		free(tree->cmd);
		tree->cmd = NULL;
	}
	if (tree)
		free(tree);
}

/*
 * <cat>minishell</cat>
 *
 * <summary>
 * 	void	ft_free_pipex(t_pipex *pipex)
 * </summary>
 *
 * <description>
 * 	ft_free_pipex free all element of pipes structure.
 * </description>
 *
 * <param type="t_pipex *" name="pipex">pipex structure</param>
 *
 * <return>
 * 	void.
 * </return>
 *
 */

void	ft_free_pipex(t_pipex *pipex)
{
	if (!pipex)
		return ;
	if (pipex->limiter)
		free(pipex->limiter);
	if (pipex->file_in)
		free(pipex->file_in);
	if (pipex->file_out)
		free(pipex->file_out);
	if (pipex->path_cmd)
		free(pipex->path_cmd);
	if (pipex->a_path)
		ft_free_array(pipex->a_path);
	if (pipex->a_cmd_opt)
		ft_free_array(pipex->a_cmd_opt);
	if (pipex->a_env)
		ft_free_array(pipex->a_env);
	free(pipex);
}

/*
 * <cat>minishell</cat>
 *
 * <summary>
 * 	void	ft_free_all(t_shell *shell)
 * </summary>
 *
 * <description>
 * 	ft_free_all free all structure allocated for the program.
 * </description>
 *
 * <param type="t_shell *" name="shell">structure with all other struct</param>
 *
 * <return>
 * 	void.
 * </return>
 *
 */

void	ft_free_all(t_shell *shell)
{
	if (shell->l_env)
		ft_free_env(shell->l_env);
	if (shell->l_token)
		ft_free_tokens(shell->l_token);
	if (shell->tree)
		ft_free_tree(shell->tree);
	if (shell->pipex)
		ft_free_pipex(shell->pipex);
	free(shell);
}