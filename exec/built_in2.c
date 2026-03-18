/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhurry <jjhurry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 15:29:24 by jjhurry           #+#    #+#             */
/*   Updated: 2026/03/17 15:30:42 by jjhurry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

void ft_builtin_env(t_exec_info *exec_info, t_data *data, char **arguments, char *executable)
{
	(void)exec_info;
	(void)data;
	(void)arguments;
	(void)executable;
	printf("builtin env\n");
}

void ft_builtin_pwd(t_exec_info *exec_info, t_data *data, char **arguments, char *executable)
{
	(void)exec_info;
	(void)data;
	(void)arguments;
	(void)executable;
	printf("builtin pwd\n");
}
