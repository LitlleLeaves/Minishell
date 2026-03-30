/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_builtin_execution.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhurry <jjhurry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 13:07:12 by jjhurry           #+#    #+#             */
/*   Updated: 2026/03/30 12:14:28 by jjhurry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int ft_count_single_words(t_token *head)
{
	t_token	*curr;
	int		words;

	curr = head;
	words = 0;
	while (curr != NULL)
	{
		if (curr->type == WORD)
			words++;
		curr = curr->next;
	}
	return (words);
}

int ft_check_single_builtin(char *str, t_token *head)
{
	if (ft_strncmp(str, "cd", 2) == 0)
		return(ft_builtin_single_cd(head), 1);
	else if (ft_strncmp(str, "echo", 4) == 0)
		return(ft_builtin_single_echo(head), 2);
	else if (ft_strncmp(str, "pwd", 3) == 0)
		return(ft_builtin_single_pwd(head), 3);
	else if (ft_strncmp(str, "export", 6) == 0)
		return(ft_builtin_single_export(head), 4);
	else if (ft_strncmp(str, "unset", 5) == 0)
		return(ft_builtin_single_unset(head), 5);
	else if (ft_strncmp(str, "env", 3) == 0)
		return(ft_builtin_single_env(head), 6);
	else if (ft_strncmp(str, "exit", 4) == 0)
		return(ft_builtin_single_exit(head), 7);
	else
		return (0);
}

int ft_check_builtins_before_fork(t_token *head)
{
	t_token *curr;
	
	curr = head;
	while (curr->type != WORD)
		curr = curr->next;
	return (ft_check_single_builtin(curr->value, head));
}
