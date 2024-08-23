/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 14:52:43 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/08/23 10:03:41 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_pwd(t_data *data)
{
	getcwd(data->pwd, sizeof(data->pwd));
	ft_putendl_fd(data->pwd, 1);
	data->code_child = 0;
	return (0);
}


void	ft_builtin(t_data *data)
{
	if (!ft_strncmp(data->cmd, "echo", 4))
		ft_echo(data);
	else if (!ft_strncmp(data->cmd, "cd", 2))
		ft_cd(data);
	else if (ft_strequal(data->cmd, "pwd"))
		ft_pwd(data);
	/*else if (!ft_strncmp(data->cmd, "export", 6))
		ft_export(data);
	else if (!ft_strncmp(data->cmd, "unset", 5))
		ft_unset(data);*/
	else if (!ft_strncmp(data->cmd, "env", 3))
		ft_env(data);
	else if (!ft_strncmp(data->cmd, "exit", 5))
		ft_exit(data);
	else
		return ;
}