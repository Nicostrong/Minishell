/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 14:52:43 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/08/28 10:14:25 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_builtin(t_data *data, t_env **env)
{
	char	*cmd;

	cmd = data->cmd;
	if (!ft_strncmp(cmd, "echo ", 5) || ft_strequal(cmd, "echo"))
		data->code_child = ft_echo(data, *env);
	else if (!ft_strncmp(cmd, "cd ", 3) || ft_strequal(cmd, "cd"))
		data->code_child = ft_cd(data, *env);
	else if (!ft_strncmp(cmd, "pwd", 3))
		data->code_child = ft_pwd(*env);
	else if (!ft_strncmp(cmd, "export ", 7) || ft_strequal(cmd, "export"))
		data->code_child = ft_export(data, *env);
	else if (!ft_strncmp(cmd, "unset", 5))
		data->code_child = ft_unset(data, env);
	else if (!ft_strncmp(cmd, "env", 3))
		data->code_child = ft_env(env);
	else if (!ft_strncmp(cmd, "exit", 5))
		ft_exit(data, env);
	else
		return ;
}
