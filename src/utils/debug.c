/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 13:52:37 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/09/22 15:17:15 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

///////////////////////////////////////////////////////////////////////////////
//		DEBUG	DEBUG	DEBUG	DEBUG	DEBUG	DEBUG	DEBUG	DEBUG	DEBUG
///////////////////////////////////////////////////////////////////////////////

static char	*ft_get_token_name(e_token token)
{
	switch (token)
	{
		case T_WORD:			return "T_WORD";
		case T_BUILTIN:			return "T_BUILTIN";
		case T_CMD:				return "T_CMD";
		case T_OPT:				return "T_OPT";
		case T_PIPE:			return "T_PIPE";
		case T_OR:				return "T_OR";
		case T_AND:				return "T_AND";
		case T_F_IN:			return "T_F_IN";
		case T_HEREDOC:			return "T_HEREDOC";
		case T_EOF:				return "T_EOF";
		case T_F_OUT:			return "T_F_OUT";
		case T_F_OUT_APPEND:	return "T_F_OUT_APPEND";
		case T_FILENAME:		return "T_FILENAME";
		case T_SUBSHELL:		return "T_SUBSHELL";
		case T_DQUOTE:			return "T_DQUOTE";
		case T_SQUOTE:			return "T_SQUOTE";
		case T_VAR:				return "T_VAR";
		case T_KEY:				return "T_KEY";
		case T_WILDCARD:		return "T_WILDCARD";
		case T_END:				return "T_END";
		default:				return "UNKNOWN";
	}
}

static void	ft_print_tokens(t_token *tokens)
{
	t_token	*current;

	current = tokens;
	while (current)
	{
		printf("Token = %s\t\ttype = %s\n", current->value, ft_get_token_name(current->type));
		current = current->next;
	}
}

static void	ft_print_tree(t_tree *node, int depth)
{
	int	i;

	i = -1;
	if (!node)
		return ;
	while (++i < depth)
		printf("\t");
	printf("NODE : %s\n", ft_get_token_name(node->type));
	if (node->value)
	{
		i = -1;
		while (++i < depth)
			printf("\t");
		printf("Commande : %s\n", node->value);
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

void	ft_print_pipex(t_pipex *pipex)
{
	printf("PIPEX STRUCURE :\n");
	printf("fd_in = %d\n", pipex->fd_in);
	printf("fd_out = %d\n", pipex->fd_in);
	printf("bool append = %s\n", pipex->append ? "TRUE" : "FALSE");
	printf("bool here_doc = %s\n", pipex->here_doc ? "TRUE" : "FALSE");
	printf("bool builtin = %s\n", pipex->builtin ? "TRUE" : "FALSE");
	printf("Limiter = %s\n", pipex->limiter);
	printf("file_in = %s\n", pipex->file_in);
	printf("file_out = %s\n", pipex->file_out);
	printf("path_cmd = %s\n", pipex->path_cmd);
	printf("PATH ARRAY :\n");
	ft_putstrarray(pipex->a_path);
	printf("CMD OPT ARRAY :\n");
	ft_putstrarray(pipex->a_cmd_opt);
	printf("ENV ARRAY :\n");
	ft_putstrarray(pipex->a_env);
}

void	ft_print_all(t_shell *shell)
{
	printf("Tokens de la commande :\n");
	ft_print_tokens(shell->l_token);
	printf("Arbre de la commande :\n");
    ft_print_tree(shell->tree, 0);
}