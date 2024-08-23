/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 09:55:36 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/08/21 13:25:44 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static int	ft_get_opt(char *line)
{
	int		index;

	index = 0;
	while (line[++index] == 'n')
		;
	if (line[index] == 0)
		return (1);
	return (0);
}

void	ft_echo(t_data *data)
{
	char	**array;
	int		opt;
	int		index;

	opt = 0;
	add_history(data->cmd);
	array = ft_split(data->cmd, ' ');
	if (!array[1])
	{
		data->code_child = 0;
		ft_putendl_fd("", 1);
		return ;
	}
	index = 1;
	if (array[index][0] == '-')
		opt = ft_get_opt(array[index]);
	if (opt)
	{
		while (array[++index])
		{
			ft_putstr_fd(array[index], 1);
			if (array[index + 1])
				ft_putchar_fd(' ', 1);
		}
		data->code_child = 0;
	}
	else
	{
		while (array[index])
		{
			ft_putstr_fd(array[index], 1);
			ft_putchar_fd(' ', 1);
			index++;
		}
		ft_putchar_fd('\n', 1);
		data->code_child = 0;
	}
	ft_free_array(array);
	return ;
}