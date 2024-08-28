/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 13:12:26 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/08/26 14:26:04 by nfordoxc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	handle_signal(int sign)
{
	if (sign == SIGINT)
	{
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
	else if (sign == SIGQUIT)
		return ;
	else if (sign == SIGTERM)
	{
		printf("exit\n");
		exit(EXIT_SUCCESS);
	}
}
