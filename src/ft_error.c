/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 11:00:19 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/08/30 14:00:29 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

/*
 * <cat>minishell</cat>
 *
 * <summary>
 * 	void	ft_put_error_arg(char *cmd, char *arg, char *msg)
 * </summary>
 *
 * <description>
 * 	ft_put_erro_arg print an message error for a bad argument of cmd on STDERR.
 * </description>
 *
 * <param type="char *" name="cmd">command name</param>
 * <param type="char *" name="arg">argument name</param>
 * <param type="char *" name="msg">error message</param>
 *
 * <return>
 * 	void.
 * </return>
 *
 */

void	ft_put_error_arg(char *cmd, char *arg, char *msg)
{
	ft_putstr_fd(TERM_NAME": ", 2);
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd(": `", 2);
	ft_putstr_fd(arg, 2);
	ft_putstr_fd("': ", 2);
	ft_putendl_fd(msg, 2);
}

/*
 * <cat>minishell</cat>
 *
 * <summary>
 * 	void	ft_put_error_arg_exit(char *cmd, char *arg, char *msg, int e_code)
 * </summary>
 *
 * <description>
 * 	ft_put_erro_arg_exit print an message error for a bad argument of cmd on 
 * 	STDERR and exit with a code error.
 * </description>
 *
 * <param type="char *" name="cmd">command name</param>
 * <param type="char *" name="arg">argument name</param>
 * <param type="char *" name="msg">error message</param>
 * <param type="int" name="e_code">code error</param>
 *
 * <return>
 * 	void.
 * </return>
 *
 */

void	ft_put_error_arg_exit(char *cmd, char *arg, char *msg, int e_code)
{
	ft_putstr_fd(TERM_NAME": ", 2);
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd(": `", 2);
	ft_putstr_fd(arg, 2);
	ft_putstr_fd("': ", 2);
	ft_putendl_fd(msg, 2);
	exit(e_code);
}

/*
 * <cat>minishell</cat>
 *
 * <summary>
 * 	void	ft_put_error_cmd(char *cmd, char *msg)
 * </summary>
 *
 * <description>
 * 	ft_put_erro_cmd print an message error for a bad command, 1111 on STDERR.
 * </description>
 *
 * <param type="char *" name="cmd">command name</param>
 * <param type="char *" name="msg">error message</param>
 *
 * <return>
 * 	void.
 * </return>
 *
 */

void	ft_put_error_cmd(char *cmd, char *msg)
{
	ft_putstr_fd(TERM_NAME": ", 2);
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd(": ", 2);
	ft_putendl_fd(msg, 2);
}

/*
 * <cat>minishell</cat>
 *
 * <summary>
 * 	void	ft_put_error_cmd_exit(char *cmd, char *msg, int e_code)
 * </summary>
 *
 * <description>
 * 	ft_put_erro_cmd_exit print an message error for a bad command cmd STDERR and
 * 	exit with a code error.
 * </description>
 *
 * <param type="char *" name="cmd">command name</param>
 * <param type="char *" name="msg">error message</param>
 * <param type="int" name="e_code">code error</param>
 *
 * <return>
 * 	void.
 * </return>
 *
 */

void	ft_put_error_cmd_exit(char *cmd, char *msg, int e_code)
{
	ft_putstr_fd(TERM_NAME": ", 2);
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd(": ", 2);
	ft_putendl_fd(msg, 2);
	exit(e_code);
}