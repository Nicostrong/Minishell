/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 14:52:43 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/08/29 11:15:18 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

/*
 * <cat>minishell</cat>
 *
 * <summary>
 * 	void	ft_builtin(t_data *data, t_env **env)
 * </summary>
 *
 * <description>
 * 	ft_builtin check the command value entered by the user is a builtin function
 * 	If it's a builtin function, it's running the command function or do nothing.
 * </description>
 *
 * <param type="t_data *" name="data">data struct</param>
 * <param type="t_env **" name="env">linked list env</param>
 *
 * <return>
 * 	void.
 * </return>
 *
 */

void	ft_builtin(t_data *data, t_env **env)
{
	char	*cmd;
	char	**a_cmd;

	cmd = data->cmd;
	a_cmd = ft_split(cmd, ' ');
	if (ft_strequal(a_cmd[0], "echo"))
		data->code_child = ft_echo(data, *env);
	else if (ft_strequal(a_cmd[0], "cd"))
		data->code_child = ft_cd(data, env);
	else if (ft_strequal(a_cmd[0], "pwd"))
		data->code_child = ft_pwd(*env);
	else if (ft_strequal(a_cmd[0], "export"))
		data->code_child = ft_export(data, *env);
	else if (ft_strequal(a_cmd[0], "unset"))
		data->code_child = ft_unset(data, env);
	else if (ft_strequal(a_cmd[0], "env"))
		data->code_child = ft_env(data, env);
	else if (ft_strequal(a_cmd[0], "exit"))
		ft_exit(data, env);
	else
	{
		ft_print_error(a_cmd[0]);
		data->code_child = 127;
	}
	ft_free_array(a_cmd);
}
