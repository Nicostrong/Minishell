/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 11:07:30 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/08/22 14:44:19 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_cmd *ft_parse(char *input)
{
	t_cmd	*cmd;
	
	cmd = (t_cmd *)ft_calloc(1, sizeof(t_cmd));
	if (!cmd)
		return (NULL);

	// Parcourir les tokens et remplir la structure
	char *token = strtok(input, " ");
	while (token != NULL)
	{
		if (!ft_strncmp(token, ">", 2))
		{
			// Redirection de sortie
			token = strtok(NULL, " ");
			cmd->output_file = strdup(token);
			cmd->append_output = 0;
		}
		else if (!ft_strncmp(token, ">>", 3))
		{
			// Redirection de sortie en mode ajout
			token = strtok(NULL, " ");
			cmd->output_file = strdup(token);
			cmd->append_output = 1;
		}
		else if (!ft_strncmp(token, "<", 2))
		{
			// Redirection d'entrée
			token = strtok(NULL, " ");
			cmd->input_file = strdup(token);
		}
		else if (!ft_strncmp(token, "|", 2))
		{
			// Pipeline
			cmd->is_piped = 1;
			cmd->next = parse_command(strtok(NULL, ""));  // Parsing de la commande suivante dans le pipeline
			break;
		}
		else if (!ft_strncmp(token, "&&", 3))
		{
			// Opération logique AND
			cmd->is_and = 1;
			cmd->next = parse_command(strtok(NULL, ""));
			break;
		}
		else if (!ft_strncmp(token, "||", 3))
		{
			// Opération logique OR
			cmd->is_or = 1;
			cmd->next = parse_command(strtok(NULL, ""));
			break;
		}
		else if (!ft_strncmp(token, "(", 2))
		{
			// Sous-shell
			cmd->is_subshell = 1;
			// Gérer la sous-shell ici
		}
		else
		{
			// C'est un argument de la commande
			// Ajoutez l'argument à cmd->args
		}
		token = strtok(NULL, " ");
	}
	return (cmd);
}