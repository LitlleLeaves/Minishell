/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_single2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhurry <jjhurry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 14:28:07 by jjhurry           #+#    #+#             */
/*   Updated: 2026/04/03 15:59:16 by jjhurry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

void ft_builtin_single_env(t_token *head, int words, char **arguments, t_data *data)
{
	int	i;

	if (arguments[1] != NULL)
		printf("wrong amount of argments for env\n");
	else
	{
		i = 0;
		while (data->envp[i] != NULL)
		{
			printf("%s\n", data->envp[i]);
			i++;
		}
	}	
}

int ft_builtin_single_pwd(t_token *head, int words, char **arguments, t_data *data)
{
	int		i;
	char	*buff;
	char	*pwd;
	
	pwd = ft_getenv(data, "PWD");
    if (pwd != NULL)
    {
        printf("%s\n", pwd);
        return (1);
    }
	else
	{
		buff = getcwd(NULL, 0);
		if (buff == NULL)
			return (-1);
		printf("%s\n", buff);
		free(buff);
		return (1);
	}
}
