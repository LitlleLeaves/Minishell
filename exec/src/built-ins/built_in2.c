/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhurry <jjhurry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 15:29:24 by jjhurry           #+#    #+#             */
/*   Updated: 2026/04/07 17:40:16 by jjhurry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

void ft_builtin_env(t_data *data, char **arguments)
{
	int	i;

	if (arguments[1] != NULL)
	{
		printf("wrong amount of argments for env\n");
		data->exit_code = 1	;
	}
	else
	{
		i = 0;
		while (data->envp[i] != NULL)
		{
			printf("%s\n", data->envp[i]);
			i++;
		}
	}
	ft_free_tokens(data->head);
	free(data->envp);
	ft_free_arr((void **)arguments);
	free(data->pids);
	exit(data->exit_code);
}

void ft_builtin_pwd(t_data *data, char **arguments)
{
	char	*buff;
	char	*pwd;
	
	pwd = ft_getenv(data, "PWD");
    if (pwd != NULL)
    {
        printf("%s\n", pwd);
    }
	else
	{
		buff = getcwd(NULL, 0);
		if (buff == NULL)
			return (free(arguments), exit(1));
		printf("%s\n", buff);
		free(buff);
	}
	ft_free_tokens(data->head);
	free(data->envp);
	ft_free_arr((void **)arguments);
	free(data->pids);
	exit(0);
}
