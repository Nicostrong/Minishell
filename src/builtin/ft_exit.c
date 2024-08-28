/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 10:24:40 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/08/28 10:15:43 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	ft_free_data(t_data *data)
{
	if (!data)
		return ;
	if (data->cmd)
		free(data->cmd);
}

int	ft_exit(t_data *data, t_env **env)
{
	rl_clear_history();
	ft_free_data(data);
	ft_free_env(*env);
	exit(EXIT_SUCCESS);
}
