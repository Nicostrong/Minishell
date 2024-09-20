/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 10:14:14 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/09/20 11:10:00 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/*
 * <cat>minishell</cat>
 *
 * <summary>
 * 	void	ft_get_fd_in_out(t_pipex **pipex, int *fd)
 * </summary>
 *
 * <description>
 * 	ft_get_fd_in_out open the source file and the destination file and save each
 * 	 file descriptor on the struct.
 * </description>
 *
 * <param type="t_pipex **" name="pipex">structure pipex</param>
 * <param type="int *" name="fd">pointer to fd variable (fd[2])</param>
 *
 * <return>
 * 	void but set the structure with the file descriptor.
 * </return>
 *
 */

void	ft_get_fd_in_out(t_pipex **pipex, int *fd)
{
	int	fd_out;

	if ((*pipex)->here_doc == 1)
	{
		//ft_run_here_doc(pipex, fd);
		(*pipex)->fd_in = fd[0];
	}
	else
		(*pipex)->fd_in = open((*pipex)->file_in, O_RDONLY);
	if ((*pipex)->append)
		fd_out = open((*pipex)->file_out, O_WRONLY | O_CREAT | O_APPEND, 0644);
	else
		fd_out = open((*pipex)->file_out, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	(*pipex)->fd_out = fd_out;
}

/*
 * <cat>minishell</cat>
 *
 * <summary>
 * 	char	**ft_get_path(char **env)
 * </summary>
 *
 * <description>
 * 	ft_get_path read all env variables in env (is define in header file like 
 * 	extern char **environ) catch the $PATH variable and split the path in an 
 * 	array of path.
	lst = ft_init_list(argc, argv);
 * </description>
 *
 * <param type="char **" name="env">list of all env variables</param>
 *
 * <return>
 * 	an array with all path in the var $PATH.
 * </return>
 *
 */

char	**ft_get_path(char **env)
{
	char	**path_array;
	char	*path;
	int		index;

	index = 0;
	while (env[index] && ft_strncmp(env[index], "PATH=", 5))
		index++;
	if (!env[index])
		return (NULL);
	path = env[index] + 5;
	path_array = ft_split(path, ':');
	return (path_array);
}

///////////////////////////////////////////////////////////////////////////////
//		DEBUG	DEBUG	DEBUG	DEBUG	DEBUG	DEBUG	DEBUG	DEBUG	DEBUG
///////////////////////////////////////////////////////////////////////////////

void	ft_print_pipex(t_pipex *pipex)
{
	printf("PIPEX STRUCURE :\n");
	printf("fd_in = %d\n", pipex->fd_in);
	printf("fd_out = %d\n", pipex->fd_in);
	printf("bool append = %s\n", pipex->append ? "TRUE" : "FALSE");
	printf("bool here_doc = %s\n", pipex->here_doc ? "TRUE" : "FALSE");
	printf("bool builtin = %s\n", pipex->builtin ? "TRUE" : "FALSE");
	printf("Limiter = %s\n", pipex->limiter);
	printf("file_in = %s\n", pipex->file_in);
	printf("file_out = %s\n", pipex->file_out);
	printf("path_cmd = %s\n", pipex->path_cmd);
	printf("PATH ARRAY :\n");
	ft_putstrarray(pipex->a_path);
	printf("CMD OPT ARRAY :\n");
	ft_putstrarray(pipex->a_cmd_opt);
	printf("ENV ARRAY :\n");
	ft_putstrarray(pipex->a_env);
}