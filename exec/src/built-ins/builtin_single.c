/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_single.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhurry <jjhurry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 14:28:04 by jjhurry           #+#    #+#             */
/*   Updated: 2026/04/07 16:46:00 by jjhurry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include <errno.h>
#include <limits.h>

void ft_builtin_single_cd(int words, char **arguments, t_data *data)
{
	// char cwd[4096]; // debug
	char *curr_dir;

	curr_dir = ft_getenv(data, "PWD");
	// printf("%s\n", ft_getenv(data, "PWD")); // debug
	if (words > 2)
	{
		printf("minishell: cd: too many arguments\n");
		data->exit_code = 1;
	}
	else if (words == 1)
		data->exit_code = ft_cd_no_arguments(data);
	else if (words == 2)
		data->exit_code = ft_cd_one_argument(arguments, data);
	// printf("%s\n", getcwd(cwd, sizeof(cwd))); // debug
	// printf("builtin single cd\n");
}

void ft_builtin_single_export(char **arguments, t_data *data)
{
	if (arguments[1] == NULL)
		ft_export_print_list(data);
	else
		ft_add_to_export_list(arguments, data);
}

void ft_builtin_single_unset(char **arguments, t_data *data)
{
		if (arguments[1] == NULL)
			return ;
		else
			ft_unset(arguments, data);
}

void ft_builtin_single_echo(char **arguments, t_data *data)
{
	if (arguments[1] == NULL)
		data->exit_code = ft_echo_no_arguments();
	else if (ft_check_echo_option(arguments) == 2)
		data->exit_code = ft_echo_no_newline(arguments, 2);
	else
		data->exit_code = ft_echo_newline(arguments, 1);
}

void ft_builtin_single_exit(int words, char **arguments, t_data *data)
{
	data->shutdown = 1;	
	if (words == 1)
	{
		data->exit_code = 0;
	}
		
	else if (words == 3)
	{
		printf("Minishell: exit: too many arguments\n");
		data->exit_code = 1;
	}
	else
	{
		data->exit_code = ft_atol(arguments[1]);
		if (data->exit_code == -1)
		{
			data->exit_code = 2;
			printf("Minishell: exit: %s numeric argument required\n", arguments[1]);
		}
	}
}

