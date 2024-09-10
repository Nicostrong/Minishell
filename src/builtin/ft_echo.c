/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 09:55:36 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/09/05 17:32:41 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

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

int	ft_echo(t_data *data, t_env *env)
{
	//char 	var;
	char	**array;
	int		opt;
	int		index;

	(void)env;
	opt = 0;
	array = ft_split(data->var_parse, ' ');
	if (!array[1])
	{
		ft_putendl_fd("", 1);
		return (0);
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
	}
	ft_free_array(array);
	//ft_parse_echo(data, env);
	//ft_putendl_fd(data->echo_parse, 1);
	return (0);
}