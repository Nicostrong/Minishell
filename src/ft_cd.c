/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 10:22:28 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/08/23 15:33:31 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static char	*ft_get_pwd(t_env *env)
{
	t_env	*current;

	current = env;
	while (current)
	{
		if (!ft_strncmp(current->value, "PWD=", 4))
			return (ft_strdup(current->value));
		current = current->next;
	}
	return (NULL);
}

static void	ft_find_replace(t_env *env, char *find, char *replace)
{
	t_env	*current;

	current = env;
	while (current)
	{
		if (!ft_strncmp(current->value, find, ft_strlen(find)))
		{
			free(current->value);
			current->value = ft_strdup(replace);
			return ;
		}
		current = current->next;
	}
}

void	ft_cd(char *cmd, t_env *env, t_data *data)
{
	char	*old_pwd;
	char	*new_pwd;
	char	*new_path;
	char	*old_path;
	char	**array;

	array = ft_split(cmd, ' ');
	//if (!array[1])
		//pwd = home directory
	if (chdir(array[1]))
	{
		printf("bash: cd: %s: No such file or directory\n", array[1]);
		data->code_child = 1;
	}
	else
	{
		new_pwd = getcwd(NULL, 0);
		if (!new_pwd)
		{
			//perror("getcwd");
			ft_free_array(array);
			return ;
		}
		new_path = ft_strjoin("PWD=", new_pwd);
		old_pwd = ft_get_pwd(env);
		old_path = ft_strjoin("OLDPWD=", old_pwd + 4);
		ft_find_replace(env, "PWD=", new_path);
		ft_find_replace(env, "OLDPWD=", old_path);
		free(old_pwd);
		free(new_pwd);
		free(new_path);
	}
	ft_free_array(array);
}
