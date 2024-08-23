/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 10:24:40 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/08/22 10:43:40 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static void	ft_free_data(t_data *data)
{
	if (!data)
		return ;
	if (data->cmd)
		free(data->cmd);
	if (data->pwd[0])
		free(data->pwd);
	if (data->env)
		ft_free_array(data->env);
}

int	ft_exit(t_data *data)
{
	rl_clear_history();
	ft_free_data(data);
	exit(EXIT_SUCCESS);
}