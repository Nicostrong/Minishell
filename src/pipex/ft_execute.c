/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 16:02:54 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/09/13 09:06:56 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/*
 *	Fonction pour exécuter un nœud de commande de l'AST
*/

int	ft_exec_tree(t_tree *node)
{
	int	pid;
	int	status;

	if (!node)
		return (0);
	if (is_builtin(node->args[0]))
		return (ft_exec_builtin(node->args));
	else
	{
		pid = fork();
		if (pid == 0)
		{
			if (execve(node->args[0], node->args, environ) == -1)
			{
				perror("Erreur execve");
				exit(EXIT_FAILURE);
			}
		}
		else if (pid > 0)
		{
			waitpid(pid, &status, 0);
			if (WIFEXITED(status))
				return WEXITSTATUS(status);
		}
		else
		{
			perror("Erreur fork");
			return (-1);
		}
	}
	ft_exec_tree(node->left);
	ft_exec_tree(node->right);
	return (0);
}