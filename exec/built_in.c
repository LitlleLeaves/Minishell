/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhurry <jjhurry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 15:29:13 by jjhurry           #+#    #+#             */
/*   Updated: 2026/03/19 15:29:39 by jjhurry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

void ft_builtin_cd(t_exec_info *exec_info, t_data *data, char **arguments)
{

	fprintf(stderr, "builtin cd\n");
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
