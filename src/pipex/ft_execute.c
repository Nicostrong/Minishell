/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 16:02:54 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/09/20 11:17:19 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/*
 *	Fonction pour executer builtin
 */

int	ft_exec_builtin(t_shell *shell, t_tree *node)
{
	char 	*cmd;
	t_tree	*arg;

	cmd = node->cmd;
	if (!ft_strncmp(cmd, "cd", 2))
	{
		arg = node->next;
		if (arg && chdir(arg->cmd) != 0)
			perror("cd");
		return (0);
	}
	else if (!ft_strncmp(cmd, "echo", 4))
	{
		arg = node->next;
		while (arg)
		{
			if (arg->type == T_VAR)
				printf("%s", ft_get_env_value(shell->l_env, arg->cmd));
			else
				printf("%s", arg->cmd);
			arg = arg->next;
			if (arg)
				printf(" ");
		}
		printf("\n");
		return (0);
	}
	return (-1);
}

/*
 *	Fonction pour executer une commande
 */

int	ft_exec_cmd(t_shell *shell, t_tree *node)
{
	int		pid;
	t_pipex	*pipex;
	
	pipex = shell->pipex;
	pid = fork();
	if (pid == 0)
	{
		if (execve(pipex->path_cmd, pipex->a_cmd_opt, pipex->a_env) == -1)
		{
			perror("Erreur execve");
			exit(EXIT_FAILURE);
		}
	}
	else if (pid > 0)
	{
		waitpid(pid, &shell->code_exit, 0);
		update_exit_code(shell, WEXITSTATUS(shell->code_exit));
	}
	else
	{
		perror("Erreur fork");
		return (-1);
	}
	return (0);
}

/*
*	Fonction pour exécuter un nœud de commande de l'AST
*/

int	ft_exec_tree(t_shell *shell, t_tree *node)
{

	int pipefd[2];
	int	pid;

	if (!node)
		return (0);
	switch (node->type)
	{
		case T_PIPE:
		{
			if (ft_pipe(pipefd) == -1)
			{
				perror("Erreur pipe");
				return (-1);
			}
			pid = fork();
			if (pid == 0)
			{
				close(pipefd[0]);
				dup2(pipefd[1], STDOUT_FILENO);
				close(pipefd[1]);
				ft_exec_tree(shell, node->left);
				exit(shell->code_exit);
			}
			else if (pid > 0)
			{
				close(pipefd[1]);
				dup2(pipefd[0], STDIN_FILENO);
				close(pipefd[0]);
				ft_exec_tree(shell, node->right);
				waitpid(pid, &shell->code_exit, 0);
			}
			break;
		}
		case T_AND:
		{
			ft_exec_tree(shell, node->left);
			if (shell->code_exit == 0)
				ft_exec_tree(shell, node->right);
			break;
		}
		case T_BUILTIN:
		{
			ft_exec_tree(shell, node);
			break;
		}
		case T_CMD:
		{
			ft_exec_cmd(shell, node);
			break;
		}
	}
	return (0);
}

/*
 *	execute pipex
 */

void	ft_execute_pipex(t_pipex *pipex)
{
	char	*line;
	int		fd_heredoc;

	if (pipex->here_doc)
	{
		fd_heredoc = open(".heredoc_tmp", O_WRONLY | O_CREAT | O_TRUNC, 0644);
		while (1)
		{
			line = get_next_line(0);
			if (ft_strequal(line, pipex->limiter))
				break;
			write(fd_heredoc, line, ft_strlen(line));
			free(line);
		}
		get_next_line(-1);
		close(fd_heredoc);
		pipex->fd_in = open(".heredoc_tmp", O_RDONLY);
	}
	if (pipex->fd_in != -1)
		dup2(pipex->fd_in, STDIN_FILENO);
	if (pipex->fd_out != -1)
		dup2(pipex->fd_out, STDOUT_FILENO);
	if (!pipex->path_cmd)
	{
		ft_putstr_fd("Command not found\n", 2);
		exit(1);
	}
	execve(pipex->path_cmd, pipex->a_cmd_opt, pipex->a_env);
	perror("execve");
	exit(1);
}