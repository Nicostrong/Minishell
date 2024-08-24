/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 15:41:47 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/08/23 15:10:04 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static void	ft_init_data(t_data *data, char *line, char **envp)
{
	data->cmd = ft_strdup(line);
	data->code_child = -1;
	data->env = ft_strarraycpy(envp);
	data->pwd[0] = 0;
}

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
	while (1)
	{
		line = readline(TERM_NAME);
		if (ft_strlen(line))
			add_history(line);
		//cmd = ft_parse(line);
		ft_init_data(&data, line, envp);
		free(line);
		ft_builtin(&data, env);
		//ft_parse_line(&data);
		/* faire un fork et executer cmd dans le fils */
		/* attendre le process fils et enregistrer le code retour */
		//free(data.cmd);
	}
}