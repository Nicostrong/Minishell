/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_access.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 15:42:23 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/09/17 14:21:24 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/*
 * <cat>array</cat>
 *
 * <summary>
 * 	char	**ft_get_access(t_info *info)
 * </summary>
 *
 * <description>
 * 	ft_get_access create an array with an executable path for each cmd for the 
 * 	function execve.
 * </description>
 *
 * <param type="t_info *" name="info">structure info</param>
 *
 * <return>
 * 	an array of path with cmd can be executable.
 * </return>
 *
 */

char	**ft_get_access(t_pipex *pipex)
{
	char	**access_array;

	access_array = (char **)ft_calloc(2, sizeof(char *));
	if (!access_array)
		return (NULL);
	access_array[0] = ft_concat_path_cmd(pipex, access_array);
	access_array[1] = NULL;
	return (access_array);
}

/*
 * <cat>memory</cat>
 *
 * <summary>
 * 	char	*ft_free_access(char **path, char **access)
 * </summary>
 *
 * <description>
 * 	ft_free_access free all allocation memory of all array needed to create the 
 *  access array.
 * </description>
 *
 * <param type="char **" name="path">array of path</param>
 * <param type="char **" name="access">array of access excecutable path</param>
 *
 * <return>
 * 	NULL
 * </return>
 *
 */

char	*ft_free_access(char **path, char **access)
{
	if (path)
		free_array(&path);
	if (access)
		free_array(&access);
	return (NULL);
}

/*
 * <cat>array</cat>
 *
 * <summary>
 * 	char	**ft_concat_cmd_path(char **path, char *cmd)
 * </summary>
 *
 * <description>
 * 	ft_concat_cmd_path concat all path with a simple command.
 * </description>
 *
 * <param type="char **" name="path">aray of path</param>
 * <param type="char *" name="cmd">command to join with all path</param>
 *
 * <return>
 * 	an array of path with the command.
 * </return>
 *
 */

char	**ft_concat_cmd_path(char **path, char *cmd)
{
	char	**path_cmd_array;
	char	**tmp;
	char	*joined;
	int		index;
	int		nb_row;

	index = 0;
	nb_row = 0;
	tmp = path;
	while (*tmp++)
		nb_row++;
	path_cmd_array = (char **)ft_calloc((nb_row + 1), sizeof(char *));
	if (!path_cmd_array)
		return (NULL);
	while (*path)
	{
		joined = ft_strjoin(*path++, "/");
		path_cmd_array[index] = ft_strjoin(joined, cmd);
		free(joined);
		index++;
	}
	return (path_cmd_array);
}

/*
 * <cat>str</cat>
 *
 * <summary>
 * 	char	*ft_concat_path_cmd(t_info *info, int index, char **access_array)
 * </summary>
 *
 * <description>
 * 	ft_concat_path_cmd create an array with all path with one cmd. Test if each 
 * 	path if it can be excecutable, and retrun a pointer to the executable path 
 * 	for the commande evaluated.
 * </description>
 *
 * <param type="t_info *" name="info">structure info</param>
 * <param type="int" name="index">index of evaluated cmd</param>
 * <param type="char **" name="access_array">array of excecutable path</param>
 *
 * <return>
 * 	a pointer to an excecutable path with the cmd.
 * </return>
 *
 */

char	*ft_concat_path_cmd(t_pipex *pipex, char **access_array)
{
	char	**path_tmp;
	char	*exec_path;
	int		index;

	path_tmp = ft_concat_cmd_path(pipex->path_array, pipex->cmd_array[0]);
	if (!path_tmp)
		return (ft_free_access(NULL, access_array));
	index = 0;
	while (path_tmp[index] && access(path_tmp[index], X_OK) != 0)
		index++;
	if (path_tmp[index])
	{
		exec_path = ft_strdup(path_tmp[index]);
		if (!exec_path)
			return (ft_free_access(NULL, access_array));
	}
	else
		exec_path = ft_strdup(pipex->cmd_array[0]);
	free_array(&path_tmp);
	return (exec_path);
}