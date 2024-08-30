/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 10:23:05 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/08/28 15:15:14 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/*
 * <cat>minishell</cat>
 *
 * <summary>
 * 	int	ft_pwd(t_env *env)
 * </summary>
 *
 * <description>
 * 	ft_pwd print just the env variable $PWD or if $PWD not set, call the getcwd
 * 	function to know the currect directory.
 * </description>
 *
 * <param type="t_env *" name="env">linked list env</param>
 *
 * <return>
 * 	0 if success or 1 if error.
 * </return>
 *
 */

int	ft_pwd(t_env *env)
{
	char	*pwd;
	char	*cwd;

	pwd = ft_get_env_value(env, "PWD=");
	if (pwd && !access(pwd, F_OK))
		printf("%s\n", pwd);
	else
	{
		cwd = getcwd(NULL, 0);
		if (cwd)
		{
			printf("%s\n", cwd);
			free(cwd);
		}
		else
		{
			free(pwd);
			perror("pwd");
			return (1);
		}
	}
	free(pwd);
	return (0);
}
