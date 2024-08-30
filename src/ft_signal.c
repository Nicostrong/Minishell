/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 13:12:26 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/08/28 15:23:24 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

/*
 * <cat>minishell</cat>
 *
 * <summary>
 * 	void	handle_signal(int sign)
 * </summary>
 *
 * <description>
 * 	handle_signal is the function to execute when the program catch a signal.
 * </description>
 *
 * <param type="int" name="sign">value of signal</param>
 *
 * <return>
 * 	void.
 * </return>
 *
 */

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
