/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 10:24:10 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/08/28 12:14:23 by nfordoxc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	ft_unset_key(t_env **env, char *key)
{
	t_env	*current;
	t_env	*before;

	if (!env || !*env || !key)
		return ;
	current = *env;
	before = NULL;
	while (current && !ft_strequal(current->key, key))
	{
		before = current;
		current = current->next;
	}
	if (current)
	{
		if (before)
			before->next = current->next;
		else
			*env = current->next;
		free(current->key);
		free(current->value);
		free(current);
	}
}

int	ft_unset(t_data *data, t_env **env)
{
	int		index;
	char	**array;

	array = ft_split(data->cmd, ' ');
	if (!array || !array[1])
	{
		ft_free_array(array);
		return (1);
	}
	index = 0;
	while (array[++index])
		ft_unset_key(env, array[index]);
	ft_free_array(array);
	return (0);
}
