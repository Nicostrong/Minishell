/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 08:26:04 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/09/22 14:21:19 by nfordoxc         ###   Luxembourg.lu     */
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
 * 	int	ft_is_key(t_env *env, const char *key)
 * </summary>
 *
 * <description>
 * 	ft_is_key is bool function return 1 if key is on env or 0 if not.
 * </description>
 *
 * <param type="t_env *" name="env">linked list env</param>
 * <param type="char *" name="key">key to fund</param>
 *
 * <return>
 * 	1 if key exist or 0 if not exist.
 * </return>
 *
 */

int	ft_is_key(t_env *env, char *key)
{
	t_env	*current;

	if (!env || !key)
		return (0);
	if (key[0] == '$')
		key++;
	current = env;
	while (current)
	{
		if (ft_strequal(current->key, key))
			return (1);
		current = current->next;
	}
	return (0);
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
	if (key[0] == '$')
		key++;
	current = env;
	while (current)
	{
		if (ft_strequal(current->key, key))
			return (current->value);
		current = current->next;
	}
	return (NULL);
}
