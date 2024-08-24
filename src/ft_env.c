/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 10:24:30 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/08/24 11:53:29 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

extern char	**environ;

static t_env	*ft_add_node(t_env *a_env, char *value)
{
	t_env	*node;
	t_env	*current;

	current = a_env;
	node = (t_env *)ft_calloc(1, sizeof(t_env));
	if (!node)
		return (NULL);
	node->value = ft_strdup(value);
	if (!node->value)
	{
		free(node);
		return (NULL);
	}
	node->next = NULL;
	if (!a_env)
		return (node);
	while (current->next)
		current = current->next;
	current->next = node;
	return (a_env);
}

void	ft_init_env(t_env **env, char **envp)
{
	int		index;
	int		alloc;

	alloc = 0;
	if (!envp)
	{
		envp = ft_strarraycpy(environ);
		alloc = 1;
	}
	index = -1;
	*env = NULL;
	while (envp[++index])
		*env = ft_add_node(*env, envp[index]);
	if (alloc)
		ft_free_array(envp);
}

void	ft_env(t_env *env)
{
	t_env	*current;

	current = env;
	while (current->next)
	{
		printf("%s\n", current->value);
		current = current->next;
	}
}