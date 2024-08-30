/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 10:24:10 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/08/28 15:18:57 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/*
 * <cat>minishell</cat>
 *
 * <summary>
 * 	void	ft_unset_key(t_env **env, char *key)
 * </summary>
 *
 * <description>
 * 	ft_unset_key remove properly the key on the linked list env.
 * </description>
 *
 * <param type="t_env **" name="env">linked list env</param>
 * <param type="tchar *" name="key">key of node to remove</param>
 *
 * <return>
 * 	void.
 * </return>
 *
 */

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

/*
 * <cat>minishell</cat>
 *
 * <summary>
 * 	int	ft_unset(t_data *data, t_env **env)
 * </summary>
 *
 * <description>
 * 	ft_unset is like a builtin function in bash.it can take many arguments to 
 * 	remove of the linked list.
 * </description>
 *
 * <param type="t_data *" name="data">data struct</param>
 * <param type="t_env **" name="env">linked list env</param>
 *
 * <return>
 * 	0 if success or 1 if error.
 * </return>
 *
 */

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
