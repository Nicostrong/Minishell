/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 10:23:25 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/08/30 08:53:42 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/*
 * <cat>minishell</cat>
 *
 * <summary>
 * 	int	ft_get_nb_key(t_env *env)
 * </summary>
 *
 * <description>
 * 	ft_get_nb_key count the number ok key in the linked list.
 * </description>
 *
 * <param type="t_env *" name="env">linked list env</param>
 *
 * <return>
 * 	number of key in linked list.
 * </return>
 *
 */

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

/*
 * <cat>minishell</cat>
 *
 * <summary>
 * 	void	ft_sort_a_str(char **a_key, int count)
 * </summary>
 *
 * <description>
 * 	ft_sort_a_str sort an array of string with buble sort.
 * </description>
 *
 * <param type="char **" name="a_key">array ok key</param>
 * <param type="int" name="count">number of key in array</param>
 *
 * <return>
 * 	void.
 * </return>
 *
 */

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

/*
 * <cat>minishell</cat>
 *
 * <summary>
 * 	char	**ft_get_all_key(t_env *env, int count)
 * </summary>
 *
 * <description>
 * 	ft_get_all_key creat an array with all key of the linked list env.
 * </description>
 *
 * <param type="t_env **" name="env">linked list env</param>
 * <param type="int" name="count">number ok key on linked list env</param>
 *
 * <return>
 *	an array of key.
 * </return>
 *
 */

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

/*
 * <cat>minishell</cat>
 *
 * <summary>
 * 	int	ft_print_export_env(t_env *env)
 * </summary>
 *
 * <description>
 * 	ft_print_export_env print all env variable order by alphabetic in special
 * 	format.
 * </description>
 *
 * <param type="t_env **" name="env">linked list env</param>
 *
 * <return>
 * 	0 if success or 1 if error.
 * </return>
 *
 */

static int	ft_print_export_env(t_env *env)
{
	char	*value;
	char	**a_key;
	int		count;
	int		index;

	if (!env)
		return (1);
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
			printf("export %s=\"%s\"\n", a_key[index], value);
		else
			printf("export %s\n", a_key[index]);
	}
	ft_free_array(a_key);
	return (0);
}

/*
 * <cat>minishell</cat>
 *
 * <summary>
 * 	int	ft_export(t_data *data, t_env *env)
 * </summary>
 *
 * <description>
 * 	ft_export is like a builtin function en bash. it's execute some function 
 * 	compared to an array of arguments.
 * </description>
 *
 * <param type="t_data *" name="data">data struct</param>
 * <param type="t_env *" name="env">linked list env</param>
 *
 * <return>
 * 	0 if success or 1 if error.
 * </return>
 *
 */

int	ft_export(t_data *data, t_env *env)
{
	char	*key;
	char	**array;
	int		index;

	array = ft_split(data->cmd, ' ');
	if (!array)
		return (1);
	if (!array[1])
		return (ft_free_array(array), ft_print_export_env(env));
	index = 0;
	while (array[++index])
	{
		key = ft_get_key(array[index]);
		if (ft_check_key(env, key))
			ft_update_key(&env, key, array[index]);
		else
			ft_export_value(&env, array[index]);
		free(key);
	}
	ft_free_array(array);
	return (0);
}
