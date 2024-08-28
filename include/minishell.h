/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 15:46:06 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/08/28 12:17:11 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/*
 *	Define
 */

# define BLUE	"\033[1;94m"
# define WHITE	"\033[0m"
# define TERM_NAME	BLUE"minishell"WHITE

/*
 *	Standart library
 */

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <termios.h>
# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>

/*
 *	Personal Library
 */

# include "../libft/libft.h"

/*
 *	Structure
 */

typedef struct s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
}	t_env;

typedef struct s_data
{
	char	*cmd;
	int		code_child;
}	t_data;

//typedef struct s_command t_cmd;

typedef struct s_cmd
{
	char			**args;			// Tableau d'arguments (la commande et ses arguments)
	char			*input_file;	// Fichier d'entrée pour la redirection (NULL si non utilisé)
	char			*output_file;	// Fichier de sortie pour la redirection (NULL si non utilisé)
	int				append_output;	// 1 si on utilise '>>', 0 pour '>'
	int				is_piped;		// 1 si la commande est en pipeline, 0 sinon
	struct s_cmd	*next;			// Commande suivante dans le pipeline
	int				is_and;			// 1 si la commande est suivie par &&
	int				is_or;			// 1 si la commande est suivie par ||
	int				is_subshell;	// 1 si la commande est une sous-shell (parenthèses)
	int				is_dir;			// 1 si c est un dossier
	int				is_file;		// 1 si c est un fichier
}	t_cmd;

/*
 *	Buildin
 */

	/*
	 *	echo
	 */

int			ft_echo(t_data *data, t_env *env);

	/*
	 *	env
	 */

int			ft_env(t_env **env);

char		*ft_get_env_value(t_env *env, const char *name);

void		ft_free_env(t_env *env);
void		ft_update_shlvl(t_env **env);
void		ft_init_env(t_env **env, char **envp);
void		ft_set_env_value(t_env **env, char *name, char *value);

t_env		*ft_add_node(t_env *env, char *key, char *value);

	/*
	 *	exit
	 */

int			ft_exit(t_data *data, t_env **env);

	/*
	 *	export
	 */

int			ft_export(t_data *data, t_env *env);

	/*
	 *	cd
	 */

int			ft_cd(t_data *data, t_env *env);

	/*
	 *	pwd
	 */

int			ft_pwd(t_env *env);

	/*
	 *	unset
	 */

int			ft_unset(t_data *data, t_env **env);

/*
 *	Global
 */

void		ft_builtin(t_data *data, t_env **env);
void		handle_signal(int sign);

#endif