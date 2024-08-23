/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 15:46:06 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/08/23 10:54:21 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/*
 *	Define
 */

# define BLUE	"\033[1;94m"
# define WHITE	"\033[0m"
# define TERM_NAME	BLUE"minishell"WHITE"$ "

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
	char			*value;
	struct s_env	*next;
} t_env;

typedef struct s_data
{
	char	*cmd;
	char	pwd[2048];
	char	*line;
	char	**env;
	char	**array_line;
	int		code_child;
} t_data;

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
} t_cmd;

/*
 *	Buildin
 */

/*
echo (with option -n only)
cd (with path)
pwd (no option)
export (no option)
unset (no option)
env (no option)
exit (no option)
*/

int			ft_exit(t_data *data);

void		ft_cd(t_data *data);
void		ft_env(t_data *data);
void		ft_echo(t_data *data);
void		ft_init_env(t_env *env, char **envp);

/*
 *	Global
 */

void		ft_builtin(t_data *data);
void		handle_signal(int sign);

#endif