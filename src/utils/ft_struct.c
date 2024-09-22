/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 14:13:44 by nfordoxc          #+#    #+#             */
/*   Updated: 22/09/2024 15:38:48 by Nicostrong       ###   ########.lu       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/*
 * <cat>bool</cat>
 *
 * <summary>
 *	t_pipex	*ft_init_pipex(t_shell **shell)
 * </summary>
 *
 * <description>
 *	ft_init_pipex initialize the structure pipex with the default values.
 * </description>
 *
 * <param type="t_shell **" name="shell">shell structure</param>
 *
 * <return>
 *	a pointer to a new pipex structure.
 * </return>
 *
 */

static t_pipex	*ft_init_pipex(t_shell **shell)
{
	t_pipex	*pipex;

	pipex = (t_pipex *)ft_calloc(1, sizeof(t_pipex));
	if (!pipex)
	{
		free(*shell);
		exit (EXIT_FAILURE);
	}
	pipex->fd_in = -1;
	pipex->fd_out = -1;
	pipex->here_doc = 0;
	pipex->limiter = NULL;
	pipex->file_in = NULL;
	pipex->file_out = NULL;
	pipex->path_cmd = NULL;
	pipex->a_path = ft_get_path(environ);
	pipex->a_cmd_opt = NULL;
	pipex->a_env = ft_create_env_array((*shell)->l_env);
	return (pipex);
}

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
 * 	void	ft_update_shlvl(t_env **env)
 * </summary>
 *
 * <description>
 * 	ft_update_shlvl increase the value of SHLVL variable on the linked list env.
 * </description>
 *
 * <param type="t_env **" name="env">linked list env</param>
 *
 * <return>
 * 	void.
 * </return>
 *
 */

static void	ft_update_shlvl(t_env **env)
{
	char	*shlvl_value;
	char	*new_shlvl;
	int		shlvl;

	shlvl_value = ft_get_env_value(*env, "SHLVL");
	if (shlvl_value)
	{
		shlvl = ft_atoi(shlvl_value) + 1;
		new_shlvl = ft_itoa(shlvl);
		if (!new_shlvl)
			return ;
		ft_set_env_value(env, "SHLVL", new_shlvl);
		free(new_shlvl);
	}
}

/*
 * <cat>minishell</cat>
 *
 * <summary>
 * 	t_env	*ft_init_env(void)
 * </summary>
 *
 * <description>
 * 	ft_init_env initialise the linked list env with all value of environnement 
 * 	variable.
 * </description>
 *
 * <return>
 * 	void.
 * </return>
 *
 */

static t_env	*ft_init_env(void)
{
	char	**key_value;
	int		index;
	t_env	*env;

	env = NULL;
	index = -1;
	while (environ[++index])
	{
		key_value = ft_split(environ[index], '=');
		env = ft_add_node(env, key_value[0], key_value[1]);
		ft_free_array(key_value);
	}
	ft_update_shlvl(&env);
	return (env);
}

/*
 * <cat>bool</cat>
 *
 * <summary>
 *	t_pipex	*ft_init_shell(void)
 * </summary>
 *
 * <description>
 *	ft_init_shell initialize the structure shell. it init all struct for the 
 *	shell.
 * </description>
 *
 * <param type="void" name="void">void</param>
 *
 * <return>
 *	a pointer to a new shell structure
 * </return>
 *
 */

t_shell	*ft_init_shell(void)
{
	t_shell	*shell;

	shell = (t_shell *)ft_calloc(1, sizeof(t_shell));
	if (!shell)
		exit (EXIT_FAILURE);
	shell->l_env = ft_init_env();
	shell->l_token = NULL;
	shell->tree = NULL;
	shell->pipex = ft_init_pipex(&shell);
	shell->code_exit = 0;
	return (shell);
}
