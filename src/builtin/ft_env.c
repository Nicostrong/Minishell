/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 10:24:30 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/08/29 10:44:00 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/*
 * <cat>minishell</cat>
 *
 * <summary>
 * 	t_env	*ft_add_node(t_env *env, char *key, char *value)
 * </summary>
 *
 * <description>
 * 	ft_add_node add a new node on the linked list of environnement variables.
 * </description>
 *
 * <param type="t_env *" name="env">linked list env</param>
 *
 * <return>
 * 	NULL if problem or a pointer to the head of list.
 * </return>
 *
 */

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

/*
 * <cat>minishell</cat>
 *
 * <summary>
 * 	void	ft_init_env(t_env **env, char **envp)
 * </summary>
 *
 * <description>
 * 	ft_init_env initialise the linked list env with all value of environnement 
 * 	variable.
 * </description>
 *
 * <param type="t_env *" name="env">linked list env</param>
 * <param type="char **" name="envp">array of env variables</param>
 *
 * <return>
 * 	void.
 * </return>
 *
 */

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

/*
 * <cat>minishell</cat>
 *
 * <summary>
 * 	int	ft_env(t_data *data, t_env **env)
 * </summary>
 *
 * <description>
 * 	ft_env print all environnement variables on the linked list.
 * 	variable.
 * </description>
 *
 * <param type="t_data *" name="data">data struct</param>
 * <param type="t_env *" name="env">linked list env</param>
 *
 * <return>
 * 	0 if success or
 * 	1 if error.
 * </return>
 *
 */

int	ft_env(t_data *data, t_env **env)
{
	char	*value;
	char	**array;
	t_env	*current;

	value = ft_get_env_value(*env, "PATH");
	if (!env || !value)
	{
		printf(TERM_NAME": env: No such file or directory\n");
		return (127);
	}
	array = ft_split(data->cmd, ' ');
	if (array[1])
	{
		printf("%s: '%s' No such file or directory\n", array[0], array[1]);
		ft_free_array(array);
		return (127);
	}
	current = *env;
	while (current)
	{
		if (current->value)
			printf("%s=%s\n", current->key, current->value);
		current = current->next;
	}
	return (ft_free_array(array), 0);
}
