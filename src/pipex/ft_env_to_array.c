/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_to_array.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 15:19:24 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/09/18 09:08:39 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/*
 *	count the number of var on list
 */

static int	ft_count_var(t_env *env)
{
	t_env	*current;
	int		count;

	count = 0;
	if (!env)
		return (count);
	current = env;
	while (current)
	{
		count++;
		current = current->next;
	}
	return (count);
}

static char	**ft_alloc_array(t_env *env)
{
	char	**a_env;
	int		len_array;

	len_array = ft_count_var(env);
	a_env = (char **)ft_calloc((len_array + 1), sizeof(char *));
	return (a_env);
}

/*
 *	create env array
 */

char	**ft_create_env_array(t_env *env)
{
	char	*key;
	char	*fusion;
	char	**a_env;
	int		index;

	if (!env)
		return (NULL);
	a_env = ft_alloc_array(env);
	if (!a_env)
		return (NULL);
	index = 0;
	while (env)
	{
		key = ft_strjoin(env->key, "=");
		fusion = ft_strjoin(key, env->value);
		a_env[index++] = fusion;
		free(key);
		env = env->next;
	}
	a_env[index] = NULL;
	return (a_env);
}