/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 10:24:30 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/08/28 13:51:55 by nfordoxc         ###   Luxembourg.lu     */
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
	if (value)
	{
		node->value = ft_strdup(value);
		if (!node->value)
			return (free(node->key), free(node), NULL);
	}
	else
		node->value = NULL;
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

int	ft_env(t_data *data, t_env **env)
{
	char	*value;
	char	**array;
	int		index;
	t_env	*current;

	value = ft_get_env_value(*env, "PATH");
	if (!env || !value)
	{
		printf(TERM_NAME": env: No such file or directory\n");
		return (127);
	}
	array = ft_split(data->cmd, ' ');
	current = *env;
	while (current)
	{
		if (current->value)
			printf("%s=%s\n", current->key, current->value);
		current = current->next;
	}
	index = 0;
	while (array[++index])
		printf("%s: '%s' No such file or directory\n", array[0], array[index]);
	ft_free_array(array);
	return (0);
}
