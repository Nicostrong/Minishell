/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 14:52:43 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/08/23 15:11:14 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_pwd(t_env **env)
{
	t_env	*current;

	current = *env;
	while (ft_strncmp(current->value, "PWD=", 4))
		current = current->next;
	printf("%s\n", current->value + 4);
	return (0);
}


void	ft_builtin(t_data *data, t_env *env)
{
	char	*cmd;

	cmd = data->cmd;
	if (!ft_strncmp(cmd, "echo ", 5) || ft_strequal(cmd, "echo"))
		ft_echo(data);
	else if (!ft_strncmp(cmd, "cd ", 3) || ft_strequal(cmd, "cd"))
		ft_cd(cmd, env, data);
	else if (ft_strequal(cmd, "pwd"))
		ft_pwd(&env);
	/*else if (!ft_strncmp(cmd, "export", 6))
		ft_export(data);
	else if (!ft_strncmp(cmd, "unset", 5))
		ft_unset(data);*/
	else if (!ft_strncmp(cmd, "env", 3))
		ft_env(env);
	else if (!ft_strncmp(cmd, "exit", 5))
		ft_exit(data);
	else
		return ;
}