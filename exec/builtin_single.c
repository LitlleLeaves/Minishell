/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   builtin_single.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jjhurry <jjhurry@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/03/19 14:28:04 by jjhurry       #+#    #+#                 */
/*   Updated: 2026/04/02 14:36:41 by jjhurry       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include <errno.h>

void ft_builtin_single_cd(t_token *head, int words, char **arguments, t_data *data)
{
	char cwd[4096]; // debug
	char *curr_dir;

	curr_dir = ft_getenv(data, "PWD");
	printf("%s\n", ft_getenv(data, "PWD")); // debug
	if (words > 2)
	{
		printf("minishell: cd: too many arguments\n");
		errno = 1;
	}
	else if (words == 1)
		ft_cd_no_arguments(data, curr_dir);
	else if (words == 2)
		ft_cd_one_argument(head, words, data, curr_dir);
	printf("%s\n", getcwd(cwd, sizeof(cwd))); // debug
	// printf("builtin single cd\n");
}

void ft_builtin_single_export(t_token *head, int words, char **arguments, t_data *data)
{
	// if (arguments[1] == NULL)
	// 	ft_export_print_list(); //TODO
	// else
	// 	ft_add_to_export_list(arguments); //TODO
}

void ft_builtin_single_unset(t_token *head, int words, char **arguments, t_data *data)
{
	(void)head;
	printf("builtin unset\n");
}

void ft_builtin_single_echo(t_token *head, int words, char **arguments, t_data *data)
{
	if (arguments[1] == NULL)
		ft_echo_no_arguments();
	else if (ft_check_echo_option(arguments) == 2)
		ft_echo_no_newline(arguments, 2);
		else
			ft_echo_newline(arguments, 1);
}

void ft_builtin_single_exit(t_token *head, int words, char **arguments, t_data *data)
{
	(void)head;
	printf("builtin exit\n");
}

