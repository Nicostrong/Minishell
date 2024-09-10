/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 15:01:57 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/09/02 16:14:53 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
/*
 *	caracteres de coupure de commande
 *	( et )	=>	for logical operation with && or ||
 *	"		=>	double quote
 *	'		=>	simple quote
 *	&&		=>	AND logical
 *	|		=>	pipe
 *	||		=>	OR logical
 *	<		=>	file in
 *	<<		=>	heredoc
 *	>		=>	file out
 *	>>		=>	file out append
 *	$		=>	env variable
 *	espace
 *
 * 	commencer par un split avec |
 * 	puis avec && utilisation de ( et )
 * 	puis avec ||
 * 	puis avec <
 * 	puis avec <<
 * 	puis avec >
 * 	puis avec >>
 */