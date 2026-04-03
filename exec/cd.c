/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhurry <jjhurry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 12:27:13 by jjhurry           #+#    #+#             */
/*   Updated: 2026/04/03 16:02:38 by jjhurry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include <errno.h>

int ft_set_pwd_oldpwd(t_data *data)
{
	int		i;
	char	*old_pwd;
	char 	*curr_pwd;

	i = 0;
	while (data->envp[i] != NULL)
	{
		if ((ft_strncmp(data->envp[i], "PWD", 3) == 0 && data->envp[i][3] == '='))
		{
			old_pwd = ft_strdup(ft_getenv(data, "PWD"));
			curr_pwd = getcwd(NULL, 0);
			if (old_pwd == NULL || curr_pwd == NULL)
				return (-1);
			if (ft_change_env_key_value("OLDPWD", old_pwd, data) < 0)
				return (-2);
			ft_change_env_key_value("PWD", curr_pwd, data);
			free(old_pwd);
			free(curr_pwd);
			return (2);
		}
		i++;
	}
	return (1);
}

int ft_cd_no_arguments(t_data *data, char *curr_dir)
{
	char *home;
	
	home = ft_getenv(data, "HOME");
	if (home == NULL)
	{
		printf ("Minishell: cd: HOME not set\n");
		return (1);
	}
	if (chdir(home) == -1)
		return (printf("minishell: %s\n", strerror(errno)), -1);
	else	
		ft_set_pwd_oldpwd(data);
	return (1);
}

void ft_cd_helper(t_token **curr)
{
	int	count;

	count = 0;
	while (*curr != NULL)
	{
		if ((*curr)->type == WORD)
			count++;
		if (count == 2)
			break;
		*curr = (*curr)->next;
	}
}

void ft_cd_one_argument(t_token *head, int words, t_data *data, char *curr_dir)
{
	t_token	*curr;
	char	*path;
	char	*home;
	
	curr = head;
	ft_cd_helper(&curr);
	path = curr->value;
	if (ft_strncmp(curr->value, "~", 1) == 0)
	{
		// printf("~ detected\n");
		home = ft_getenv(data, "HOME");
		// printf("%s\n", home);
		if (curr->value[1] != '\0')
			path = ft_strjoin(home, curr->value + 1);
		else
			path = ft_strdup(home);
		if (path  == NULL)
			return;
		if (chdir(path) == -1)
			printf("minishell: %s", strerror(errno));

	}
	// printf("%s", curr->value);
	else 
		if (chdir(path) == -1)
			printf("minishell: %s", strerror(errno));
		else
			ft_set_pwd_oldpwd(data);
	free(path);
}
