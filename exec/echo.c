/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhurry <jjhurry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 14:04:24 by jjhurry           #+#    #+#             */
/*   Updated: 2026/04/03 16:01:16 by jjhurry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

void ft_echo_no_arguments()
{
	printf("\n");
}

int ft_check_echo_option(char **arguments)
{
	if (strncmp(arguments[1], "-n", 3) == 0)
		return (2);
	return (1);
}

void ft_echo_no_newline(char **arguments, int i)
{
	while (arguments[i] != NULL && arguments[i + 1] != NULL)
	{
		printf("%s ", arguments[i]);
		i++;
	}
	if (arguments[i] != NULL)
		printf("%s", arguments[i]);
}

void ft_echo_newline(char **arguments, int i)
{
	while (arguments[i] != NULL && arguments[i + 1] != NULL)
	{
		printf("%s ", arguments[i]);
		i++;
	}
	if (arguments[i] != NULL)
		printf("%s\n", arguments[i]);
	else
		printf("\n");
}