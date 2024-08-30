/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 08:26:04 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/08/29 10:36:17 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/*
 * <cat>minishell</cat>
 *
 * <summary>
 * 	void	ft_set_env_value(t_env **env, char *key, char *value)
 * </summary>
 *
 * <description>
 * 	ft_set_env_value modify the value of the key in linfed list env.
 * </description>
 *
 * <param type="t_env **" name="env">linked list env</param>
 * <param type="char *" name="key">key to modifie</param>
 * <param type="char *" name="value">new value for the key</param>
 *
 * <return>
 * 	void.
 * </return>
 *
 */

void	ft_set_env_value(t_env **env, char *key, char *value)
{
	t_env	*current;

	if (!env || !key)
		return ;
	current = *env;
	while (current)
	{
		if (ft_strequal(current->key, key))
		{
			if (current->value)
				free(current->value);
			current->value = ft_strdup(value);
			return ;
		}
		current = current->next;
	}
}

/*
 * <cat>minishell</cat>
 *
 * <summary>
 * 	char	*ft_get_env_value(t_env *env, const char *key)
 * </summary>
 *
 * <description>
 * 	ft_get_env_value get the value of the key in linfed list env.
 * </description>
 *
 * <param type="t_env *" name="env">linked list env</param>
 * <param type="char *" name="key">key to modifie</param>
 *
 * <return>
 * 	the value of the key or NULL if error or not fund.
 * </return>
 *
 */

char	*ft_get_env_value(t_env *env, char *key)
{
	t_env	*current;

	if (!env || !key)
		return (NULL);
	current = env;
	while (current)
	{
		if (ft_strequal(current->key, key))
			return (current->value);
		current = current->next;
	}
	return (NULL);
}

/*
 * <cat>minishell</cat>
 *
 * <summary>
 * 	void	ft_update_shlvl(t_env **env)
 * </summary>
 *
 * <description>
 * 	ft_update_shlvl increase the value of SHLVL variable on the linked list env.
 * </description>
 *
 * <param type="t_env **" name="env">linked list env</param>
 *
 * <return>
 * 	void.
 * </return>
 *
 */

void	ft_update_shlvl(t_env **env)
{
	char	*shlvl_value;
	char	*new_shlvl;
	int		shlvl;

	shlvl_value = ft_get_env_value(*env, "SHLVL");
	if (shlvl_value)
	{
		shlvl = ft_atoi(shlvl_value) + 1;
		new_shlvl = ft_itoa(shlvl);
		if (!new_shlvl)
			return ;
		ft_set_env_value(env, "SHLVL", new_shlvl);
		free(new_shlvl);
	}
}

/*
 * <cat>minishell</cat>
 *
 * <summary>
 * 	void	ft_free_env(t_env *env)
 * </summary>
 *
 * <description>
 * 	ft_free_env free all pointer and node of the linked list env.
 * </description>
 *
 * <param type="t_env *" name="env">linked list env</param>
 *
 * <return>
 * 	void.
 * </return>
 *
 */

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
