/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 15:46:06 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/09/13 08:52:42 by phkevin          ###   Luxembour.lu      */
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
 *	Externe variable
 */

extern char	**environ;

/*
 *	Global variable
 */

extern int	g_status;

/*
 *	Standart library
 */

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <termios.h>
# include <signal.h>
# include <dirent.h>
# include <sys/ioctl.h>
# include <sys/wait.h>
# include <readline/readline.h>
# include <readline/history.h>

/*
 *	Personal Library
 */

# include "../libft/libft.h"

/*
 *	Enum
 */

typedef enum
{
	T_WORD,				//	word			=>	to print
	T_BUILTIN,			//	builtin			=>	echo , cd, env, export, unset, exit
	T_CMD,				//	cmd				=>	exc
	T_OPT,				//	option			=>	-alpha
	T_PIPE,				//	pipe			=>	|
	T_OR,				//	or logical		=>	||
	T_AND,				//	and logical		=>	&&
	T_F_IN,				//	file in			=>	<
	T_HEREDOC,			//	heredoc mod		=>	<<
	T_EOF,				//	limiter			=>	word
	T_F_OUT,			//	file out		=>	>
	T_F_OUT_APPEND,		//	file out append	=>	>>
	T_FILENAME,			//	file name		=>	word
	T_SUBSHELL,			//	subshell		=>	( ou )
	T_DQUOTE,			//	double quote	=>	"
	T_SQUOTE,			//	simple quote	=>	'
	T_VAR,				//	env var			=>	$
	T_KEY,				//	env key			=>	PWD
	T_WILDCARD,			//	wildcard		=>	*
	T_END				//	end of cmd
}	e_token;

/*
 *	Structure
 */

typedef struct s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
}	t_env;

typedef struct s_token
{
	e_token			type;
	char			*value;
	struct s_token	*next;
}	t_token;

typedef struct s_tree
{
	e_token			type;		//	type de l operation
	char			*cmd;		//	nom de la commande
	struct s_tree	*left;		//	sous expression gauche
	struct s_tree	*right;		//	sous expression droite
	struct s_tree	*next;		//	next commande (voir pour le noeud parent)
}	t_tree;

typedef struct s_pipex
{
	int		nb_cmd;
	int		fd_in;
	int		fd_out;
	int		here_doc;
	char	*limiter;
	char	*file_in;
	char	*file_out;
	char	**path_array;
	char	**cmd_opt_array;
	char	**cmd_array;
	char	**access_path;
}	t_pipex;

typedef struct s_minishell
{
	t_env	*l_env;		// Liste chaînée des variables d'environnement
	t_token	*l_token;	// Liste chaînée des tokens de commande
	t_tree	*tree;		// Racine de l'arbre AST pour les commandes
	t_pipex	*pipex;		// Informations pour l'exécution de Pipex
	int		code_exit;	// Code retour last process
}   t_shell;

typedef struct s_data
{
	char	*cmd;			// Commande entree par l utilisateur
	char	*var_parse;		// Commande dont toutes les $VAR sont remplace par leur valeur
	char	*export_parse;	// array de commande exporte avec les valeurs des $VAR existante
	char	*echo_parse;	// array de string a afficher avec les valeur de $VAR si entre \" ou sans \' et \"
	int		code_child;		// Code retour de la derniere commande
}	t_data;

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

int			ft_is_key(t_env *env, char *key);
int			ft_env(t_data *data, t_env **env);

char		*ft_get_env_value(t_env *env, char *key);

void		ft_update_shlvl(t_env **env);
void		ft_set_env_value(t_env **env, char *key, char *value);

t_env		*ft_init_env(void);
t_env		*ft_add_node(t_env *env, char *key, char *value);

	/*
	 *	exit
	 */

int			ft_exit(t_data *data, t_env **env);

	/*
	 *	export
	 */

int			ft_export(t_data *data, t_env *env);
int			ft_check_key(t_env *env, char *key);

char		*ft_get_key(char *key_value);
char		*ft_get_value(char *key_value);

void		ft_export_value(t_env **env, char *key_val);

	/*
	 *	cd
	 */

int			ft_cd(t_data *data, t_env **env);

	/*
	 *	pwd
	 */

int			ft_pwd(t_env *env);

	/*
	 *	unset
	 */

int			ft_unset(t_data *data, t_env **env);

/*
 *	Parser
 */

//char		**ft_parse_input(char *input);

char		*ft_get_token_name(e_token token);

t_token		*ft_parse_cmd(char *input);

t_tree		*ft_parse_token_to_tree(t_token **tokens);
t_tree		*ft_handle_var(t_token **cur, t_tree **parent_node);
t_tree		*ft_handle_pipe_or_and(t_token **cur, t_tree **head);
t_tree		*ft_handle_file(t_token **cur, t_tree **parent_node);
t_tree		*ft_handle_quote(t_token **cur, t_tree **parent_node);
t_tree		*ft_handle_option(t_token **cur, t_tree **parent_node);
t_tree		*ft_handle_cmd(t_token **cur, t_tree **head, t_tree **parent_node);
t_tree		*ft_handle_sub(t_token **cur, t_tree **head, t_tree **parent_node);
t_tree		*ft_parse_subshell(t_token **tokens);
t_tree		*ft_create_node_tree(e_token type, char *cmd);

//void		ft_free_all(t_shell *shell);
void		ft_print_tokens(t_token *tokens);	// pour debug
void		ft_print_tree(t_tree *node, int depth);		// pour debug

//void		ft_parse_cmd(t_data *data, t_env *env);
//void		ft_parse_echo(t_data *data, t_env *env);
void		ft_append_token(t_token **head, e_token type, char *value);

/*
 *	Global
 */

void		handle_signal(int sign);
void		ft_wilcard(char *input);
void		ft_print_error(char *cmd);
void		ft_builtin(t_data *data, t_env **env);

/*
 *	error
 */

void		ft_put_error_cmd(char *cmd, char *msg);
void		ft_put_error_arg(char *cmd, char *arg, char *msg);
void		ft_put_error_cmd_exit(char *cmd, char *msg, int e_code);
void		ft_put_error_arg_exit(char *cmd, char *arg, char *msg, int e_code);

/*
 *	free
 */

void		ft_free_env(t_env *env);
void		ft_free_tree(t_tree *tree);
void		ft_free_all(t_shell *shell);
void		ft_free_pipex(t_pipex *pipex);
void		ft_free_tokens(t_token *tokens);

#endif