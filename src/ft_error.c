/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 11:00:19 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/08/29 11:19:53 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_print_error(char *cmd)
{
	char	*join1;
	char	*print;

	join1 = ft_strjoin(TERM_NAME": ", cmd);
	print = ft_strjoin(join1, ": command not found");
	ft_putendl_fd(print, 2);
	free(join1);
	free(print);
}