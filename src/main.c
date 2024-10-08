/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 15:41:47 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/09/23 09:40:25 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	g_status = 0;

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
 *	It've got a history commands.
 * </description>
 *
 * <return>
 *	0 in success or 1 in error.
 * </return>
 *
 */

/*
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
	ft_init_data(&data);
	while (1)
	{
		line = readline(TERM_NAME"$ ");
		if (ft_strlen(line))
		{
			add_history(line);
			ft_wilcard("*");
			//ft_parse(&data, env, line);
			ft_parse_cmd(&data, env);
			ft_builtin(&data, &env);
			//free(data.cmd);
			char **tokens;
			int	index;
			tokens = ft_parse_input(line);
			index = -1;
			while (tokens[++index])
				printf("Token %d = %s \n", index, tokens[index]);
		}
		free(line);
		free(data.cmd);
		free(data.var_parse);
	}
}

//command = "(echo $USER && echo $HOME) | /bin/cat < input | /usr/bin/grep \"toto\" | /bin/wc -l >> out";
//command = "/bin/cat < input | /usr/bin/grep \"toto\" | /bin/wc -l >> out";
//command = "<< EOF /bin/cat | wc -l > out";
//command = "(echo \"Hello $USER\" && /bin/cat < input.txt | /bin/grep -i \"pattern\" || echo 'No match found') | /bin/ls -la | /bin/wc -l >> count.log && /bin/tail -f output.log";
*/

int	main(void)
{
	char	*command;
	t_shell	*shell;

	shell = ft_init_shell();
	signal(SIGINT, handle_signal);
	signal(SIGQUIT, SIG_IGN);
	while (1)
	{
		command = readline(TERM_NAME);
		if (!command)
		{
			printf("exit¦n");
			rl_clear_history();	// for linux
			// clear_history();		// for Mac
			ft_free_all(shell);
			exit (EXIT_SUCCESS);
		}
		if (ft_strlen(command))
		{
			add_history(command);
			if (ft_check_syntax_input(command, shell))
			{
				shell->l_token = ft_parse_cmd(command, shell);
				shell->tree = ft_parse_token_to_tree(&shell->l_token);
				ft_print_all(shell);	//	DEBUG
				//ft_fill_pipex(shell);
				//ft_print_pipex(shell->pipex);
				if (ft_strequal(command, "exit"))
				{
					printf("exit\n");
					rl_clear_history();	// for linux
					// clear_history();		// for Mac
					ft_free_all(shell);
					free(command);
					exit (EXIT_SUCCESS);
				}
				ft_free_tokens(shell->l_token);
				ft_free_tree(shell->tree);
			}
		}
		free(command);
	}
}
