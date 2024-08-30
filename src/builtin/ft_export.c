/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 10:23:25 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/08/28 13:23:53 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	ft_get_nb_key(t_env *env)
{
	int	count;

	count = 0;
	if (!env)
		return (count);
	while (env)
	{
		count++;
		env = env->next;
	}
	return (count);
}

static void	ft_sort_a_str(char **a_key, int count)
{
	char	*tmp;
	int		i;
	int		j;

	i = -1;
	while (++i < count)
	{
		j = -1;
		while (++j < count - 1)
		{
			if (ft_strcmp(a_key[j], a_key[j + 1]) > 0)
			{
				tmp = a_key[j];
				a_key[j] = a_key[j + 1];
				a_key[j + 1] = tmp;
			}
		}
	}
}

static char	**ft_get_all_key(t_env *env, int count)
{
	char	**a_key;
	int		index;
	t_env	*current;

	current = env;
	a_key = (char **)ft_calloc(count + 1, sizeof(char *));
	if (!a_key)
		return (NULL);
	index = -1;
	while (current)
	{
		if (index < count)
			a_key[++index] = ft_strdup(current->key);
		current = current->next;
	}
	a_key[++index] = NULL;
	return (a_key);
}

static int	ft_print_export_env(t_env *env)
{
	char	*value;
	char	**a_key;
	int		count;
	int		index;

	value = NULL;
	a_key = NULL;
	count = 0;
	index = -1;
	count = ft_get_nb_key(env);
	a_key = ft_get_all_key(env, count);
	ft_sort_a_str(a_key, count);
	while (a_key[++index])
	{
		value = ft_get_env_value(env, a_key[index]);
		if (value)
			printf("export %s=%s\n", a_key[index], value);
		else
			printf("export %s\n", a_key[index]);
	}
	ft_free_array(a_key);
	return (0);
}

int	ft_export(t_data *data, t_env *env)
{
	char	**array;
	char	**key_val;
	int		index;

	array = ft_split(data->cmd, ' ');
	if (!array)
		return (1);
	if (ft_strequal(data->cmd, "export"))
		return (ft_free_array(array), ft_print_export_env(env));
	index = 0;
	while (array[++index])
	{
		key_val = ft_split(array[index], '=');
		if (key_val[1])
			ft_add_node(env, key_val[0], key_val[1]);
		else
			ft_add_node(env, key_val[0], NULL);
		ft_free_array(key_val);
	}
	ft_free_array(array);
	return (0);
}
