/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 13:08:20 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/09/10 09:35:23 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/*
*	get the part of string between two quote or double quote
*/

static char	*ft_get_quoted_token(char **cmds, char quote_type)
{
	char	*start;
	char	*end;

	start = *cmds;
	end = ft_strchr(start + 1, quote_type);
	if (!end)
	{
		ft_putendl_fd("Invalid Quotes", 2);
		return (NULL);
	}
	*end = 0;
	*cmds = end + 1;
	return (ft_strdup(start + 1));
}

char	**ft_parse_input(char *input)
{
	char	**tokens;
	char	*token;
	char	*start;
	int		token_count;
	size_t	length;

	tokens = (char **)ft_calloc(1024, sizeof(char *));
	if (!tokens)
		return (NULL);
	token_count = 0;
	while (*input)
	{
		while (*input && (*input == ' ' || *input == '\t'))
			input++;
		if (*input == 0)
			break ;
		if (*input == '\'' || *input == '"')
			token = ft_get_quoted_token(&input, *input);
		else if (!ft_strncmp(input, "&&", 2) || !ft_strncmp(input, "||", 2))
		{
			token = ft_strndup(input, 2);
			input += 2;
		}
		else if (*input == '|' || *input == '<' || *input == '>')
		{
			if (*input == '>' && *(input + 1) == '>')
				token = ft_strndup(input, 2);
			else if (*input == '<' && *(input + 1) == '<')
				token = ft_strndup(input, 2);
			else
				token = ft_strndup(input, 1);
			input += ft_strlen(token);
		}
		else
		{
			start = input;
			while (*input && !ft_strchr(" \t'\"|<>", *input))
				input++;
			length = input - start;
			token = (char *)ft_calloc(length + 1, sizeof(char));
			if (!token)
				return NULL;
			ft_strlcpy(token, start, length);
			//token[length] = '\0';
		}
		if (token)
			tokens[token_count++] = token;
	}
	tokens[token_count] = NULL;
	return (tokens);
}

/*
*	parse la commande d entree et remplace toutes les variables $VAR par leur valeur
*/

void	ft_parse_cmd(t_data *data, t_env *env)
{
	char	*var;
	char	**a_cmd;
	int		index;

	a_cmd = ft_split(data->cmd, ' ');
	index = -1;
	while (a_cmd[++index])
	{
		var = NULL;
		if (ft_is_key(env, a_cmd[index]))
			var = ft_get_env_value(env, a_cmd[index]);
		if (var)
		{
			free(a_cmd[index]);
			a_cmd[index] = ft_strdup(var);
		}
	}
	data->var_parse = ft_join_array(a_cmd, " ");
	ft_free_array(a_cmd);
}

/*
*	parse les argument apres export pour remplacer les $VAR par leur valeur
*/
/*void	ft_parse_export(t_data *data, t_env *env)
{
}*/

/*
*	parse les arguments pour la fonction echo
*/

void	ft_parse_echo(t_data *data, t_env *env)
{
	char	*buffer = NULL;
	char	*var = NULL;
	char	*value;
	int		i;
	int		j;
	int		k;
	int		in_double_quotes;
	int		in_single_quotes;

	i = 0;
	j = 0;
	in_double_quotes = 0;
	in_single_quotes = 0;
	while (data->cmd[i] != '\0')
	{
		if (data->cmd[i] == '"' && !in_single_quotes)
		{
			in_double_quotes = !in_double_quotes;
			i++;
		}
		else if (data->cmd[i] == '\'' && !in_double_quotes)
		{
			in_single_quotes = !in_single_quotes;
			i++;
		}
		if (data->cmd[i] == '$' && (in_double_quotes || !in_single_quotes))
		{
			k = 0;
			i++;
			while (ft_isalnum(data->cmd[i]) || data->cmd[i] == '_')
				var[k++] = data->cmd[i++];
			var[k] = '\0';
			value = ft_get_env_value(env, var);
			if (value)
				while (*value)
					buffer[j++] = *value++;
		}
		else
			buffer[j++] = data->cmd[i++];
	}
	buffer[j] = '\0';
	data->echo_parse = ft_strdup(buffer);
}

/*static void	ft_parse_echo(t_data *data, t_env *env)
{
	*//*
	 *	parcourir l input
	 *	si char == "	=> on inverse un bool_dq
	 *					=> si bool_dq TRUE	=> on change Key => Value 
	 *										=> on affiche les '
	 *					=> si bool_dq FALSE => on affiche le texte tel quel sans "
	 *					=> bq jamais afficher sauf entre sq
	 *	si char == '	=> on inverse un bool_sq seulement si bool_dq est FALSE
	 *					=> si bool_dq TRUE	=> on change Key => Value 
	 *										=> on affiche les '
	 *					=> si bool_dq FALSE => on affiche le texte tel quel
	 *					=> sq seulement afficher si dq
	 *	si char == $ 	=> si bool_dq TRUE	=> on retire le $n
	 *					=> si nb_dq == 0	=> on retire le $n
	 *					=> si cha&& r + 1	=> is num => on retire le $n
	 *									=> is alpha	=> on recupere la key
	 *					=> si char + 1 == _	=> on affiche la var $_ = resultat de la derniere commande
	 *	si char = * 	=> on liste le nom des fichiers et dossier 
	 *					=> on les affiche les un apres les autres
	 *	si char = 0 et bool_dq = TRUE => print message error
	 *	si char = 0 et bool_sq = TRUE => print message error
	 */
	
	/*char	*in;
	char	out[4096];
	int		is_dq;	// bool double quote
	int		nb_dq;	// number of "
	int		is_sq;	// bool simple quote
	int		i_in;	// index input
	int		i_out;	// index output

	is_dq = 0;
	is_sq = 0;
}*/

void	ft_parse(t_data *data, t_env *env, char *input)
{
	data->cmd = ft_strdup(input);
	ft_parse_echo(data, env);
}