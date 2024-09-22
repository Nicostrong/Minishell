/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_to_array.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 15:19:24 by nfordoxc          #+#    #+#             */
/*   Updated: 22/09/2024 15:41:39 by Nicostrong       ###   ########.lu       */
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

/*
 *	create env array
 */

char	**ft_create_env_array(t_env *env)
{
	char	*key;
	char	*fusion;
	char	**a_env;
	int		index;
	int		len_array;

	if (!env)
		return (NULL);
	len_array = ft_count_var(env);
	a_env = (char **)ft_calloc((len_array + 1), sizeof(char *));
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
