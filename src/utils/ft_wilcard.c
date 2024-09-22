/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wilcard.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 10:51:48 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/09/22 14:13:03 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	ft_match_wildcard(const char *pattern, const char *str)
{
	if (*pattern == '\0' && *str == '\0')
		return (1);
	if (*pattern == '*')
	{
		while (*str != '\0')
		{
			if (ft_match_wildcard(pattern + 1, str))
				return (1);
			str++;
		}
		return (ft_match_wildcard(pattern + 1, str));
	}
	if (*pattern == *str || (*pattern == '?' && *str != '\0'))
		return (ft_match_wildcard(pattern + 1, str + 1));
	return (0);
}

static int	ft_getperror(char *p_dir, DIR *dir, char **a_file)
{
	p_dir = getcwd(NULL, 0);
	if (!p_dir)
	{
		perror("getcwd");
		return (1);
	}
	dir = opendir(p_dir);
	if (!dir)
	{
		perror("opendir");
		free(p_dir);
		return (1);
	}
	a_file = (char **)ft_calloc(4096, sizeof(char *));
	if (!a_file)
	{
		closedir(dir);
		free(p_dir);
		perror("malloc");
		return (1);
	}
	return (0);
}

static char	**ft_setfile(char *input, DIR *directory, char **file)
{
	struct dirent	*dir_ent;
	int				i_array;

	i_array = -1;
	dir_ent = readdir(directory);
	while (dir_ent != NULL)
	{
		if (!input[1])
			file[++i_array] = ft_strdup(dir_ent->d_name);
		else if (ft_match_wildcard(input, dir_ent->d_name))
			file[++i_array] = ft_strdup(dir_ent->d_name);
		else
			continue ;
		dir_ent = readdir(directory);
	}
	file[++i_array] = NULL;
	return (file);
}

void	ft_wilcard(char *input)
{
	char			*path_directory;
	char			**a_file;
	DIR				*directory;

	if (!input)
		return ;
	path_directory = getcwd(NULL, 0);
	directory = opendir(path_directory);
	a_file = (char **)ft_calloc(4096, sizeof(char *));
	if (!ft_getperror(path_directory, directory, a_file))
		return ;
	a_file = ft_setfile(input, directory, a_file);
	closedir(directory);
	free(path_directory);
	ft_putstrarray(a_file);
}
