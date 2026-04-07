/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhurry <jjhurry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 15:29:13 by jjhurry           #+#    #+#             */
/*   Updated: 2026/04/07 13:56:57 by jjhurry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

void ft_builtin_cd(t_exec_info *exec_info, t_data *data, char **arguments)
{

	char *curr_dir;

	curr_dir = ft_getenv(data, "PWD");
	if (exec_info->words > 2)
	{
		printf("minishell: cd: too many arguments\n");
		data->exit_code = 1;
	}
	else if (exec_info->words == 1)
		data->exit_code = ft_cd_no_arguments(data);
	else if (exec_info->words == 2)
		data->exit_code = ft_cd_one_argument(arguments, data);
}

void ft_builtin_export(t_exec_info *exec_info, t_data *data, char **arguments)
{

	printf("builtin export\n");
}

void ft_builtin_unset(t_exec_info *exec_info, t_data *data, char **arguments)
{
	
	printf("builtin unset\n");
}

void ft_builtin_echo(t_exec_info *exec_info, t_data *data, char **arguments)
{
	
	printf("builtin echo\n");
}

void ft_builtin_exit(t_exec_info *exec_info, t_data *data, char **arguments)
{
	
	printf("builtin exit\n");
}
