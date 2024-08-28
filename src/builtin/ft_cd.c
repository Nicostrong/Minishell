/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 10:22:28 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/08/28 12:15:55 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	ft_go_home(t_env *env)
{
	char	*home;
	char	*oldpwd;

	home = ft_get_env_value(env, "HOME");
	if (!home || chdir(home) == -1)
	{
		printf(TERM_NAME": cd: HOME not set\n");
		return (1);
	}
	oldpwd = ft_get_env_value(env, "PWD");
	ft_set_env_value(env, "OLDPWD", oldpwd);
	ft_set_env_value(env, "PWD", home);
	return (0);
}

static int	ft_go_back(t_env *env, char **array)
{
	char	*old_pwd;
	char	*pwd;

	if (array[1][1])
	{
		printf("cd: usage: cd [-L|[-P [-e]] [-@]] [dir]\n");
		return (2);
	}
	pwd = ft_get_env_value(env, "PWD");
	old_pwd = ft_get_env_value(env, "OLDPWD");
	if (!old_pwd || chdir(old_pwd) == -1)
	{
		printf(TERM_NAME": cd: OLDPWD not set\n");
		return (1);
	}
	printf("%s\n", old_pwd);
	ft_set_env_value(env, "OLDPWD", pwd);
	ft_set_env_value(env, "PWD", old_pwd);
	return (0);
}

int	ft_go_cd(t_env *env)
{
	char	*old_pwd;
	char	*new_pwd;

	old_pwd = ft_get_env_value(env, "PWD");
	if (old_pwd)
		ft_set_env_value(env, "OLDPWD", old_pwd);
	new_pwd = getcwd(NULL, 0);
	if (new_pwd)
		ft_set_env_value(env, "PWD", new_pwd);
	free(new_pwd);
	return (0);
}

int	ft_cd(t_data *data, t_env *env)
{
	char	**array;
	int		code_ret;

	array = ft_split(data->cmd, ' ');
	code_ret = 0;
	if (!array[1] || array[2])
	{
		ft_free_array(array);
		ft_putendl_fd(TERM_NAME": cd: too many arguments", 2);
		return (1);
	}
	else if (!array[1] || ft_strequal(array[1], "~")
		|| ft_strequal(array[1], "--"))
		code_ret = ft_go_home(env);
	else if (ft_strequal(array[1], "-"))
		code_ret = ft_go_back(env, array);
	else if (chdir(array[1]) == -1)
		return (ft_free_array(array), 1);
	else
		code_ret = ft_go_cd(env);
	ft_free_array(array);
	return (code_ret);
}
