/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 12:07:18 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/08/30 15:48:56 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/*
 * <cat>minishell</cat>
 *
 * <summary>
 * 	char	*ft_get_value(char *key_value)
 * </summary>
 *
 * <description>
 * 	ft_get_value get the value of the string formated like key=value.
 * </description>
 *
 * <param type="char *" name="key_value">string with key and value</param>
 *
 * <return>
 *  a pointer to a sting with the value.
 * </return>
 *
 */

char	*ft_get_value(char *key_value)
{
	char	*value;
	int		index_sep;

	if (!key_value)
		return (NULL);
	index_sep = 0;
	index_sep = ft_charchr(key_value, '=');
	value = ft_substr(key_value, ++index_sep, ft_strlen(key_value));
	return (value);
}

int	ft_valid_key(char *key)
{
	if (ft_isalpha(key[0]) || key[0] == '_')
		return (1);
	ft_put_error_arg("export", key, "not a valid identifier");
	return (0);
}

/*
 * <cat>minishell</cat>
 *
 * <summary>
 * 	int	ft_get_key(char *key_value)
 * </summary>
 *
 * <description>
 * 	ft_get_key get the first part of the string formated like "key=value".
 * </description>
 *
 * <param type="char *" name="key_value">string with key and value</param>
 *
 * <return>
 * 	a new pointer to the key.
 * </return>
 *
 */

char	*ft_get_key(char *key_value)
{
	char	*key;
	char	**a_key_value;
	
	if (!key_value)
		return (NULL);
	a_key_value = ft_split(key_value, '=');
	key = ft_strdup(a_key_value[0]);
	ft_free_array(a_key_value);
	if (ft_valid_key(key))
		return (key);
	free(key);
	return (NULL);
}

/*
 * <cat>minishell</cat>
 *
 * <summary>
 * 	int	ft_check_key(t_env *env, char *key)
 * </summary>
 *
 * <description>
 * 	ft_check_key check if the key exist on the struct env.
 * </description>
 *
 * <param type="t_env *" name="env">linked list env</param>
 * <param type="char *" name="key">key to evaluate</param>
 *
 * <return>
 * 	1 if exist or 0 if not exist.
 * </return>
 *
 */

int	ft_check_key(t_env *env, char *key)
{
	while (env)
	{
		if (ft_strequal(env->key, key))
			return (1);
		env = env->next;
	}
	return (0);
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

void	ft_export_value(t_env **env, char *key_val)
{
	char	**a_key_val;
	char	*a_k_v[2];

	a_key_val = ft_split(key_val, '=');
	if (a_key_val[2])
	{
		a_k_v[0] = ft_substr(key_val, 0, ft_charchr(key_val, '='));
		if (a_key_val[1])
			a_k_v[1] = ft_substr(key_val, ft_charchr(key_val, '=') + 1, -1);
		ft_add_node(*env, a_k_v[0], a_k_v[1]);
		free(a_k_v[0]);
		free(a_k_v[1]);
		ft_free_array(a_key_val);
	}
	else
	{
		if (key_val[1])
			ft_add_node(*env, a_key_val[0], a_key_val[1]);
		else
			ft_add_node(*env, a_key_val[0], NULL);
		ft_free_array(a_key_val);
	}
}
/*
EXPORT

export seul => affiche la liste des variable avec value meme les variable vide
export var => cree une var vide
export var=value => si var existe => mise a jour de value
					si var new => creation de var avec value
export var=VAL1=val2=val3 => si var exist => mise a jour avec VAL1=val2=val3
							 si var new => creation de var avec VAL1=val2=val3
export var1=val1 var2=val2 varn=valn => pour chaque var => check if exist => MAJ || NEW

		50€ la photo biz
		*/