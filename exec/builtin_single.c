/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_single.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhurry <jjhurry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 14:28:04 by jjhurry           #+#    #+#             */
/*   Updated: 2026/03/30 17:49:13 by jjhurry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include <errno.h>

void ft_builtin_single_cd(t_token *head, int words, char **arguments)
{
	char cwd[4096]; // debug

	printf("%s\n", getenv("PWD")); // debug
	if (words > 2)
	{
		printf("minishell: cd: too many arguments\n");
		errno = 1;
	}
	else if (words == 1)
		ft_cd_no_arguments();
	else if (words == 2)
		ft_cd_one_argument(head, words);
	printf("%s\n", getcwd(cwd, sizeof(cwd))); // debug
	// printf("builtin single cd\n");
}

void ft_builtin_single_export(t_token *head, int words, char **arguments)
{
	if (arguments[1] == NULL)
		ft_export_print_list(); //TODO
	else
		ft_add_to_export_list(arguments); //TODO
}

void ft_builtin_single_unset(t_token *head, int words, char **arguments)
{
	(void)head;
	printf("builtin unset\n");
}

void ft_builtin_single_echo(t_token *head, int words, char **arguments)
{
	(void)head;
	printf("builtin echo\n");
}

void ft_builtin_single_exit(t_token *head, int words, char **arguments)
{
	(void)head;
	printf("builtin exit\n");
}

