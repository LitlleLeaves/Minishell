/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_builtin_execution.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhurry <jjhurry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 13:07:12 by jjhurry           #+#    #+#             */
/*   Updated: 2026/03/18 16:57:19 by jjhurry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int ft_check_single_builtin(char *str)
{
	if (strncmp(str, "cd", 2))
		return(1);
	else if (strncmp(str, "echo", 4))
		return(2);
	else if (strncmp(str, "pwd", 3))
		return(3);
	else if (strncmp(str, "export", 6))
		return(4);
	else if (strncmp(str, "unset", 5))
		return(5);
	else if (strncmp(str, "env", 3))
		return(6);
	else if (strncmp(str, "exit", 4))
		return(7);
	else
		return (0);
}

int ft_check_builtins_before_fork(t_token *head, t_data *data)
{
	t_token *curr;
	
	if (head == NULL || head->type != WORD)
		return (0);
	curr = head;
	while (curr->value != WORD)
		curr = curr->next;
	return (ft_check_single_builtin(curr->value));
}

void ft_single_builtin(t_token *head, t_data *data)
{
	//TODO
}