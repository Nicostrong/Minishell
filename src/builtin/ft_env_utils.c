/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 08:26:04 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/08/28 12:15:20 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_set_env_value(t_env *env, char *key, char *value)
{
	t_env	*current;

	current = env;
	while (current)
	{
		if (ft_strequal(current->key, key))
		{
			free(current->value);
			current->value = ft_strdup(value);
			return ;
		}
		current = current->next;
	}
}

char	*ft_get_env_value(t_env *env, const char *name)
{
	t_env	*current;

	current = env;
	while (current)
	{
		if (ft_strequal(current->key, name))
			return (current->value);
		current = current->next;
	}
	return (NULL);
}
// TROP LONG 
void	ft_update_shlvl(t_env **env)
{
	char	*shlvl_value;
	char	*new_shlvl;
	int		shlvl;
	t_env	*current;

	shlvl_value = ft_get_env_value(*env, "SHLVL");
	if (shlvl_value)
	{
		shlvl = ft_atoi(shlvl_value) + 1;
		new_shlvl = ft_itoa(shlvl);
		if (!new_shlvl)
			return ;
		current = *env;
		while (current)
		{
			if (ft_strequal(current->key, "SHLVL"))
			{
				free(current->value);
				current->value = new_shlvl;
				return ;
			}
			current = current->next;
		}
		free(new_shlvl);
	}
	return ;
}

void	ft_free_env(t_env *env)
{
	t_env	*current;
	t_env	*next;

	next = env;
	while (next)
	{
		current = next;
		next = current->next;
		free(current->key);
		free(current->value);
		free(current);
	}
	env = NULL;
}
