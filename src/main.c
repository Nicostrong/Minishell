/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 15:41:47 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/09/10 09:25:02 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

/*static void	ft_init_data(t_data *data)
{
	data->cmd = NULL;
	data->echo_parse = NULL;
	data->export_parse = NULL;
	data->var_parse = NULL;
	data->code_child = -1;
}*/

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
			//ft_parse_cmd(&data, env);
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
*/

int	main(void)
{
	char	*command;
    t_token	*tokens;
	t_tree	*tree;

	command = "(echo $USER && echo $HOME) | /bin/cat < input | /usr/bin/grep \"toto\" | /bin/wc -l >> out";
	tokens = ft_parse_cmd(command);
	tree = ft_parse_token_to_tree(&tokens);
    
    // Affichage des tokens
	printf("command = %s\n", command);
	ft_print_tokens(tokens);

	// Affichage de l arbre
	printf("Arbre de la commande :\n");
    ft_print_tree(tree);
	//(void)tree;
    return 0;
}
