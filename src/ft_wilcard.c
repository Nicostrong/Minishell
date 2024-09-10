/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wilcard.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 10:51:48 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/09/06 11:28:47 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

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

void	ft_wilcard(char *input)
{
	char			*path_directory;
	char			**a_file;
	struct dirent	*directory_entry;
	DIR				*directory;
	int				i_array;

	if (!input)
		return ;
	path_directory = getcwd(NULL, 0);
	if (!path_directory)
	{
		perror("getcwd");
		return ;
	}
	directory = opendir(path_directory);
	if (!directory)
	{
		perror("opendir");
		free(path_directory);
		return ;
	}
	a_file = (char **)ft_calloc(4096, sizeof(char *));
	if (!a_file)
	{
		closedir(directory);
		free(path_directory);
		perror("malloc");
		return ;
	}
	i_array = -1;
	while ((directory_entry = readdir(directory)) != NULL)
	{
		if (!input[1])
			a_file[++i_array] = ft_strdup(directory_entry->d_name);
		else if (ft_match_wildcard(input, directory_entry->d_name))
			a_file[++i_array] = ft_strdup(directory_entry->d_name);
		else
			continue ;
	}
	a_file[++i_array] = NULL;
	closedir(directory);
	free(path_directory);
	ft_putstrarray(a_file);
}