/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executable.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhurry <jjhurry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 14:56:47 by jjhurry           #+#    #+#             */
/*   Updated: 2026/03/12 15:10:35 by jjhurry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include "exec.h"

void ft_relative_executable_help(char *command)
{
	if (access(command, X_OK) == -1)
	{
		if (errno == EACCES)
		{
			printf("minishell: %s: Permission denied\n", command);
			exit(126);
		}
		else
		{
			perror(command);
			exit(126);
		}
	}
}
//check whether the relative path exsists and if the file is executable
char *ft_relative_executable(char *command)
{
	struct stat st;
	
	if (stat(command, &st) == -1)
	{
		if (errno == ENOENT)
		{
			printf("minishell: %s: No such file or directory\n", command);
			exit(127);
		}
		else
		{
			perror(command);
			exit(126);
		}
	}
	if (S_ISDIR(st.st_mode))
	{
		printf("minishell: %s: Is a directory\n", command);
		exit(126);
	}
	ft_relative_executable_help(command);
	return (strdup(command));
}

//make a executable by looking through the path and finding if it is executable
char *ft_make_executable(char *executable, char **envp)
{
	int		i;
	char	**paths;
	char	*exec;
	char	*path;

	i = 0;
	while (ft_strncmp(envp[i], "PATH=", 5))
		i++;
	paths = ft_split(envp[i] + 5, ':');
	if (paths == NULL)
		return (NULL);
	i = 0;
	while (paths[i])
	{
		path = ft_strjoin(paths[i], "/");
		if (path == NULL)
			return (ft_free_arr((void **)paths), NULL);
		exec = ft_strjoin(path, executable);
		if (exec == NULL)
			return (ft_free_arr((void **)paths), free(path), NULL);
	if (access(exec, F_OK) == 0)
		return (free(path), ft_free_arr((void **)paths), exec);
	}
	printf("%s: command not found", executable);
	return (free(exec), free(path), ft_free_arr((void **)paths), NULL);
}
