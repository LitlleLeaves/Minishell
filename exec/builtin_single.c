/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_single.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhurry <jjhurry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 14:28:04 by jjhurry           #+#    #+#             */
/*   Updated: 2026/03/19 14:47:28 by jjhurry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

void ft_builtin_single_cd(t_token *head)
{
	// (void)head;
	printf("builtin cd\n");
}

void ft_builtin_single_export(t_token *head)
{
	(void)head;
	printf("builtin export\n");
}

void ft_builtin_single_unset(t_token *head)
{
	(void)head;
	printf("builtin unset\n");
}

void ft_builtin_single_echo(t_token *head)
{
	(void)head;
	printf("builtin echo\n");
}

void ft_builtin_single_exit(t_token *head)
{
	(void)head;
	printf("builtin exit\n");
}

