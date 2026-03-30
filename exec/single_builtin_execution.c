/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_builtin_execution.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhurry <jjhurry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 13:07:12 by jjhurry           #+#    #+#             */
/*   Updated: 2026/03/30 17:09:53 by jjhurry          ###   ########.fr       */
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

int ft_check_single_builtin(t_token *head, int words, char **arguments)
{
	if (ft_strncmp(arguments[0], "cd", 2) == 0)
		return(ft_builtin_single_cd(head, words, arguments), 1);
	else if (ft_strncmp(arguments[0], "echo", 4) == 0)
		return(ft_builtin_single_echo(head, words, arguments), 2);
	else if (ft_strncmp(arguments[0], "pwd", 3) == 0)
		return(ft_builtin_single_pwd(head, words, arguments), 3);
	else if (ft_strncmp(arguments[0], "export", 6) == 0)
		return(ft_builtin_single_export(head, words, arguments), 4);
	else if (ft_strncmp(arguments[0], "unset", 5) == 0)
		return(ft_builtin_single_unset(head, words, arguments), 5);
	else if (ft_strncmp(arguments[0], "env", 3) == 0)
		return(ft_builtin_single_env(head, words, arguments), 6);
	else if (ft_strncmp(arguments[0], "exit", 4) == 0)
		return(ft_builtin_single_exit(head, words, arguments), 7);
	else
		return (0);
}

int ft_single_argument_list(t_token *curr, int words, char **arguments)
{
	int	counter;

	counter = 0;
	while (counter < words || curr != NULL)
	{
		if (curr->type == WORD)
		{
			arguments[counter] = ft_strdup(curr->value);
			if (arguments[counter] == NULL)
				return (ft_free_r((void **)arguments, counter), -1);
			counter++;
		}
		curr = curr->next;
	}
	return (1);
}

int ft_check_builtins_before_fork(t_token *head)
{
	t_token *curr;
	int		fd_in;
	int		fd_out;
	int		words;
	char **arguments;
	
	curr = head;
	words = ft_count_single_words(curr);
	fd_in = -2;
	fd_out = -2;
	ft_apply_redirection(&fd_in, &fd_out, curr);
	arguments = ft_calloc(words + 1, sizeof(char *));
	if (arguments == NULL)
		return (-1);
	ft_single_argument_list(curr , words, arguments);
	while (curr->type != WORD)
		curr = curr->next;
	return (ft_check_single_builtin(head, words, arguments), 1);
}
