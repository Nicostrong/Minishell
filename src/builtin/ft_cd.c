/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 10:22:28 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/08/30 14:03:03 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/*
 * <cat>minishell</cat>
 *
 * <summary>
 * 	int	ft_go_home(t_env **env)
 * </summary>
 *
 * <description>
 * 	ft_go_home change the directory to the home directory and update somes env.
 * </description>
 *
 * <param type="t_env **" name="env">linked list env</param>
 *
 * <return>
 * 	0 if success or 1 if error.
 * </return>
 *
 */

static int	ft_go_home(t_env **env)
{
	char	*home;
	char	*oldpwd;

	home = ft_get_env_value(*env, "HOME");
	if (!home || chdir(home) == -1)
		ft_put_error_cmd_exit("cd", "HOME not set", 1);
	oldpwd = ft_get_env_value(*env, "PWD");
	ft_set_env_value(env, "OLDPWD", oldpwd);
	ft_set_env_value(env, "PWD", home);
	return (0);
}

/*
 * <cat>minishell</cat>
 *
 * <summary>
 * 	int	ft_go_back(t_env **env, char **array)
 * </summary>
 *
 * <description>
 * 	ft_go_back change the directory to the oldpwd directory and update somes env.
 * </description>
 *
 * <param type="t_env **" name="env">linked list env</param>
 * <param type="char **" name="array">array of options</param>
 *
 * <return>
 * 	0 if success or 1 if error.
 * </return>
 *
 */

static int	ft_go_back(t_env **env, char **array)
{
	char	*old_pwd;
	char	*pwd;

	if (array[1][1])
	{
		printf("cd: usage: cd [-L|[-P [-e]] [-@]] [dir]\n");
		return (2);
	}
	pwd = ft_strdup(ft_get_env_value(*env, "PWD"));
	old_pwd = ft_strdup(ft_get_env_value(*env, "OLDPWD"));
	if (!old_pwd || chdir(old_pwd) == -1)
	{
		free(pwd);
		free(old_pwd);
		ft_put_error_cmd_exit("cd", "OLDPWD not set", 1);
	}
	printf("%s\n", old_pwd);
	ft_set_env_value(env, "OLDPWD", pwd);
	ft_set_env_value(env, "PWD", old_pwd);
	return (free(pwd), free(old_pwd), 0);
}

/*
 * <cat>minishell</cat>
 *
 * <summary>
 * 	int	ft_go_cd(t_env **env)
 * </summary>
 *
 * <description>
 * 	ft_go_cd change the directory and update somes env.
 * </description>
 *
 * <param type="t_env **" name="env">linked list env</param>
 *
 * <return>
 * 	0 if success or 1 if error.
 * </return>
 *
 */

int	ft_go_cd(t_env **env)
{
	char	*old_pwd;
	char	*new_pwd;

	old_pwd = ft_get_env_value(*env, "PWD");
	if (old_pwd)
		ft_set_env_value(env, "OLDPWD", old_pwd);
	new_pwd = getcwd(NULL, 0);
	if (new_pwd)
		ft_set_env_value(env, "PWD", new_pwd);
	free(new_pwd);
	return (0);
}

/*
 * <cat>minishell</cat>
 *
 * <summary>
 * 	int	ft_cd(t_data *data, t_env **env)
 * </summary>
 *
 * <description>
 * 	ft_cd is like a bultin function cd in bash. It's checking the nomber of 
 * 	argument and call a different function compared to argument list.
 * </description>
 *
 * <param type="t_data *" name="data">structure data</param>
 * <param type="t_env **" name="env">linked list env</param>
 *
 * <return>
 * 	0 if success or 1 if error.
 * </return>
 *
 */

int	ft_cd(t_data *data, t_env **env)
{
	char	**array;
	int		code_ret;

	array = ft_split(data->cmd, ' ');
	code_ret = 0;
	if (array[1] && array[2])
	{
		ft_free_array(array);
		ft_put_error_cmd_exit(array[0], "too many arguments", 1);
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
