/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_pipex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 20:17:38 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/09/20 11:10:43 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_fill_pipex(t_shell *shell)
{
	t_tree	*current;
	t_pipex	*pipex;

	current = shell->tree;
	pipex = shell->pipex;
	while (current)
	{
		if (current->type == T_CMD)
		{
			pipex->path_cmd = ft_concat_path_cmd(shell->pipex, current->cmd);
			pipex->a_cmd_opt[0] = ft_strdup(pipex->path_cmd);
		}
		else if (current->type == T_BUILTIN)
			pipex->builtin = 1;
		else if (current->type == T_OPT)
			pipex->a_cmd_opt = ft_append_str(pipex->a_cmd_opt, current->cmd);
		else if (current->type == T_F_OUT)
		{
			pipex->file_out = ft_strdup(current->next->cmd);
			pipex->fd_out = open(pipex->file_out, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		}
		else if (current->type == T_F_OUT_APPEND)
		{
			pipex->file_out = ft_strdup(current->next->cmd);
			pipex->fd_out = open(pipex->file_out, O_WRONLY | O_CREAT | O_APPEND, 0644);
			pipex->append = 1;
		}
		else if (current->type == T_F_IN)
		{
			pipex->file_in = ft_strdup(current->next->cmd);
			pipex->fd_in = open(pipex->file_in, O_WRONLY);
		}
		else if (current->type == T_HEREDOC)
		{
			pipex->here_doc = 1;
			pipex->limiter = ft_strdup(current->next->cmd);
		}
		current = current->next;
	}
}