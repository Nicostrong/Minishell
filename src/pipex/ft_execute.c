/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 16:02:54 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/09/12 09:33:32 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/*
 *	Fonction pour exécuter un nœud de commande de l'AST
 */

int	ft_exec_cmd_node(t_tree *node, int input_fd, int output_fd, char **envp)
{
	char	**args;
	int	pid;

	if (node->type == T_CMD || node->type == T_BUILTIN)
	{
		pid = fork();
		if (pid == 0)
		{
			if (input_fd != STDIN_FILENO)
			{
				dup2(input_fd, STDIN_FILENO);
				close(input_fd);
			}
			if (output_fd != STDOUT_FILENO)
			{
				dup2(output_fd, STDOUT_FILENO);
				close(output_fd);
			}

			*args[0] = node->cmd;
			*args[1] = NULL;
			execvp(node->cmd, args);
			perror("execvp failed");
			exit(EXIT_FAILURE);
		}
		else if (pid < 0)
		{
			perror("fork failed");
			return -1;
		}
		else
			waitpid(pid, NULL, 0);
	}
	return (0);
}

/*
 *	fonction execute AST
 */

int	ft_exec_ast(t_tree *node, char **envp)
{
    int	pipefd[2];
    int	input_fd;
    int	status;
	int	pid;

	input_fd = STDIN_FILENO;
	status = 0;
    while (node)
    {
        if (node->type == T_PIPE)
        {
            pipe(pipefd);
            ft_exec_cmd_node(node->left, input_fd, pipefd[1], envp);
            close(pipefd[1]);
            input_fd = pipefd[0];
            node = node->right;
        }
        else if (node->type == T_AND)
            if (ft_exec_ast(node->left, envp) == 0)
                status = execute_ast(node->right, envp);
        else if (node->type == T_OR)
            if (ft_exec_ast(node->left, envp) != 0)
                status = ft_exec_ast(node->right, envp);
        else if (node->type == T_SUBSHELL)
        {
            pid = fork();
            if (pid == 0)
            {
                execute_ast(node->left, envp);
                exit(EXIT_SUCCESS);
            }
            else if (pid > 0)
                waitpid(pid, &status, 0);
            else
            {
                perror("fork failed");
                return -1;
            }
            break ;
        }
        else
        {
            ft_exec_cmd_node(node, input_fd, STDOUT_FILENO, envp);
            break ;
        }
    }
    return (status);
}