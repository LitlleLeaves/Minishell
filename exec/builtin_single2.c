/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_single2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhurry <jjhurry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 14:28:07 by jjhurry           #+#    #+#             */
/*   Updated: 2026/03/30 17:08:00 by jjhurry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

void ft_builtin_single_env(t_token *head, int words, char **arguments)
{
	(void)head;
	printf("builtin env\n");
}

void ft_builtin_single_pwd(t_token *head, int words, char **arguments)
{
	(void)head;
	printf("builtin pwd\n");
}
