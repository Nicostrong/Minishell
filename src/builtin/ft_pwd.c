/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 10:23:05 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/08/27 09:31:54 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

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
