/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 14:26:46 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/09/22 18:42:56 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/*
 * <cat>bool</cat>
 *
 * <summary>
 *	int	ft_check_pipe(char *cmd)
 * </summary>
 *
 * <description>
 *	ft_check_pipe check on the string command if the syntaxe pipe is correct.
 *	correct is '|' or ’||’ and incorrect is '|||'.
 * </description>
 *
 * <param type="char *" name="cmd">sting to check</param>
 *
 * <return>
 *	0 in error case.
 *	1 if no error.
 * </return>
 *
 */

static int	ft_check_pipe(char *cmd)
{
	int	i;

	i = 0;
	while (cmd[i])
	{
		if (cmd[i] == '|' && cmd[i + 1] == '|' && cmd[i + 2] == '|')
		{
			ft_put_error_cmd("bash", "syntax error near \"|\"");
			return (0);
		}
		i++;
	}
	return (1);
}

/*
 * <cat>bool</cat>
 *
 * <summary>
 *	int	ft_check_and(char *cmd)
 * </summary>
 *
 * <description>
 *	ft_check_and check on the string command if the syntaxe and is correct.
 *	correct is '&&' and incorrect is '&&&'.
 * </description>
 *
 * <param type="char *" name="cmd">sting to check</param>
 *
 * <return>
 *	0 in error case.
 *	1 if no error.
 * </return>
 *
 */

static int	ft_check_and(char *cmd)
{
	int	i;

	i = 0;
	while (cmd[i])
	{
		if (cmd[i] == '&' && cmd[i + 1] == '&' && cmd[i + 2] == '&')
		{
			ft_put_error_cmd("bash", "syntax error near \"&\"");
			return (0);
		}
		i++;
	}
	return (1);
}

/*
 * <cat>bool</cat>
 *
 * <summary>
 *	int	ft_check_f_in(char *cmd)
 * </summary>
 *
 * <description>
 *	ft_check_f_in check on the string command if the syntaxe file in is correct.
 *	correct is '<' or '<<' or '<<<' and incorrect is '<<<<'.
 * </description>
 *
 * <param type="char *" name="cmd">sting to check</param>
 *
 * <return>
 *	0 in error case.
 *	1 if no error.
 * </return>
 *
 */

static int	ft_check_f_in(char *cmd)
{
	int	i;

	i = 0;
	while (cmd[i])
	{
		if (cmd[i] == '<' && cmd[i + 1] == '<' && cmd[i + 2] == '<'
			&& cmd[i + 3] == '<')
		{
			ft_put_error_cmd("bash", "syntax error near \"<\"");
			return (0);
		}
		i++;
	}
	return (1);
}

/*
 * <cat>bool</cat>
 *
 * <summary>
 *	int	ft_check_f_out(char *cmd)
 * </summary>
 *
 * <description>
 *	ft_check_f_out check on the string command if the syntaxe file out is OK.
 *	correct is '>' or '>>' and incorrect is '>>>'.
 * </description>
 *
 * <param type="char *" name="cmd">sting to check</param>
 *
 * <return>
 *	0 in error case.
 *	1 if no error.
 * </return>
 *
 */

static int	ft_check_f_out(char *cmd)
{
	int	i;

	i = 0;
	while (cmd[i])
	{
		if (cmd[i] == '>' && cmd[i + 1] == '>' && cmd[i + 2] == '>')
		{
			ft_put_error_cmd("bash", "syntax error near \">\"");
			return (0);
		}
		i++;
	}
	return (1);
}

/*
 * <cat>bool</cat>
 *
 * <summary>
 *	int	ft_check_syntax_input(char *cmd, t_shell *shell)
 * </summary>
 *
 * <description>
 *	ft_check_syntax_input check all syntax error cases.
 * </description>
 *
 * <param type="char *" name="cmd">sting to check</param>
 * <param type="t_shell *" name="shell">shell structure</param>
 *
 * <return>
 *	1 if the syntax is correct or
 *	0 in case of error syntax.
 * </return>
 *
 */

int	ft_check_syntax_input(char *cmd, t_shell *shell)
{
	if (!ft_check_pipe(cmd)
		|| !ft_check_and(cmd)
		|| !ft_check_f_in(cmd)
		|| !ft_check_f_out(cmd))
		shell->code_exit = 2;
	else
		return (1);
	return (0);
}
