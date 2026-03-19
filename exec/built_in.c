/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhurry <jjhurry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 15:29:13 by jjhurry           #+#    #+#             */
/*   Updated: 2026/03/19 14:30:49 by jjhurry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

void ft_builtin_cd(t_exec_info *exec_info, t_data *data, char **arguments, char *executable)
{
	(void)exec_info;
	(void)data;
	(void)arguments;
	(void)executable;
	printf("builtin cd\n");
}

void ft_builtin_export(t_exec_info *exec_info, t_data *data, char **arguments, char *executable)
{
	(void)exec_info;
	(void)data;
	(void)arguments;
	(void)executable;
	printf("builtin export\n");
}

void ft_builtin_unset(t_exec_info *exec_info, t_data *data, char **arguments, char *executable)
{
	(void)exec_info;
	(void)data;
	(void)arguments;
	(void)executable;
	printf("builtin unset\n");
}

void ft_builtin_echo(t_exec_info *exec_info, t_data *data, char **arguments, char *executable)
{
	(void)exec_info;
	(void)data;
	(void)arguments;
	(void)executable;
	printf("builtin echo\n");
}

void ft_builtin_exit(t_exec_info *exec_info, t_data *data, char **arguments, char *executable)
{
	(void)exec_info;
	(void)data;
	(void)arguments;
	(void)executable;
	printf("builtin exit\n");
}
