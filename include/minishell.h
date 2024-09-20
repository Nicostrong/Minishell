/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 15:46:06 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/09/20 11:01:27 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/*
 *	Define
 */

# define BLUE	"\033[1;94m"
# define RED	"\033[1;91m"
# define WHITE	"\033[0m"
# define TERM_NAME	BLUE"mini$"RED"[🔥🔥🔥HELL🔥🔥🔥]$ "WHITE

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
	T_WORD,				//	word			=	0	=>	to print
	T_BUILTIN,			//	builtin			=	1	=>	echo , cd, env, export, unset, exit
	T_CMD,				//	cmd				=	2	=>	exc
	T_OPT,				//	option			=	3	=>	-alpha
	T_PIPE,				//	pipe			=	4	=>	|
	T_OR,				//	or logical		=	5	=>	||
	T_AND,				//	and logical		=	6	=>	&&
	T_F_IN,				//	file in			=	7	=>	<
	T_F_OUT,			//	file out		=	8	=>	>
	T_F_OUT_APPEND,		//	file out append	=	9	=>	>>
	T_HEREDOC,			//	heredoc mod		=	10	=>	<<
	T_EOF,				//	limiter			=	11	=>	word
	T_FILENAME,			//	file name		=	12	=>	word
	T_SUBSHELL,			//	subshell		=	13	=>	( ou )
	T_DQUOTE,			//	double quote	=	14	=>	"
	T_SQUOTE,			//	simple quote	=	15	=>	'
	T_VAR,				//	env var			=	16	=>	$
	T_KEY,				//	env key			=	17	=>	PWD
	T_WILDCARD,			//	wildcard		=	18	=>	*
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
	struct s_tree	*next;		//	suite de la commande
}	t_tree;

typedef struct s_pipex
{
	int		fd_in;				//	fd du file in
	int		fd_out;				//	fd du file out
	int		append;				//	bool si mode append (>>)
	int		here_doc;			//	bool si mode here_doc (<<)
	int		builtin;			//	bool si builtin fonction
	char	*limiter;			//	mot du limiter EOF
	char	*file_in;			//	nom du fichier in
	char	*file_out;			//	nom du fichier out
	char	*path_cmd;			//	path de la commande evecve->arg[0]
	char	**a_path;			//	array avec tout les path pour trouver les executables
	char	**a_cmd_opt;		//	array pour execve->arg[1]
	char	**a_env;			//	array pour execve->arg[2]
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

char		*ft_get_token_name(e_token token);

void		ft_free_all(t_shell *shell);
void		ft_print_tokens(t_token *tokens);	// pour debug
void		ft_print_tree(t_tree *node, int depth);		// pour debug
void		ft_append_token(t_token **head, e_token type, char *value);

t_tree		*ft_parse_heredoc(t_token **tokens);
t_tree		*ft_parse_subshell(t_token **tokens);
t_tree		*ft_parse_token_to_tree(t_token **tokens);
t_tree		*ft_create_node_tree(e_token type, char *cmd);
t_tree		*ft_handle_var(t_token **cur, t_tree **parent_node);
t_tree		*ft_handle_pipe_or_and(t_token **cur, t_tree **head);
t_tree		*ft_handle_file(t_token **cur, t_tree **parent_node);
t_tree		*ft_handle_quote(t_token **cur, t_tree **parent_node);
t_tree		*ft_handle_option(t_token **cur, t_tree **parent_node);
t_tree		*ft_handle_cmd(t_token **cur, t_tree **head, t_tree **parent_node);
t_tree		*ft_handle_sub(t_token **cur, t_tree **head, t_tree **parent_node);

t_token		*ft_parse_cmd(char *input);

/*
 *	pipex
 */

int			ft_count_cmd(t_tree *node);

char		*ft_concat_path_cmd(t_pipex *pipex, char *cmd);

char		**ft_get_path(char **env);
char		**ft_create_env_array(t_env *env);

void		ft_fill_pipex(t_shell *shell);
void		ft_print_pipex(t_pipex *pipex);
void		ft_get_fd_in_out(t_pipex **pipex, int *fd);

/*
 *	global
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