/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 10:22:28 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/08/23 10:25:26 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_cd(t_data *data)
{
	char	**array;

	array = ft_split(data->cmd, ' ');
	if (chdir(array[1]))
	{
		printf("bash: %s: %s: No such file or directory\n", array[0], array[1]);
		data->code_child = 1;
		return ;
	}
	
}
