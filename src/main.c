/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 15:41:47 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/08/29 11:14:42 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

/*
 * <cat>minishell</cat>
 *
 * <summary>
 *	minishell
 * </summary>
 *
 * <description>
 *	minishell is like a bash shell. It 's running with the same isue of bash
 *	and contant some builtin function.
 *	Builtin function :
 *		- env without options/arguments;
 *		- pwd without options;
 *		- cd with relative or absolut path;
 *		- unset without options;
 *		- export without options;
 *		- echo with -n option;
 *		- exit without options;
 *	Minishell is available to interpret :
 *		- multiple pipi;
 *		- ", ', (, ), <, <<, >, >>, &&, ||;
 *		- ctrl + c => displays a new prompt on a new line;
 *		- ctrl + D => exits the shell;
 *		- ctrl + \ => does nothing;
 *		- $ENV_VARIABLE;
 *	It've got a history commands.
 * </description>
 *
 * <return>
 *	0 in success or 1 in error.
 * </return>
 *
 */

int main(int argc, char **argv, char **envp)
{
	char		*line;
	t_data		data;
	t_env		*env;
	//t_cmd		*cmd;

	(void)argc;
	(void)argv;
	signal(SIGINT, handle_signal);
    signal(SIGQUIT, SIG_IGN);
	ft_init_env(&env, envp);
	data.code_child = -1;
	while (1)
	{
		line = readline(TERM_NAME"$ ");
		if (ft_strlen(line))
			add_history(line);
		//cmd = ft_parse(line);
		data.cmd = ft_strdup(line);
		free(line);
		ft_builtin(&data, &env);
		//ft_parse_line(&data);
		/* faire un fork et executer cmd dans le fils */
		/* attendre le process fils et enregistrer le code retour */
		free(data.cmd);
	}
}
