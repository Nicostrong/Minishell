/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 10:24:40 by nfordoxc          #+#    #+#             */
/*   Updated: 22/09/2024 15:37:47 by Nicostrong       ###   ########.lu       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/*
 * <cat>minishell</cat>
 *
 * <summary>
 * 	void	ft_free_data(t_data *data)
 * </summary>
 *
 * <description>
 * 	ft_free_data free all pointer on struct data.
 * 	variable.
 * </description>
 *
 * <param type="t_data *" name="data">data struct</param>
 *
 * <return>
 * 	void.
 * </return>
 *
 */

static void	ft_free_data(t_data *data)
{
	if (!data)
		return ;
	if (data->cmd)
		free(data->cmd);
	if (data->var_parse)
		free(data->var_parse);
	if (data->echo_parse)
		free(data->echo_parse);
}

/*
 * <cat>minishell</cat>
 *
 * <summary>
 * 	int	ft_exit(t_data *data, t_env **env)
 * </summary>
 *
 * <description>
 * 	ft_exit clear all history command and free all struct and linked list.
 * 	variable.
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

int	ft_exit(t_data *data, t_env **env)
{
	//rl_clear_history();
	clear_history();	// TO REMOVE FOR LINUX
	ft_free_data(data);
	ft_free_env(*env);
	exit(EXIT_SUCCESS);
}
