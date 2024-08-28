/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 10:24:30 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/08/28 10:18:00 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_env	*ft_add_node(t_env *env, char *key, char *value)
{
	t_env	*node;
	t_env	*current;

	node = (t_env *)ft_calloc(1, sizeof(t_env));
	if (!node)
		return (NULL);
	node->key = ft_strdup(key);
	if (!node->key)
		return (free(node), NULL);
	node->value = ft_strdup(value);
	if (!node->value)
		return (free(node->key), free(node), NULL);
	node->next = NULL;
	if (!env)
		return (node);
	current = env;
	while (current->next)
		current = current->next;
	current->next = node;
	return (env);
}

void	ft_init_env(t_env **env, char **envp)
{
	char	**key_value;
	int		index;

	index = -1;
	*env = NULL;
	while (envp[++index])
	{
		key_value = ft_split(envp[index], '=');
		*env = ft_add_node(*env, key_value[0], key_value[1]);
		ft_free_array(key_value);
	}
	ft_update_shlvl(env);
}

int	ft_env(t_env **env)
{
	char	*value;
	t_env	*current;

	value = ft_get_env_value(*env, "PATH");
	if (!env || !value)
	{
		printf(TERM_NAME": env: No such file or directory\n");
		return (127);
	}
	current = *env;
	while (current)
	{
		printf("%s=%s\n", current->key, current->value);
		current = current->next;
	}
	return (0);
}
