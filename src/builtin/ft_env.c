/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 10:24:30 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/09/22 14:22:02 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

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
